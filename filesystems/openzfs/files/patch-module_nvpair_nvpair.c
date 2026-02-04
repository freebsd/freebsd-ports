--- module/nvpair/nvpair.c.orig	2025-12-18 18:01:01 UTC
+++ module/nvpair/nvpair.c
@@ -3246,7 +3246,8 @@ nvs_xdr_nvl_fini(nvstream_t *nvs)
  * xdrproc_t-compatible callbacks for xdr_array()
  */
 
-#if defined(_KERNEL) && defined(__linux__) /* Linux kernel */
+#if (defined(__FreeBSD_version) && __FreeBSD_version >= 1600010) || \
+    defined(_KERNEL) && defined(__linux__) /* Linux kernel */
 
 #define	NVS_BUILD_XDRPROC_T(type)		\
 static bool_t					\
@@ -3255,7 +3256,7 @@ nvs_xdr_nvp_##type(XDR *xdrs, void *ptr)	\
 	return (xdr_##type(xdrs, ptr));		\
 }
 
-#elif !defined(_KERNEL) && defined(XDR_CONTROL) /* tirpc */
+#elif !defined(_KERNEL) && defined(XDR_CONTROL) /* tirpc, FreeBSD < 16 */
 
 #define	NVS_BUILD_XDRPROC_T(type)		\
 static bool_t					\
@@ -3271,7 +3272,7 @@ nvs_xdr_nvp_##type(XDR *xdrs, ...)		\
 	return (xdr_##type(xdrs, ptr));		\
 }
 
-#else /* FreeBSD, sunrpc */
+#else /* FreeBSD kernel < 16, sunrpc */
 
 #define	NVS_BUILD_XDRPROC_T(type)		\
 static bool_t					\
