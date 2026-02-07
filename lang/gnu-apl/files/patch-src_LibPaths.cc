--- src/LibPaths.cc.orig	2019-06-23 12:39:20 UTC
+++ src/LibPaths.cc
@@ -70,33 +70,22 @@ LibPaths::compute_bin_path(const char * argv0, bool lo
          //
          // we fix this by searching argv0 in $PATH
          //
-         const char * path = getenv("PATH");   // must NOT be modified
-
-         if (path)
+         if (const char * paths = getenv("PATH"))
             {
               logit && CERR << "initializing paths from  $PATH = "
-                            << path << endl;
+                            << paths << endl;
 
-              // we must not modify path, so we copy it to path1 and
-              // replace the semicolons in path1 by 0. That converts
-              // p1;p2; ... into a sequence of 0-terminated strings
-              // p1 p2 ... The variable next points to the start of each
-              // string.
-              //
-              const size_t plen = strlen(path);
-              std::string   path1;
-              path1.reserve(plen + 1);
-              loop(p, (plen + 1))   path1 += path[p];
-              char * next = &path1[0];
-              for (;;)
-                  {
-                    char * semi = strchr(next, ':');
-                    if (semi)   *semi = 0;
-                    UTF8_string filename;
-                    for (const char * n = next; *n; ++n)   filename += *n;
-                    filename += '/';
-                    for (const char * a = argv0; *a; ++a)   filename += *a;
+              while (*paths)
+                    {
+                      size_t dir_len;
+                      if (const char * colon = strchr(paths, ':'))
+                         dir_len = colon - paths;
+                      else
+                         dir_len = strlen(paths);
 
+                    std::string filename(paths, dir_len);
+                    filename += '/';
+                    filename.append(argv0);
                     if (access(filename.c_str(), X_OK) == 0)
                        {
                          strncpy(APL_bin_path, filename.c_str(),
@@ -110,8 +99,7 @@ LibPaths::compute_bin_path(const char * argv0, bool lo
                          goto done;
                        }
 
-                    if (semi == 0)   break;
-                    next = semi + 1;
+                    paths += dir_len + 1;   // next $PATH item
                   }
             }
            else
