commit 74dec52749e3c3af2ac6492f50e2676128f35b27
Author: Milian Wolff <mail@milianw.de>
Date:   Fri Nov 18 16:26:06 2011 +0100

    fix svn api usage: use svn_dirent_canonicalize instead of svn_path_internal_style
    
    this was suggested by Stephan Sperling
    
    CCBUG: 284061

diff --git a/plugins/subversion/kdevsvncpp/path.cpp b/plugins/subversion/kdevsvncpp/path.cpp
index eaa84c1..4dced08 100644
--- ./plugins/subversion/kdevsvncpp/path.cpp
+++ ./plugins/subversion/kdevsvncpp/path.cpp
@@ -24,6 +24,7 @@
 
 // subversion api
 #include "svn_path.h"
+#include "svn_dirent_uri.h"
 
 // apr api
 #include "apr_file_io.h"
@@ -63,8 +64,7 @@ namespace svn
       m_path = "";
     else
     {
-      const char * int_path =
-        svn_path_internal_style(path, pool.pool());
+      const char * int_path = svn_dirent_canonicalize(path, pool);
 
       m_path = int_path;
 
