--- src/cpp/core/system/PosixSched.cpp.orig	2020-05-18 18:11:10 UTC
+++ src/cpp/core/system/PosixSched.cpp
@@ -41,7 +41,7 @@ bool isCpuAffinityEmpty(const CpuAffinity& cpus)
 
 Error getCpuAffinity(CpuAffinity* pCpus)
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    cpu_set_t cs;
    CPU_ZERO(&cs);
    if (::sched_getaffinity(0, sizeof(cs), &cs) == -1)
@@ -66,7 +66,7 @@ Error getCpuAffinity(CpuAffinity* pCpus)
 
 Error setCpuAffinity(const CpuAffinity& cpus)
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    cpu_set_t cs;
    CPU_ZERO(&cs);
 
