--- arduino-core/src/cc/arduino/contributions/packages/HostDependentDownloadableContribution.java.orig	2016-09-21 10:09:37 UTC
+++ arduino-core/src/cc/arduino/contributions/packages/HostDependentDownloadableContribution.java
@@ -79,6 +79,16 @@ public abstract class HostDependentDownl
       }
     }
 
+    if (osName.contains("FreeBSD")) {
+      if (osArch.contains("amd64")) {
+        return host.matches("x86_64-freebsd[0-9]*");
+      } else if (osArch.contains("arm")) {
+        return host.matches("arm.*-freebsd[0-9]*");
+      } else {
+        return host.matches("i386-freebsd[0-9]*");
+      }
+    }
+
     return false;
   }
 }
