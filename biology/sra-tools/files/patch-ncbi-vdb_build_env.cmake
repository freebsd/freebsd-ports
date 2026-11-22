--- ncbi-vdb/build/env.cmake.orig	2026-03-25 20:29:00 UTC
+++ ncbi-vdb/build/env.cmake
@@ -398,7 +398,7 @@ if ( SINGLE_CONFIG )
 
 if(NOT _NCBIVDB_CFG_PACKAGING)
 if ( SINGLE_CONFIG )
-    install( SCRIPT CODE
+    install( CODE
         "execute_process(COMMAND /bin/bash -c \"${CMAKE_SOURCE_DIR}/build/install-root.sh ${VERSION} ${INST_INCDIR} ${INST_LIBDIR} \" )"
     )
 endif()
