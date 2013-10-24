--- CMakeModules/download_boost.cmake.orig	2013-09-13 07:40:43.000000000 +0000
+++ CMakeModules/download_boost.cmake	2013-10-22 21:38:43.909426514 +0000
@@ -103,9 +103,9 @@
         PREFIX          "${PREFIX}"
         DOWNLOAD_DIR    "${DOWNLOAD_DIR}"
-        URL             http://downloads.sourceforge.net/project/boost/boost/${BOOST_RELEASE}/boost_${BOOST_VERS}.tar.bz2
+        URL             file://${PROJECT_SOURCE_DIR}/boost_${BOOST_VERS}.tar.bz2
         URL_MD5         ${BOOST_MD5}
 
         # The patch command executes with the working directory set to <SOURCE_DIR>
-        PATCH_COMMAND   bzr patch -p0 "${PROJECT_SOURCE_DIR}/patches/boost.patch"
+        PATCH_COMMAND   env BZR_HOME="${PROJECT_SOURCE_DIR}" bzr patch -p0 "${PROJECT_SOURCE_DIR}/patches/boost.patch"
 
         # [Mis-]use this step to erase all the boost headers and libraries before
@@ -140,9 +140,9 @@
         PREFIX          "${PREFIX}"
         DOWNLOAD_DIR    "${DOWNLOAD_DIR}"
-        URL             http://downloads.sourceforge.net/project/boost/boost/${BOOST_RELEASE}/boost_${BOOST_VERS}.tar.bz2
+        URL             file://${PROJECT_SOURCE_DIR}/boost_${BOOST_VERS}.tar.bz2
         URL_MD5         ${BOOST_MD5}
 
         # The patch command executes with the working directory set to <SOURCE_DIR>
-        PATCH_COMMAND   bzr patch -p0 "${PROJECT_SOURCE_DIR}/patches/boost.patch"
+        PATCH_COMMAND   env BZR_HOME=${PROJECT_SOURCE_DIR} bzr patch -p0 "${PROJECT_SOURCE_DIR}/patches/boost.patch"
 
         # Dick 18-Aug-2013:
@@ -167,5 +168,6 @@
 
 ExternalProject_Add_Step( boost bzr_commit_boost
-    COMMAND bzr ci -q -m pristine <SOURCE_DIR>
+    COMMAND env BZR_HOME=${PROJECT_SOURCE_DIR} bzr whoami "M R <mr@freebsd.org>"
+    COMMAND env BZR_HOME=${PROJECT_SOURCE_DIR} bzr ci -q -m pristine <SOURCE_DIR>
     COMMENT "committing pristine boost files to 'boost scratch repo'"
     DEPENDERS patch
@@ -175,5 +177,5 @@
 ExternalProject_Add_Step( boost bzr_add_boost
     # add only the headers to the scratch repo, repo = "../.bzr" from ${headers_src}
-    COMMAND bzr add -q ${headers_src}
+    COMMAND env BZR_HOME=${PROJECT_SOURCE_DIR} bzr add -q ${headers_src}
     COMMENT "adding pristine boost files to 'boost scratch repo'"
     DEPENDERS bzr_commit_boost
@@ -182,5 +184,5 @@
 
 ExternalProject_Add_Step( boost bzr_init_boost
-    COMMAND bzr init -q <SOURCE_DIR>
+    COMMAND env BZR_HOME=${PROJECT_SOURCE_DIR} bzr init -q <SOURCE_DIR>
     COMMENT "creating 'boost scratch repo' specifically for boost to track boost patches"
     DEPENDERS bzr_add_boost
