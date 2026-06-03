https://github.com/dotnet/diagnostics/pull/5547

--- src/diagnostics/src/SOS/extensions/hostcoreclr.cpp.orig	2025-05-20 22:48:44 UTC
+++ src/diagnostics/src/SOS/extensions/hostcoreclr.cpp
@@ -476,11 +476,6 @@ static HRESULT GetHostRuntime(std::string& coreClrPath
     // If the hosting runtime isn't already set, use the runtime we are debugging
     if (g_hostRuntimeDirectory == nullptr)
     {
-#if defined(HOST_FREEBSD)
-        TraceHostingError("FreeBSD not supported\n");
-        return E_FAIL;
-#else
-
         HRESULT Status = E_FAIL;
         std::vector<ProbingStrategy> strategyList = {
              { ProbeEnvVarInstallationHint, RuntimeHostingConstants::DotnetRootArchSpecificEnvVar }
@@ -546,7 +541,6 @@ static HRESULT GetHostRuntime(std::string& coreClrPath
     coreClrPath.append(DIRECTORY_SEPARATOR_STR_A);
     coreClrPath.append(MAKEDLLNAME_A("coreclr"));
     return S_OK;
-#endif
 }
 
 /**********************************************************************\
