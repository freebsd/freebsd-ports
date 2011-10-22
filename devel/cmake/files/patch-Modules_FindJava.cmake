--- ./Modules/FindJava.cmake.orig	2010-04-16 16:49:52.000000000 +1100
+++ ./Modules/FindJava.cmake	2010-04-16 16:51:27.398957616 +1100
@@ -90,7 +90,7 @@
       # 2. OpenJDK 1.6
       # 3. GCJ 1.5
       # 4. Kaffe 1.4.2
-      IF(var MATCHES "java version \"[0-9]+\\.[0-9]+\\.[0-9_.]+[oem-]*\".*")
+      IF(var MATCHES "[java|openjdk] version \"[0-9]+\\.[0-9]+\\.[0-9_.]+[oem-]*\".*")
         # This is most likely Sun / OpenJDK, or maybe GCJ-java compat layer
         STRING( REGEX REPLACE ".* version \"([0-9]+\\.[0-9]+\\.[0-9_.]+)[oem-]*\".*"
                 "\\1" Java_VERSION_STRING "${var}" )
