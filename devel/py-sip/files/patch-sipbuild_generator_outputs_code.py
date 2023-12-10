Fix several regressions in the new code generator that was re-written in
Python.

Includes upstream fixes:
https://www.riverbankcomputing.com/hg/sip/rev/67e0294b505c
https://www.riverbankcomputing.com/hg/sip/rev/4b98e8e43a1e
https://www.riverbankcomputing.com/hg/sip/rev/0d6692e9c295
https://www.riverbankcomputing.com/hg/sip/rev/10b05deedee7
https://www.riverbankcomputing.com/hg/sip/rev/2d6fa85ae3de
https://www.riverbankcomputing.com/hg/sip/rev/fc6f81078cc4

plus a missed space in a function declaration (first hunk).

--- sipbuild/generator/outputs/code.py.orig	2023-11-30 12:14:32 UTC
+++ sipbuild/generator/outputs/code.py
@@ -521,7 +521,7 @@ f'''
             sf.write(
 f'''
 
-void sipVEH_{module_name}_{virtual_error_handler.name}(sipSimpleWrapper *{self_name}, sip_gilstate_t{state_name})
+void sipVEH_{module_name}_{virtual_error_handler.name}(sipSimpleWrapper *{self_name}, sip_gilstate_t {state_name})
 {{
 ''')
 
@@ -4251,7 +4251,7 @@ def _call_default_ctor(spec, ctor):
 
         # Do what we can to provide type information to the compiler.
         if arg.type is ArgumentType.CLASS and len(arg.derefs) > 0 and not arg.is_reference:
-            class_type = fmt_argument_as_cpp_type(spec, arg.definition)
+            class_type = fmt_argument_as_cpp_type(spec, arg)
             arg_s = f'static_cast<{class_type}>(0)'
         elif arg.type is ArgumentType.ENUM:
             enum_type = fmt_enum_as_cpp_type(arg.definition)
@@ -6177,7 +6177,7 @@ def _catch_block(sf, spec, exception, py_signature=Non
     # with older versions of SIP.
     exception_cpp_stripped = exception_fq_cpp_name.cpp_stripped(STRIP_GLOBAL)
 
-    sip_exception_ref = 'sipExceptionRef' if exception.class_exception is not None or _is_used_in_code(exception.raise_code) else ''
+    sip_exception_ref = 'sipExceptionRef' if exception.class_exception is not None or _is_used_in_code(exception.raise_code, 'sipExceptionRef') else ''
 
     sf.write(
 f'''            catch ({exception_cpp_stripped} &{sip_exception_ref})
@@ -7593,10 +7593,10 @@ def _arg_parser(sf, spec, scope, py_signature, ctor=No
             operator = '!='
             sip_value = 'sipValue'
 
-        parser_function = f'sipValue {operator} SIP_NULLPTR && sipParsePair('
+        parser_function = f'sipValue {operator} SIP_NULLPTR && sipParsePair'
         args.append('&sipParseErr')
         args.append('sipName')
-        args.append('sipValue')
+        args.append(sip_value)
 
     elif (overload is not None and overload.common.allow_keyword_args) or ctor is not None:
         # We handle keywords if we might have been passed some (because one of
@@ -8013,7 +8013,7 @@ def _delete_temporaries(sf, spec, py_signature):
             if spec.c_bindings or not arg.is_const:
                 sf.write(f'            sipFree({arg_name});\n')
             else:
-                sf.write(f'            sipFree(const_cast<wchar_t *>({arg_nr}));\n')
+                sf.write(f'            sipFree(const_cast<wchar_t *>({arg_name}));\n')
 
         else:
             convert_to_type_code = _get_convert_to_type_code(arg)
@@ -8408,7 +8408,7 @@ def _class_docstring(sf, spec, bindings, klass):
     else:
         is_first = True
 
-    if klass.docstring is None or klass.docstring.signature is not SocstringSignature.DISCARDED:
+    if klass.docstring is None or klass.docstring.signature is not DocstringSignature.DISCARDED:
         for ctor in klass.ctors:
             if ctor.access_specifier is AccessSpecifier.PRIVATE:
                 continue
