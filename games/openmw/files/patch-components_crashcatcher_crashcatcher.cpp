--- components/crashcatcher/crashcatcher.cpp.orig	2025-07-01 11:41:15 UTC
+++ components/crashcatcher/crashcatcher.cpp
@@ -83,6 +83,7 @@ namespace
         { SIGFPE, "FPU exception", "SIGFPE" },
         { SIGBUS, "System BUS error", "SIGBUS" },
         { SIGABRT, "Abnormal termination condition", "SIGABRT" },
+        { 0, nullptr },
     };
 
     constexpr SignalInfo sigIllCodes[] = {
@@ -96,6 +97,7 @@ namespace
         { ILL_COPROC, "Coprocessor error" },
         { ILL_BADSTK, "Internal stack error" },
 #endif
+        { 0, nullptr },
     };
 
     constexpr SignalInfo sigFpeCodes[] = {
@@ -107,6 +109,7 @@ namespace
         { FPE_FLTRES, "Floating point inexact result" },
         { FPE_FLTINV, "Floating point invalid operation" },
         { FPE_FLTSUB, "Subscript out of range" },
+        { 0, nullptr },
     };
 
     constexpr SignalInfo sigSegvCodes[] = {
@@ -114,6 +117,7 @@ namespace
         { SEGV_MAPERR, "Address not mapped to object" },
         { SEGV_ACCERR, "Invalid permissions for mapped object" },
 #endif
+        { 0, nullptr },
     };
 
     constexpr SignalInfo sigBusCodes[] = {
@@ -122,6 +126,7 @@ namespace
         { BUS_ADRERR, "Non-existent physical address" },
         { BUS_OBJERR, "Object specific hardware error" },
 #endif
+        { 0, nullptr },
     };
 
     const char* findSignalDescription(std::span<const SignalInfo> info, int code)
