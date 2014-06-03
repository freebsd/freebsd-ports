--- CMakeModules/download_boost.cmake.orig	2014-05-23 16:28:19.000000000 +0200
+++ CMakeModules/download_boost.cmake	2014-06-03 10:26:43.963718518 +0200
@@ -93,5 +93,5 @@
 
 # Default Toolset
-set( BOOST_TOOLSET "toolset=gcc" )
+set( BOOST_TOOLSET "toolset=clang" )
 
 if( KICAD_BUILD_STATIC OR APPLE )
@@ -131,5 +131,5 @@
     #message( STATUS "libs_csv:${libs_csv}" )
 
-    set( bootstrap ./bootstrap.sh --with-libraries=${libs_csv} )
+    set( bootstrap ./bootstrap.sh --with-${BOOST_TOOLSET} --with-libraries=${libs_csv} )
     # pass to *both* C and C++ compilers
     set( BOOST_CFLAGS   "cflags=${PIC_FLAG}" )
@@ -186,5 +186,5 @@
     PREFIX          "${PREFIX}"
 
-    URL             http://downloads.sourceforge.net/project/boost/boost/${BOOST_RELEASE}/boost_${BOOST_VERS}.tar.bz2
+    URL             file://${PROJECT_SOURCE_DIR}/boost_${BOOST_VERS}.tar.bz2
     DOWNLOAD_DIR    "${DOWNLOAD_DIR}"
     TIMEOUT         1200            # 20 minutes
@@ -204,7 +204,7 @@
     # fails when applying a patch to the branch twice and doesn't have a switch
     # to ignore previously applied patches
-    PATCH_COMMAND   bzr revert
+    PATCH_COMMAND   BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr revert
         # bzr revert is insufficient to remove "added" files:
-        COMMAND     bzr clean-tree -q --force
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr clean-tree -q --force
 
         COMMAND     ${PATCH_STR_CMD} "${PROJECT_SOURCE_DIR}/patches/boost_minkowski.patch"
@@ -213,6 +213,6 @@
         COMMAND     ${PATCH_STR_CMD} "${PROJECT_SOURCE_DIR}/patches/boost_macosx_x86.patch"        #https://svn.boost.org/trac/boost/ticket/8266
         # tell bzr about "added" files by last patch:
-        COMMAND     bzr add libs/context/src/asm/jump_i386_x86_64_sysv_macho_gas.S
-        COMMAND     bzr add libs/context/src/asm/make_i386_x86_64_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/jump_i386_x86_64_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/make_i386_x86_64_sysv_macho_gas.S
 
         COMMAND     ${PATCH_STR_CMD} "${PROJECT_SOURCE_DIR}/patches/boost_macosx_x86_build.patch"  #https://svn.boost.org/trac/boost/ticket/8266
@@ -221,18 +221,18 @@
         COMMAND     ${PATCH_STR_CMD} "${PROJECT_SOURCE_DIR}/patches/boost_mingw.patch"             #https://svn.boost.org/trac/boost/ticket/7262
         # tell bzr about "added" files by last patch:
-        COMMAND     bzr add libs/context/src/asm/make_i386_ms_pe_gas.S
-        COMMAND     bzr add libs/context/src/asm/jump_i386_ms_pe_gas.S
-        COMMAND     bzr add libs/context/src/asm/make_x86_64_ms_pe_gas.S
-        COMMAND     bzr add libs/context/src/asm/jump_x86_64_ms_pe_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/make_i386_ms_pe_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/jump_i386_ms_pe_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/make_x86_64_ms_pe_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/jump_x86_64_ms_pe_gas.S
 
         COMMAND     ${PATCH_STR_CMD} "${PROJECT_SOURCE_DIR}/patches/patch_macosx_context_ppc_v2.patch" #https://svn.boost.org/trac/boost/ticket/8266
-        COMMAND     bzr add libs/context/build/Jamfile.v2
-        COMMAND     bzr add libs/context/build/architecture.jam
-        COMMAND     bzr add libs/context/src/asm/jump_combined_sysv_macho_gas.S
-        COMMAND     bzr add libs/context/src/asm/jump_ppc32_sysv_macho_gas.S
-        COMMAND     bzr add libs/context/src/asm/jump_ppc64_sysv_macho_gas.S
-        COMMAND     bzr add libs/context/src/asm/make_combined_sysv_macho_gas.S
-        COMMAND     bzr add libs/context/src/asm/make_ppc32_sysv_macho_gas.S
-        COMMAND     bzr add libs/context/src/asm/make_ppc64_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/build/Jamfile.v2
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/build/architecture.jam
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/jump_combined_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/jump_ppc32_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/jump_ppc64_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/make_combined_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/make_ppc32_sysv_macho_gas.S
+        COMMAND     BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add libs/context/src/asm/make_ppc64_sysv_macho_gas.S
 
     # [Mis-]use this step to erase all the boost headers and libraries before
@@ -297,5 +297,6 @@
 
 ExternalProject_Add_Step( boost bzr_commit_boost
-    COMMAND bzr ci -q -m pristine <SOURCE_DIR>
+    COMMAND BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr whoami "M R <mr@freebsd.org>"
+    COMMAND BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr ci -q -m pristine <SOURCE_DIR>
     COMMENT "committing pristine boost files to 'boost scratch repo'"
     DEPENDERS patch
@@ -305,5 +306,5 @@
 ExternalProject_Add_Step( boost bzr_add_boost
     # add only the headers to the scratch repo, repo = "../.bzr" from ${headers_src}
-    COMMAND bzr add -q ${PREFIX}/src/boost
+    COMMAND BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr add -q ${PREFIX}/src/boost
     COMMENT "adding pristine boost files to 'boost scratch repo'"
     DEPENDERS bzr_commit_boost
@@ -312,5 +313,5 @@
 
 ExternalProject_Add_Step( boost bzr_init_boost
-    COMMAND bzr init -q <SOURCE_DIR>
+    COMMAND BZR_LOG=/dev/null BZR_HOME=${PROJECT_SOURCE_DIR} bzr init -q <SOURCE_DIR>
     COMMENT "creating 'boost scratch repo' specifically for boost to track boost patches"
     DEPENDERS bzr_add_boost
