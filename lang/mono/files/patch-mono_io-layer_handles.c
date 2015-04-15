--- mono/io-layer/handles.c.orig	2015-03-11 23:10:27.670052907 -0400
+++ mono/io-layer/handles.c	2015-03-11 23:11:40.239046159 -0400
@@ -244,6 +244,9 @@
 		  == WAPI_HANDLE_COUNT);
 
 	_wapi_fd_reserve = wapi_getdtablesize ();
+	/* This being very large causes SIGSEGV on FreeBSD */
+	if ( _wapi_fd_reserve > 5000 )
+		_wapi_fd_reserve = 5000;
 
 	/* This is needed by the code in _wapi_handle_new_internal */
 	_wapi_fd_reserve = (_wapi_fd_reserve + (_WAPI_HANDLE_INITIAL_COUNT - 1)) & ~(_WAPI_HANDLE_INITIAL_COUNT - 1);
