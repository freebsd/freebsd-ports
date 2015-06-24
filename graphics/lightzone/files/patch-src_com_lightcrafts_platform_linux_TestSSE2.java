--- src/com/lightcrafts/platform/linux/TestSSE2.java.orig	2015-06-23 04:17:32 UTC
+++ src/com/lightcrafts/platform/linux/TestSSE2.java
@@ -29,6 +29,8 @@ class TestSSE2 {
             regex = "^flags\t\t:.*sse2";
         } else if (osname.indexOf("SunOS") >= 0) {
             regex = "^\t.*sse2";
+        } else if (osname.indexOf("FreeBSD") >= 0) {
+            regex = "^hw.instruction_sse: 1";
         } else {
             regex = "^  Features=.*SSE2";
         }
@@ -42,6 +44,8 @@ class TestSSE2 {
             cmd = new String[] {"cat", "/proc/cpuinfo"};
         } else if (osname.indexOf("SunOS") >= 0) {
             cmd = new String[] {"sh", "-c", "isainfo -nv ; psrinfo -pv"};
+        } else if (osname.indexOf("FreeBSD") >= 0) {
+            cmd = new String[] {"/sbin/sysctl", "hw"};
         } else {
             cmd = new String[] {"dmesg"};
         }
@@ -68,6 +72,8 @@ class TestSSE2 {
             regex = getCpuInfoLine("^model name\t: ");
         } else if (osname.indexOf("SunOS") >= 0) {
             regex = getCpuInfoLine("^\t");
+        } else if (osname.indexOf("FreeBSD") >= 0) {
+            regex = getCpuInfoLine("^hw.model: ");
         } else {
             regex = getCpuInfoLine("^CPU: ");
         }
