--- qw/source/cl_http.c.orig	2013-01-23 03:10:55 UTC
+++ qw/source/cl_http.c
@@ -114,7 +114,7 @@ CL_HTTP_Update (void)
 				Sys_Printf ("download failed: %ld\n", response_code);
 				CL_FailDownload ();
 			}
-			curl_multi_remove_handle (multi_handle, easy_handle);
+			CL_HTTP_Reset ();
 		}
 	}
 }
