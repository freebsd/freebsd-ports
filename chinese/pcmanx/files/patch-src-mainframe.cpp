--- src/mainframe.cpp.orig	Tue Oct 11 02:46:46 2005
+++ src/mainframe.cpp	Tue Oct 11 02:47:07 2005
@@ -1033,7 +1033,7 @@
 		child_pid = fork();
 		if (child_pid == 0)
 		{
-			int t_nRet = system("wget -O ~/.pcmanx/sitelist http://free.ym.edu.tw/pcman/site_list.utf8");
+			int t_nRet = system("fetch -o ~/.pcmanx/sitelist http://free.ym.edu.tw/pcman/site_list.utf8");
 			if (t_nRet == 0)
 				kill(parent_pid, SIGUSR1);
 			else
