--- ../stoc/source/javavm/javavm.cxx.orig	Fri Mar 21 12:03:58 2003
+++ ../stoc/source/javavm/javavm.cxx	Fri Mar 21 12:04:24 2003
@@ -1097,7 +1097,7 @@
                             static_cast<
                                 css::java::JavaNotConfiguredException * >(0))))
                 {
-#if defined LINUX
+#if defined LINUX || defined FREEBSD
                     // Because of LD_LIBRARY_PATH, even javaldx --use-links does
                     // not work sometimes:
                     m_bDontCreateJvm = true;
@@ -1109,7 +1109,7 @@
                                      css::java::MissingJavaRuntimeException * >(
                                          0))))
                 {
-#if defined LINUX
+#if defined LINUX || defined FREEBSD
                     // Because of LD_LIBRARY_PATH, even javaldx --use-links does
                     // not work sometimes:
                     m_bDontCreateJvm = true;
@@ -1596,7 +1596,7 @@
     // On linux we load jvm with RTLD_GLOBAL. This is necessary for debugging, because
     // libjdwp.so need a symbol (fork1) from libjvm which it only gets if the jvm is loaded
     // witd RTLD_GLOBAL. On Solaris libjdwp.so is correctly linked with libjvm.so
-#ifdef LINUX
+#ifdef LINUX || defined FREEBSD
     if(!m_aJavaLib.load(jvm.getRuntimeLib(), SAL_LOADMODULE_GLOBAL | SAL_LOADMODULE_NOW))
 #else
     if(!m_aJavaLib.load(jvm.getRuntimeLib()))
