--- mono/io-layer/handles.c.orig	2015-01-12 12:15:08.000000000 -0500
+++ mono/io-layer/handles.c	2015-03-05 16:07:37.826119000 -0500
@@ -244,6 +244,8 @@
 		  == WAPI_HANDLE_COUNT);
 
 	_wapi_fd_reserve = wapi_getdtablesize ();
+	if ( _wapi_fd_reserve > 10000 )
+	  _wapi_fd_reserve = 9999;
 
 	/* This is needed by the code in _wapi_handle_new_internal */
 	_wapi_fd_reserve = (_wapi_fd_reserve + (_WAPI_HANDLE_INITIAL_COUNT - 1)) & ~(_WAPI_HANDLE_INITIAL_COUNT - 1);
