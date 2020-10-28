--- modules/javafx.graphics/src/main/java/com/sun/glass/ui/Platform.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/java/com/sun/glass/ui/Platform.java
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
             } else if (osNameLowerCase.startsWith("ios")) {
                 type = IOS;
