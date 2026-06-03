--- src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp.orig	2025-08-13 19:50:05 UTC
+++ src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp
@@ -151,7 +151,7 @@ enum
     MODIFYVM_UARTMODE,
     MODIFYVM_UARTTYPE,
     MODIFYVM_UART,
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
     MODIFYVM_LPTMODE,
     MODIFYVM_LPT,
 #endif
@@ -393,7 +393,7 @@ static const RTGETOPTDEF g_aModifyVMOptions[] =
     OPT2("--uart-mode",                     "--uartmode",               MODIFYVM_UARTMODE,                  RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT2("--uart-type",                     "--uarttype",               MODIFYVM_UARTTYPE,                  RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT1("--uart",                                                      MODIFYVM_UART,                      RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS) || defined(RT_OS_FREEBSD)
     OPT2("--lpt-mode",                      "--lptmode",                MODIFYVM_LPTMODE,                   RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT1("--lpt",                                                       MODIFYVM_LPT,                       RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
 #endif
@@ -2680,7 +2680,7 @@ RTEXITCODE handleModifyVM(HandlerArg *a)
                 break;
             }
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
             case MODIFYVM_LPTMODE:
             {
                 ComPtr<IParallelPort> lpt;
