--- rf/utoolbar.cpp.orig	2002-06-15 19:49:37.000000000 +0200
+++ rf/utoolbar.cpp	2007-11-14 00:09:12.000000000 +0100
@@ -736,14 +736,14 @@
 		delete m_winInfo;
 }
 
-int UToolbar::UDispatchMessage(int/*UEventType*/ evt, int arg1, void *arg2, UDispatchInfo & dispatchInfo)
+int UToolbar::UDispatchMessage(int/*UEventType*/ evt, int arg1, const void *arg2, UDispatchInfo & dispatchInfo)
 {
 	if(evt == EV_CMD)
 	{
 		WININFO *info = m_winInfo;
 		if(info != 0L)
 		{
-			int index;
+			int index = 0;
 			std::vector<TbEntry *>::iterator f = info->Search(arg1, &index);
 			if(f != info->entries.end())
 			{
@@ -772,7 +772,7 @@
 	if(info == 0L)
 		return;
 
-	int index;
+	int index = 0;
 	std::vector<TbEntry *>::iterator f = info->Search(cmd, &index);
 	if(f == info->entries.end())
 		return;
