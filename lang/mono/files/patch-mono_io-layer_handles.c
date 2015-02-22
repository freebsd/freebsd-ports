--- mono/io-layer/handles.c.orig	2015-02-19 22:47:35.161952462 -0500
+++ mono/io-layer/handles.c	2015-02-19 22:50:12.224936078 -0500
@@ -225,6 +225,9 @@
 		  == WAPI_HANDLE_COUNT);
 	
 	_wapi_fd_reserve = getdtablesize();
+	/* If the file number is over a million we tend to see SIGSEGV */
+	if ( _wapi_fd_reserve > 1000000 )
+		_wapi_fd_reserve = 1000000;
 
 	/* This is needed by the code in _wapi_handle_new_internal */
 	_wapi_fd_reserve = (_wapi_fd_reserve + (_WAPI_HANDLE_INITIAL_COUNT - 1)) & ~(_WAPI_HANDLE_INITIAL_COUNT - 1);
