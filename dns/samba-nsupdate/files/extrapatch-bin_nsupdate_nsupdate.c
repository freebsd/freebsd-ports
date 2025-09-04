--- bin/nsupdate/nsupdate.c.orig	2025-07-06 22:45:25 UTC
+++ bin/nsupdate/nsupdate.c
@@ -2440,14 +2440,12 @@ update_completed(isc_task_t *task, isc_event_t *event)
 	case DNS_R_TSIGVERIFYFAILURE:
 	case DNS_R_UNEXPECTEDTSIG:
 	case ISC_R_FAILURE:
-#if 0
 		if (usegsstsig && answer->rcode == dns_rcode_noerror) {
 			/*
 			 * For MS DNS that violates RFC 2845, section 4.2
 			 */
 			break;
 		}
-#endif /* if 0 */
 		fprintf(stderr, "; TSIG error with server: %s\n",
 			isc_result_totext(result));
 		seenerror = true;
