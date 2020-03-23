--- src/common/fileio.cpp.orig	2020-03-17 17:41:27 UTC
+++ src/common/fileio.cpp
@@ -125,11 +125,7 @@ static char *select_nobody_user (const char *nobody_na
             // Other varieties get this right.
         } while (getgrouplist (nobody_name,
                                nobody.pw_gid,
-#if !defined(__FreeBSD__) && !defined(__APPLE__)
                                nobody_groups,
-#else
-                               (int *) nobody_groups,
-#endif
                                &nobody_groups_count)
                  < 0);
     }
