--- modules/graphics/src/main/java/com/sun/glass/ui/Platform.java.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/java/com/sun/glass/ui/Platform.java
@@ -52,6 +52,8 @@ final class Platform {
                    type = WINDOWS;
                 else if (userPlatform.equals("linux"))
                    type = GTK;
+                else if (userPlatform.equals("freebsd"))
+                    type = GTK;
                 else if (userPlatform.equals("gtk"))
                    type = GTK;
                 else if (userPlatform.equals("ios"))
@@ -68,6 +70,8 @@ final class Platform {
             } else if (osNameLowerCase.startsWith("wind")) {
                 type = WINDOWS;
             } else if (osNameLowerCase.startsWith("linux")) {
+                type = GTK;
+            } else if (osNameLowerCase.startsWith("freebsd")) {
                 type = GTK;
             }
         }
