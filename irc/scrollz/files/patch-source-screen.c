--- source/screen.c.orig	2021-05-06 08:04:55 UTC
+++ source/screen.c
@@ -2425,6 +2425,10 @@ create_additional_screen()
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
@@ -2463,6 +2467,7 @@ create_additional_screen()
 	say("Opening new %s...",
 		screen_type == ST_XTERM ?  "window" :
 		screen_type == ST_SCREEN ? "screen" :
+		screen_type == ST_TMUX ?   "tmux window" :
 					   "wound" );
 	snprintf(sock.sun_path, sizeof sock.sun_path, "/tmp/irc_%08d_%x", (int) pid, mycycle);
 	sock.sun_family = AF_UNIX;
@@ -2577,6 +2582,22 @@ create_additional_screen()
 			args[i++] = error_sockaddr->sun_path;
 			args[i] = NULL;
 			execvp(xterm, args);
+		}
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
 		}
 		perror("execve");
 		unlink(sockaddr->sun_path);
