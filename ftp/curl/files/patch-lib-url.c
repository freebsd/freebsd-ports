[1]
Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

[2]
Reference:	https://github.com/bagder/curl/commit/fd9d3a1ef1f7b1cb5812d04bad07818efc6f3b3a.patch

--- lib/url.c.orig	2015-04-22 05:55:54 UTC
+++ lib/url.c
@@ -658,6 +658,10 @@ CURLcode Curl_open(struct SessionHandle 
     data->progress.flags |= PGRS_HIDE;
     data->state.current_speed = -1; /* init to negative == impossible */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     data->wildcard.state = CURLWC_INIT;
     data->wildcard.filelist = NULL;
     data->set.fnmatch = ZERO_NULL;
@@ -3069,9 +3073,11 @@ ConnectionExists(struct SessionHandle *d
   struct connectdata *check;
   struct connectdata *chosen = 0;
   bool canPipeline = IsPipeliningPossible(data, needle);
+#ifdef USE_NTLM
   bool wantNTLMhttp = ((data->state.authhost.want & CURLAUTH_NTLM) ||
                        (data->state.authhost.want & CURLAUTH_NTLM_WB)) &&
     (needle->handler->protocol & PROTO_FAMILY_HTTP) ? TRUE : FALSE;
+#endif
   struct connectbundle *bundle;
 
   *force_reuse = FALSE;
@@ -3208,6 +3214,7 @@ ConnectionExists(struct SessionHandle *d
           continue;
       }
 
+#if defined(USE_NTLM)
       if((!(needle->handler->flags & PROTOPT_CREDSPERREQUEST)) ||
          (wantNTLMhttp || check->ntlm.state != NTLMSTATE_NONE)) {
         /* This protocol requires credentials per connection or is HTTP+NTLM,
@@ -3217,10 +3224,9 @@ ConnectionExists(struct SessionHandle *d
           /* one of them was different */
           continue;
         }
-#if defined(USE_NTLM)
         credentialsMatch = TRUE;
-#endif
       }
+#endif
 
       if(!needle->bits.httpproxy || needle->handler->flags&PROTOPT_SSL ||
          (needle->bits.httpproxy && check->bits.httpproxy &&
