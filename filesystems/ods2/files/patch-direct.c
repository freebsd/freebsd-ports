--- direct.c.orig	2001-08-31 18:01:07 UTC
+++ direct.c
@@ -136,12 +136,15 @@ int name_match(char *spec,int spec_len,char *dirent,in
         register char sch = *name;
         if (sch != '*') {
             register char ech = *entry;
-                if (sch != ech) if (toupper(sch) != toupper(ech))
-                    if (sch == '%') {
-                        percent = MAT_NE;
-                    } else {
-                        break;
-                    }
+                if (sch != ech) {
+                   if (toupper(sch) != toupper(ech)) {
+                      if (sch == '%') {
+                          percent = MAT_NE;
+                      } else {
+                          break;
+                      }
+                   }
+                }
         } else {
             break;
         }
