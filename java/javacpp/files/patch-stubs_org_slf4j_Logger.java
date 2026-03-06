--- /dev/null	2026-03-06 07:12:54 UTC
+++ stubs/org/slf4j/Logger.java
@@ -0,0 +1 @@
+package org.slf4j; public interface Logger {  boolean isDebugEnabled(); boolean isInfoEnabled(); boolean isWarnEnabled(); boolean isErrorEnabled();  void debug(String s); void info(String s); void warn(String s); void error(String s); }
