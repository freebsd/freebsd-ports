--- src/corelibs/U2Private/U2Private.pro.orig	2018-08-16 13:59:12 UTC
+++ src/corelibs/U2Private/U2Private.pro
@@ -12,12 +12,7 @@ HEADERS += src/AppContextImpl.h \
            src/PluginSupportImpl.h \
            src/ServiceRegistryImpl.h \
            src/SettingsImpl.h \
-           src/TaskSchedulerImpl.h \
-           src/crash_handler/CrashHandler.h \
-           src/crash_handler/CrashHandlerArgsHelper.h \
-           src/crash_handler/CrashHandlerPrivate.h \
-           src/crash_handler/CrashLogCache.h \
-           src/crash_handler/StackWalker.h
+           src/TaskSchedulerImpl.h
 
 SOURCES += src/AppContextImpl.cpp \
            src/AppSettingsImpl.cpp \
@@ -30,23 +25,13 @@ SOURCES += src/AppContextImpl.cpp \
            src/PluginSupportImpl.cpp \
            src/ServiceRegistryImpl.cpp \
            src/SettingsImpl.cpp \
-           src/TaskSchedulerImpl.cpp \
-           src/crash_handler/CrashHandler.cpp \
-           src/crash_handler/CrashHandlerArgsHelper.cpp \
-           src/crash_handler/CrashHandlerPrivate.cpp \
-           src/crash_handler/CrashLogCache.cpp \
-           src/crash_handler/StackWalker.cpp
+           src/TaskSchedulerImpl.cpp
 
 TRANSLATIONS += transl/russian.ts
 
 win32 {
     HEADERS += src/crash_handler/CrashHandlerPrivateWin.h
     SOURCES += src/crash_handler/CrashHandlerPrivateWin.cpp
-}
-
-unix_not_mac() {
-    HEADERS += src/crash_handler/CrashHandlerPrivateUnixNotMac.h
-    SOURCES += src/crash_handler/CrashHandlerPrivateUnixNotMac.cpp
 }
 
 mac {
