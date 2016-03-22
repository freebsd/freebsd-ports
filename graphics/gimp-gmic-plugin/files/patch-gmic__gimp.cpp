--- gmic_gimp.cpp.orig	2016-02-05 13:45:21 UTC
+++ gmic_gimp.cpp
@@ -2724,10 +2724,6 @@ void process_image(const char *const com
         PROCESS_MEMORY_COUNTERS pmc;
         if (GetProcessMemoryInfo(GetCurrentProcess(),&pmc,sizeof(pmc)))
           used_memory = (unsigned long)(pmc.WorkingSetSize/1024/1024);
-#elif cimg_OS==1 // #if cimg_OS==2
-        CImg<char> st; st.load_raw("/proc/self/status",512); st.back() = 0;
-        const char *const s = std::strstr(st,"VmRSS:");
-        if (s && cimg_sscanf(s + 7,"%u",&used_memory)==1) used_memory/=1024;
 #endif // #if cimg_OS==2
       }
 
