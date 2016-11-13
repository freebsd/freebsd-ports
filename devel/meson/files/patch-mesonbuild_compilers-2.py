From ac58c13bbfa6c7b47cc54f30e32bd405c944076d Mon Sep 17 00:00:00 2001
From: Nirbheek Chauhan <nirbheek@centricular.com>
Date: Tue, 25 Oct 2016 02:32:57 +0530
Subject: [PATCH] has_function: Only ignore prototype when no includes are
 specified

The Autoconf-style check we were doing gives false positives when the
linker uses the prototype defined in the SDK header to decide whether
a function is available or not.

For example, with macOS 10.12, clock_gettime is now implemented
(alongwith other functions). These functions are always defined in the
XCode 8 SDK as weak imports and you're supposed to do a runtime check to
see if the symbols are available and use fallback code if they aren't.

The linker will always successfully link if you use one of those symbols
(without a runtime fallback) even if you target an older OS X version
with -mmacosx-version-min. This is the intended behaviour by Apple.

But this makes has_function useless because to test if the symbol is
available, we must know at link-time whether it is available.

To force the linker to do the check at link-time you must use
'-Wl,-no_weak_imports` *and* use the prototype in time.h which has an
availability macro which tells the linker whether the symbol is
available or not based on the -mmacosx-version-min flag.

An autoconf-style check would override this prototype and use its own
which would result in the linker thinking that the function is always
available (a false positive). Worse, this would manifest at runtime and
might not be picked up immediately.

We now use the function prototype in the user-provided includes if the
'prefix' kwarg contains a `#include` and use the old Autoconf-style
check if not. I've tested that the configure checks done by GStreamer
and GLib are completely unaffected by this; at least on Linux.

The next commit will also add `-Wl,-no_weak_imports` to extra_args by
default so that Meson avoids this mess completely. We always want this
because the user would not do a has_function check if they have
a runtime fallback for the function in their code.
--- mesonbuild/compilers.py.orig	2016-11-09 17:25:49 UTC
+++ mesonbuild/compilers.py
@@ -891,55 +891,65 @@ int main(int argc, char **argv) {
             raise EnvironmentException('Could not determine alignment of %s. Sorry. You might want to file a bug.' % typename)
         return align
 
-    def has_function(self, funcname, prefix, env, extra_args=None, dependencies=None):
+    @staticmethod
+    def _no_prototype_templ():
         """
-        First, this function looks for the symbol in the default libraries
-        provided by the compiler (stdlib + a few others usually). If that
-        fails, it checks if any of the headers specified in the prefix provide
-        an implementation of the function, and if that fails, it checks if it's
-        implemented as a compiler-builtin.
+        Try to find the function without a prototype from a header by defining
+        our own dummy prototype and trying to link with the C library (and
+        whatever else the compiler links in by default). This is very similar
+        to the check performed by Autoconf for AC_CHECK_FUNCS.
         """
-        if extra_args is None:
-            extra_args = []
-        # Define the symbol to something else in case it is defined by the
-        # includes or defines listed by the user `{0}` or by the compiler.
-        # Then, undef the symbol to get rid of it completely.
-        templ = '''
+        # Define the symbol to something else since it is defined by the
+        # includes or defines listed by the user (prefix -> {0}) or by the
+        # compiler. Then, undef the symbol to get rid of it completely.
+        head = '''
         #define {1} meson_disable_define_of_{1}
         #include <limits.h>
         {0}
         #undef {1}
         '''
-
         # Override any GCC internal prototype and declare our own definition for
         # the symbol. Use char because that's unlikely to be an actual return
         # value for a function which ensures that we override the definition.
-        templ += '''
+        head += '''
         #ifdef __cplusplus
         extern "C"
         #endif
         char {1} ();
         '''
-
-        # glibc defines functions that are not available on Linux as stubs that
-        # fail with ENOSYS (such as e.g. lchmod). In this case we want to fail
-        # instead of detecting the stub as a valid symbol.
-        # We always include limits.h above to ensure that these are defined for
-        # stub functions.
-        stubs_fail = '''
-        #if defined __stub_{1} || defined __stub___{1}
-        fail fail fail this function is not going to work
-        #endif
-        '''
-        templ += stubs_fail
-
-        # And finally the actual function call
-        templ += '''
-        int
-        main ()
+        # The actual function call
+        main = '''
+        int main ()
         {{
           return {1} ();
         }}'''
+        return head, main
+
+    @staticmethod
+    def _have_prototype_templ():
+        """
+        Returns a head-er and main() call that uses the headers listed by the
+        user for the function prototype while checking if a function exists.
+        """
+        # Add the 'prefix', aka defines, includes, etc that the user provides
+        head = '#include <limits.h>\n{0}\n'
+        # We don't know what the function takes or returns, so just add
+        # a useless reference to it
+        main = '\nint main() {{ {1}; }}'
+        return head, main
+
+    def has_function(self, funcname, prefix, env, extra_args=None, dependencies=None):
+        """
+        First, this function looks for the symbol in the default libraries
+        provided by the compiler (stdlib + a few others usually). If that
+        fails, it checks if any of the headers specified in the prefix provide
+        an implementation of the function, and if that fails, it checks if it's
+        implemented as a compiler-builtin.
+        """
+        if extra_args is None:
+            extra_args = []
+
+        # Short-circuit if the check is already provided by the cross-info file
         varname = 'has function ' + funcname
         varname = varname.replace(' ', '_')
         if self.is_cross:
@@ -948,16 +958,35 @@ int main(int argc, char **argv) {
                 if isinstance(val, bool):
                     return val
                 raise EnvironmentException('Cross variable {0} is not a boolean.'.format(varname))
-        if self.links(templ.format(prefix, funcname), env, extra_args, dependencies):
-            return True
+
+        # glibc defines functions that are not available on Linux as stubs that
+        # fail with ENOSYS (such as e.g. lchmod). In this case we want to fail
+        # instead of detecting the stub as a valid symbol.
+        # We already included limits.h earlier to ensure that these are defined
+        # for stub functions.
+        stubs_fail = '''
+        #if defined __stub_{1} || defined __stub___{1}
+        fail fail fail this function is not going to work
+        #endif
+        '''
+
+        # If we have any includes in the prefix supplied by the user, assume
+        # that the user wants us to use the symbol prototype defined in those
+        # includes. If not, then try to do the Autoconf-style check with
+        # a dummy prototype definition of our own.
+        # This is needed when the linker determines symbol availability from an
+        # SDK based on the prototype in the header provided by the SDK.
+        # Ignoring this prototype would result in the symbol always being
+        # marked as available.
+        if '#include' in prefix:
+            head, main = self._have_prototype_templ()
+        else:
+            head, main = self._no_prototype_templ()
+        templ = head + stubs_fail + main
+
         # Add -O0 to ensure that the symbol isn't optimized away by the compiler
         args = extra_args + self.get_no_optimization_args()
-        # Sometimes the implementation is provided by the header, or the header
-        # redefines the symbol to be something else. In that case, we want to
-        # still detect the function. We still want to fail if __stub_foo or
-        # _stub_foo are defined, of course.
-        header_templ = '#include <limits.h>\n{0}\n' + stubs_fail + '\nint main() {{ {1}; }}'
-        if self.links(header_templ.format(prefix, funcname), env, args, dependencies):
+        if self.links(templ.format(prefix, funcname), env, extra_args, dependencies):
             return True
         # Some functions like alloca() are defined as compiler built-ins which
         # are inlined by the compiler, so test for that instead. Built-ins are
