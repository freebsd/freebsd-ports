--- src/qml/jsruntime/qv4global_p.h	2018-02-06 19:49:18 UTC
+++ src/qml/jsruntime/qv4global_p.h
@@ -104,7 +104,7 @@ inline double trunc(double d) { return d > 0 ? floor(d
 #    define V4_ENABLE_JIT
 #  endif
 #elif defined(Q_PROCESSOR_ARM_64) && (QT_POINTER_SIZE == 8)
-#  if defined(Q_OS_LINUX) || defined(Q_OS_QNX)
+#  if defined(Q_OS_LINUX) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD)
 #    define V4_ENABLE_JIT
 #  endif
 #elif defined(Q_PROCESSOR_MIPS_32) && defined(Q_OS_LINUX)
