--- src/java/datalevin/dtlvnative/DTLVConfig.java.orig	2026-03-01 22:54:30 UTC
+++ src/java/datalevin/dtlvnative/DTLVConfig.java
@@ -32,7 +32,16 @@ import org.bytedeco.javacpp.tools.*;
                            preload = { "omp" }),
                 @Platform( // FreeBSD
                            value = { "freebsd" },
-                           link = { "dtlv", "usearch" })
+                           includepath = {
+                              "/usr/local/include/",
+                              "/usr/local/include/usearch/",
+                              "../../src/"
+                           },
+                           linkpath = {
+                              "/usr/local/lib",
+                              ".."
+                           },
+                           link = { "dtlv", "usearch_c" })
             },
             target = "datalevin.dtlvnative.DTLV"
             )
