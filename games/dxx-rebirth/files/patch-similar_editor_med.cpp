--- similar/editor/med.cpp.orig	2018-11-21 18:28:30 UTC
+++ similar/editor/med.cpp
@@ -891,7 +891,7 @@ static void close_editor()
 {
 	//	_MARK_("end of editor");//Nuked to compile -KRB
 	
-#if !defined(__linux__) && !defined(__OpenBSD__)
+#if !defined(__linux__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 	set_warn_func(msgbox_warning);
 #else
 	clear_warn_func();
