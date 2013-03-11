--- source/screen.c.orig	2011-04-29 17:21:18.000000000 +0900
+++ source/screen.c	2013-03-12 00:08:32.423090823 +0900
@@ -2416,6 +2416,10 @@
 	{
 		screen_type = ST_SCREEN;
 	}
+	else if (0 != getenv("TMUX"))
+	{
+		screen_type = ST_TMUX;
+	}
 	else if ((char *) 0 != (displayvar = getenv("DISPLAY")))
 	{
 		if ((char *) 0 == (termvar = getenv("TERM")))
@@ -2454,6 +2458,7 @@
 	say("Opening new %s...",
 		screen_type == ST_XTERM ?  "window" :
 		screen_type == ST_SCREEN ? "screen" :
+		screen_type == ST_TMUX ?   "tmux window" :
 					   "wound" );
 	snprintf(sock.sun_path, sizeof sock.sun_path, "/tmp/irc_%08d_%x", (int) pid, mycycle);
 	sock.sun_family = AF_UNIX;
@@ -2569,6 +2574,22 @@
 			args[i] = NULL;
 			execvp(xterm, args);
 		}
+		else if (screen_type == ST_TMUX)
+		{
+			char	*args[64],
+				*ss,
+				*t,
+				opts[BIG_BUFFER_SIZE];
+
+			Debug((3, "going to execvp screen wserv..."));
+			args[i++] = "tmux";
+			args[i++] = "new-window";
+			snprintf(opts, BIG_BUFFER_SIZE-1, "%s %s %s", WSERV_PATH, sockaddr->sun_path, error_sockaddr->sun_path);
+			args[i++] = opts;
+			Debug((3, "added: %s %s '%s'", args[i-3], args[i-2], args[i-1]));
+			args[i++] = NULL;
+			execvp("tmux", args);
+		}
 		perror("execve");
 		unlink(sockaddr->sun_path);
 		unlink(error_sockaddr->sun_path);
