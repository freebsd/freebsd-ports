--- net/base/features.cc.orig	2024-02-21 00:20:50 UTC
+++ net/base/features.cc
@@ -500,7 +500,12 @@ BASE_FEATURE(kSpdyHeadersToHttpResponseUseBuilder,
              "SpdyHeadersToHttpResponseUseBuilder",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
+#if BUILDFLAG(IS_OPENBSD)
+// No IP_RECVTOS support
 BASE_FEATURE(kReceiveEcn, "ReceiveEcn", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
+BASE_FEATURE(kReceiveEcn, "ReceiveEcn", base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 // TODO(crbug.com/634470): Remove this feature flag in January 2024 if the new
 // limit sticks.
