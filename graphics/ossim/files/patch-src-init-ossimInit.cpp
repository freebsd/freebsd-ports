Obtained from:	https://github.com/ossimlabs/ossim/commit/c456397821cf369af4d9ff1fb60a5dfd1bcefc24
		https://github.com/ossimlabs/ossim/commit/0498f71e811ff3068ba491929c09aa5137ea0cca
		https://github.com/ossimlabs/ossim/commit/c0d97536f9ac967941b6ca48a6a7a4dde44f4ee3

--- src/init/ossimInit.cpp.orig	2019-10-17 21:54:21 UTC
+++ src/init/ossimInit.cpp
@@ -65,12 +65,61 @@
 
 #include <algorithm>
 #include <mutex>
-
+#include <geos_c.h>
+#include <cstdio>
+#include <cstdarg>
+#include <cstddef>
 using namespace std;
 
 static ossimTrace traceExec = ossimTrace("ossimInit:exec");
 static ossimTrace traceDebug = ossimTrace("ossimInit:debug");
 
+extern "C"
+{
+   void geosNoticeFunction(const char *fmt, ...);
+   void geosErrorFunction(const char *fmt, ...);
+}
+
+ossimString geosErrorV(const char *fmt, va_list args)
+{
+   char temp[2024];
+   if (fmt)
+   {
+      vsprintf(temp, fmt, args);
+   }
+   else
+   {
+      sprintf(temp, "%s", "");
+   }
+
+   return temp;
+}
+
+void geosNoticeFunction(const char *fmt, ...)
+{
+   // NOTE: This code has an infinite loop in it!!! (drb)
+   //std::lock_guard<std::mutex> lock(theMutex);
+   // theMutex.lock();
+   va_list args;
+
+   va_start(args, fmt);
+   ossimString result = geosErrorV(fmt, args);
+   va_end(args);
+   // theMutex.unlock();
+   ossimNotify(ossimNotifyLevel_WARN) << result << "\n";
+}
+
+void geosErrorFunction(const char *fmt, ...)
+{
+   va_list args;
+
+   va_start(args, fmt);
+   ossimString result = geosErrorV(fmt, args);
+   va_end(args);
+   // theMutex.unlock();
+   ossimNotify(ossimNotifyLevel_WARN) << result << "\n";
+}
+
 ossimInit* ossimInit::theInstance = 0;
 
 ossimInit::~ossimInit()
@@ -122,6 +171,8 @@ void ossimInit::initialize(int& argc, ch
 {
    static std::mutex m;
    std::lock_guard<std::mutex> lock(m);
+   initGEOS(geosNoticeFunction, geosErrorFunction);
+
    if( !theInitializedFlag )
    {
       ossimArgumentParser argumentParser(&argc, argv);
@@ -144,6 +195,8 @@ void ossimInit::initialize(ossimArgument
       }
       return;
    }
+   initGEOS(geosNoticeFunction, geosErrorFunction);
+
    theInstance->parseEnvOptions(parser);
    theInstance->parseNotifyOption(parser);
    theInstance->parsePrefsOptions(parser);
@@ -202,7 +255,7 @@ void ossimInit::initialize()
       }
       return;
    }
-   
+
    int argc = 1;
    char* argv[1];
 
@@ -210,59 +263,11 @@ void ossimInit::initialize()
    argv[0][0] = '\0';
    initialize(argc, argv);
    delete [] argv[0];
-
-#if 0   
-    static std::mutex m;
-   std::lock_guard<std::mutex> lock(m);
-   if(theInitializedFlag)
-   {
-      if (traceDebug())
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "DEBUG ossimInit::initialize(): Already initialized, returning......" << std::endl;
-      }
-      return;
-   }
-
-   theInstance->theAppName  = "";
-   theInstance->thePreferences = ossimPreferences::instance();
-   theInstance->initializeDefaultFactories();
-   
-   if ( theElevEnabledFlag )
-   {
-      theInstance->initializeElevation();
-   }
-
-   theInstance->initializeLogFile();
-
-   //---
-   // To do:
-   // We need a mechanism to register factories to the "front" or the
-   // "back" of factory list so that plugins can override things.  For
-   // now we will initialize the plugins last...
-   //---
-   if(thePluginLoaderEnabledFlag)
-   {
-      theInstance->initializePlugins();
-   }
-
-   if (traceDebug())
-   {
-      ossimNotify(ossimNotifyLevel_DEBUG)
-         << "ossim preferences file: "
-         << theInstance->thePreferences->getPreferencesFilename()
-         << "\nVersion: " << version()
-         << "\nossimInit::initialize() leaving..."
-         << std::endl;
-   } 
-   
-   theInitializedFlag = true;
-#endif
 }
 
 void ossimInit::finalize()
 {
-   
+   finishGEOS();
 }
 /*!****************************************************************************
  *  Prints to stdout the list of command line options that this object parses.
