--- src/serial/grpc_integration/grpc_integration.cpp.orig	2025-07-22 11:26:40 UTC
+++ src/serial/grpc_integration/grpc_integration.cpp
@@ -87,21 +87,6 @@ static CNCBILogSink s_NCBILogSink;
 
 #else //ABSEIL_LOG
 
-extern "C" {
-    static void s_NCBI_GPR_Log_Function(gpr_log_func_args *args) {
-        static const char* unk_func = ncbi::g_DiagUnknownFunction();
-        ncbi::CDiagCompileInfo diag_info(args->file, args->line, unk_func, "GRPC");
-        ncbi::EDiagSev sev = ncbi::eDiag_Error;
-        switch (args->severity) {
-        case GPR_LOG_SEVERITY_DEBUG:  sev = ncbi::eDiag_Trace;  break;
-        case GPR_LOG_SEVERITY_INFO:   sev = ncbi::eDiag_Info;   break;
-        case GPR_LOG_SEVERITY_ERROR:  sev = ncbi::eDiag_Error;  break;
-        }
-        ncbi::CNcbiDiag(diag_info) << ncbi::Severity(sev) << args->message << ncbi::Endm;
-    }
-}
-#define GPR_SET_LOG_FUNCION gpr_set_log_function(s_NCBI_GPR_Log_Function)
-
 #endif //ABSEIL_LOG
 #endif //HAVE_LIBGRPC
 
@@ -172,7 +157,6 @@ CGRPCInitializer::CGRPCInitializer(void)
 
 CGRPCInitializer::CGRPCInitializer(void)
 {
-    GPR_SET_LOG_FUNCION;
     sm_ServerCallbacks = new CGRPCServerCallbacks;
     grpc::Server::SetGlobalCallbacks(sm_ServerCallbacks);
     // NB: on the client side, we encourage the use of
