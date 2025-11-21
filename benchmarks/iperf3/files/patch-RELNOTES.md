diff --git a/RELNOTES.md b/RELNOTES.md
index cf5bd19..5bb89a5 100644
--- RELNOTES.md.orig
+++ RELNOTES.md
@@ -30,10 +30,10 @@ releases, including iperf-3.19.1.
       flag (PR #1903)
 
     * Sends with `--zerocopy` are now properly seeded with data
-      instead of being all-zeroes. (PR #1909)
+      instead of being all-zeroes. (PR #1949)
 
-    * The `--time` flag is now allowed on the iperf3 server to impose
-      a maximum duration on timed tests. (PR #1684, PR #1931)
+    * The `--server-max-duration` flag is now allowed on the iperf3 server to impose
+      a maximum duration on timed tests. (PR #1684)
 
     * The `--rcv-timeout` flag is now ignored for `--bidir`
       tests. This change prevents premature termination of
