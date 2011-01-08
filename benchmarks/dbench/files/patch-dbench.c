--- ./dbench.c.orig	2011-01-07 14:33:29.000000000 +0000
+++ ./dbench.c	2011-01-07 14:36:43.000000000 +0000
@@ -304,7 +304,7 @@
 				exit(1);
 			}
 
-			semctl(barrier,0,IPC_RMID);
+			//semctl(barrier,0,IPC_RMID);
 
 			fn(&children[i*options.clients_per_process], options.loadfile);
 			_exit(0);
@@ -334,7 +334,7 @@
 		exit(1);
 	}
 
-	semctl(barrier,0,IPC_RMID);
+	//semctl(barrier,0,IPC_RMID);
 
 	signal(SIGALRM, sig_alarm);
 	alarm(PRINT_FREQ);
