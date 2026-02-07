https://bugzilla.libsdl.org/show_bug.cgi?id=1427
https://hg.libsdl.org/SDL/rev/57a55e457ef6

--- src/video/x11/SDL_x11video.c.orig	2012-01-19 06:30:06 UTC
+++ src/video/x11/SDL_x11video.c
@@ -418,16 +418,21 @@ static void create_aux_windows(_THIS)
     }
 
 	{
-		pid_t pid = getpid();
+		union align_pid {
+			pid_t pid;
+			long dummy;
+		} a_pid;
 		char hostname[256];
+		
+		a_pid.pid = getpid();
 
-		if (pid > 0 && gethostname(hostname, sizeof(hostname)) > -1) {
+		if (a_pid.pid > 0 && gethostname(hostname, sizeof(hostname)) > -1) {
 			Atom _NET_WM_PID = XInternAtom(SDL_Display, "_NET_WM_PID", False);
 			Atom WM_CLIENT_MACHINE = XInternAtom(SDL_Display, "WM_CLIENT_MACHINE", False);
 			
 			hostname[sizeof(hostname)-1] = '\0';
 			XChangeProperty(SDL_Display, WMwindow, _NET_WM_PID, XA_CARDINAL, 32,
-					PropModeReplace, (unsigned char *)&pid, 1);
+					PropModeReplace, (unsigned char *)&(a_pid.pid), 1);
 			XChangeProperty(SDL_Display, WMwindow, WM_CLIENT_MACHINE, XA_STRING, 8,
 					PropModeReplace, (unsigned char *)hostname, SDL_strlen(hostname));
 		}
