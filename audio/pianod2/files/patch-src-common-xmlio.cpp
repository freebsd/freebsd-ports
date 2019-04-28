--- src/common/xmlio.cpp.orig	2018-03-16 18:13:50 UTC
+++ src/common/xmlio.cpp
@@ -212,11 +212,7 @@ static char *select_nobody_user (const char *nobody_na
             // Stupid apple/BSDism: nobody.pw_gid should be gid_t but is int.
             // Other varieties get this right.
         } while (getgrouplist (nobody_name, nobody.pw_gid,
-#if !defined(__FreeBSD__) && !defined(__APPLE__)
                                nobody_groups,
-#else
-                               (int *) nobody_groups,
-#endif
                                &nobody_groups_count) < 0);
     }
     return home;
