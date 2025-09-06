https://github.com/dotnet/diagnostics/pull/5547

--- src/diagnostics/src/SOS/extensions/hostcoreclr.cpp.orig	2024-05-28 16:53:38 UTC
+++ src/diagnostics/src/SOS/extensions/hostcoreclr.cpp
@@ -460,11 +460,6 @@ static HRESULT GetHostRuntime(std::string& coreClrPath
     // If the hosting runtime isn't already set, use the runtime we are debugging
     if (g_hostRuntimeDirectory == nullptr)
     {
-#if defined(HOST_FREEBSD)
-        TraceError("Hosting on NetBSD not supported\n");
-        return E_FAIL;
-#else
-
         HRESULT Status = E_FAIL;
         std::vector<ProbingStrategy> strategyList = {
              { ProbeEnvVarInstallationHint, RuntimeHostingConstants::DotnetRootArchSpecificEnvVar }
@@ -527,7 +522,6 @@ static HRESULT GetHostRuntime(std::string& coreClrPath
     coreClrPath.append(DIRECTORY_SEPARATOR_STR_A);
     coreClrPath.append(MAKEDLLNAME_A("coreclr"));
     return S_OK;
-#endif
 }
 
 /**********************************************************************\
