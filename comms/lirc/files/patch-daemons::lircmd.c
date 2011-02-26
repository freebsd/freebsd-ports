--- daemons/lircmd.c.orig
+++ daemons/lircmd.c
@@ -277,9 +277,9 @@ setup_error:
 	return -1;
 }
 
+#ifdef __linux__
 void write_uinput(__u16 type, __u16 code, __s32 value)
 {
-#ifdef __linux__
 	struct input_event event;
 
 	memset(&event, 0, sizeof(event));
@@ -299,8 +299,8 @@ void write_uinput(__u16 type, __u16 code
 			syslog(LOG_ERR, "%m");
 		}
 	}
-#endif
 }
+#endif
 
 void msend(int dx, int dy, int dz, int rep, int buttp, int buttr)
 {
