--- /dev/null	2026-03-06 07:12:11 UTC
+++ stubs/org/osgi/annotation/bundle/Export.java
@@ -0,0 +1 @@
+package org.osgi.annotation.bundle; import java.lang.annotation.*;  @Retention(RetentionPolicy.CLASS) public @interface Export { String[] value() default {}; }
