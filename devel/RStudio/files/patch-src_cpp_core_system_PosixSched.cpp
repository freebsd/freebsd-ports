--- src/cpp/core/system/PosixSched.cpp.orig	2020-01-23 23:30:24 UTC
+++ src/cpp/core/system/PosixSched.cpp
@@ -15,8 +15,12 @@
 
 #include <core/system/PosixSched.hpp>
 
+#define _GNU_SOURCE
 #include <algorithm>
 #include <sched.h>
+#include <sys/types.h>
+#include <sys/param.h> // w/out this fails on i386 with error: use of undeclared identifier 'NBBY'
+#include <sys/cpuset.h>
 
 #include <shared_core/Error.hpp>
 
@@ -42,9 +46,10 @@ bool isCpuAffinityEmpty(const CpuAffinity& cpus)
 Error getCpuAffinity(CpuAffinity* pCpus)
 {
 #ifndef __APPLE__
-   cpu_set_t cs;
+/*
+   cpuset_t cs;
    CPU_ZERO(&cs);
-   if (::sched_getaffinity(0, sizeof(cs), &cs) == -1)
+   if (sched_getaffinity(0, sizeof(cs), &cs) == -1)
       return systemError(errno, ERROR_LOCATION);
 
    pCpus->clear();
@@ -56,7 +61,7 @@ Error getCpuAffinity(CpuAffinity* pCpus)
       else
          pCpus->push_back(false);
    }
-
+*/
    return Success();
 #else
    return systemError(boost::system::errc::not_supported, ERROR_LOCATION);
@@ -67,7 +72,8 @@ Error getCpuAffinity(CpuAffinity* pCpus)
 Error setCpuAffinity(const CpuAffinity& cpus)
 {
 #ifndef __APPLE__
-   cpu_set_t cs;
+/*
+   cpuset_t cs;
    CPU_ZERO(&cs);
 
    for (std::size_t i=0; i<cpus.size(); i++)
@@ -80,7 +86,7 @@ Error setCpuAffinity(const CpuAffinity& cpus)
 
    if (::sched_setaffinity(0, sizeof(cs), &cs) == -1)
       return systemError(errno, ERROR_LOCATION);
-
+*/
    return Success();
 #else
    return systemError(boost::system::errc::not_supported, ERROR_LOCATION);
