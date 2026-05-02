--- src/butil/logging.cc.orig	2026-02-23 02:11:29 UTC
+++ src/butil/logging.cc
@@ -129,6 +129,16 @@ BUTIL_VALIDATE_GFLAG(print_stack_on_check, butil::Pass
             "Print the stack trace when a CHECK was failed");
 BUTIL_VALIDATE_GFLAG(print_stack_on_check, butil::PassValidate);
 
+#if defined(OS_FREEBSD)
+// Rename flags to avoid gflags duplicate registration with system glog.
+// glog defines "v" and "vmodule"; we define "brpc_verbose" and "brpc_vmodule"
+// and create local aliases so brpc code can still use FLAGS_v / FLAGS_vmodule.
+DEFINE_int32(brpc_verbose, 0, "Show all VLOG(m) messages for m <= this."
+               " Overridable by --brpc_vmodule.");
+DEFINE_string(brpc_vmodule, "", "per-module verbose level.");
+#define FLAGS_v FLAGS_brpc_verbose
+#define FLAGS_vmodule FLAGS_brpc_vmodule
+#else
 DEFINE_int32(v, 0, "Show all VLOG(m) messages for m <= this."
              " Overridable by --vmodule.");
 DEFINE_string(vmodule, "", "per-module verbose level."
@@ -136,15 +146,24 @@ DEFINE_string(vmodule, "", "per-module verbose level."
               " MODULE_NAME is a glob pattern, matched against the filename base"
               " (that is, name ignoring .cpp/.h)."
               " LOG_LEVEL overrides any value given by --v.");
+#endif
 
 DEFINE_bool(log_pid, false, "Log process id");
 
 DEFINE_bool(log_bid, true, "Log bthread id");
 
+#if defined(OS_FREEBSD)
+DEFINE_int32(brpc_minloglevel, 0, "Any log at or above this level will be "
+             "displayed. Anything below this level will be silently ignored. "
+             "0=INFO 1=NOTICE 2=WARNING 3=ERROR 4=FATAL");
+BUTIL_VALIDATE_GFLAG(brpc_minloglevel, butil::NonNegativeInteger);
+#define FLAGS_minloglevel FLAGS_brpc_minloglevel
+#else
 DEFINE_int32(minloglevel, 0, "Any log at or above this level will be "
              "displayed. Anything below this level will be silently ignored. "
              "0=INFO 1=NOTICE 2=WARNING 3=ERROR 4=FATAL");
 BUTIL_VALIDATE_GFLAG(minloglevel, butil::NonNegativeInteger);
+#endif
 
 DEFINE_bool(log_hostname, false, "Add host after pid in each log so"
             " that we know where logs came from when using aggregation tools"
