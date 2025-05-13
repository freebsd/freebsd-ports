--- src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp.orig	2022-10-06 19:10:28.000000000 +0200
+++ src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp	2024-12-26 16:08:30.624183000 +0100
@@ -170,7 +170,7 @@
     MODIFYVM_UARTMODE,
     MODIFYVM_UARTTYPE,
     MODIFYVM_UART,
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
     MODIFYVM_LPTMODE,
     MODIFYVM_LPT,
 #endif
@@ -382,7 +382,7 @@
     OPT2("--uart-mode",                     "--uartmode",               MODIFYVM_UARTMODE,                  RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT2("--uart-type",                     "--uarttype",               MODIFYVM_UARTTYPE,                  RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT1("--uart",                                                      MODIFYVM_UART,                      RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS) || defined(RT_OS_FREEBSD)
     OPT2("--lpt-mode",                      "--lptmode",                MODIFYVM_LPTMODE,                   RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT1("--lpt",                                                       MODIFYVM_LPT,                       RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
 #endif
@@ -2496,7 +2496,7 @@
                 break;
             }
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
             case MODIFYVM_LPTMODE:
             {
                 ComPtr<IParallelPort> lpt;
