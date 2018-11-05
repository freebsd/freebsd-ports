--- src/httpc.c.orig	2018-10-12 19:53:35 UTC
+++ src/httpc.c
@@ -333,7 +333,9 @@ httpc_execute(struct httpc_request *req,
 			++env->stat.http_other_responses;
 		}
 		break;
+#if LIBCURL_VERSION_NUM < 0x073e00
 	case CURLE_SSL_CACERT:
+#endif
 	case CURLE_PEER_FAILED_VERIFICATION:
 		/* 495 SSL Certificate Error (nginx non-standard) */
 		req->status = 495;
