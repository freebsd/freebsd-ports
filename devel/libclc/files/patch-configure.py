The LLVM_TOOL_LINK builds a helper tool named utils/prepare-builtins that
requires libedit which in turn pulls in libtinfo (part of libncurses).
In order to support builds on platforms without base ncurses (e.g. DF),
require base libedit.  This requires an additional -L LDFLAGS to search
${LOCALBASE}/lib for the needed libs.  (prepare-builtins is not installed)

--- configure.py.orig	2015-07-10 13:37:04 UTC
+++ configure.py
@@ -118,7 +118,8 @@ b.rule("OPT", command = llvm_opt + " -O3
        description = 'OPT $out')
 
 c_compiler_rule(b, "LLVM_TOOL_CXX", 'CXX', cxx_compiler, llvm_cxxflags)
-b.rule("LLVM_TOOL_LINK", cxx_compiler + " -o $out $in %s" % llvm_core_libs + " -Wl,-rpath %s" % llvm_libdir, 'LINK $out')
+b.rule("LLVM_TOOL_LINK", cxx_compiler + " -o $out $in %s" % llvm_core_libs + 
+  " -L" + prefix + "/lib -Wl,-rpath %s" % llvm_libdir, 'LINK $out')
 
 prepare_builtins = os.path.join('utils', 'prepare-builtins')
 b.build(os.path.join('utils', 'prepare-builtins.o'), "LLVM_TOOL_CXX",
@@ -264,7 +265,7 @@ install_cmd = ' && '.join(['mkdir -p ${D
                            {'src': file,
                             'dst': libexecdir}
                            for (file, dest) in install_files_bc])
-install_cmd = ' && '.join(['%(old)s && mkdir -p ${DESTDIR}/%(dst)s && cp -r %(srcdir)s/generic/include/clc ${DESTDIR}/%(dst)s' %
+install_cmd = ' && '.join(['%(old)s && mkdir -p ${DESTDIR}/%(dst)s && cp -r generic/include/clc ${DESTDIR}/%(dst)s' %
                            {'old': install_cmd,
                             'dst': includedir,
                             'srcdir': srcdir}])
