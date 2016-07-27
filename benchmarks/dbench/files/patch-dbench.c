--- dbench.c.orig	2008-02-18 00:49:35 UTC
+++ dbench.c
@@ -304,7 +304,7 @@ static void create_procs(int nprocs, voi
 				exit(1);
 			}
 
-			semctl(barrier,0,IPC_RMID);
+			//semctl(barrier,0,IPC_RMID);
 
 			fn(&children[i*options.clients_per_process], options.loadfile);
 			_exit(0);
@@ -334,7 +334,7 @@ static void create_procs(int nprocs, voi
 		exit(1);
 	}
 
-	semctl(barrier,0,IPC_RMID);
+	//semctl(barrier,0,IPC_RMID);
 
 	signal(SIGALRM, sig_alarm);
 	alarm(PRINT_FREQ);
