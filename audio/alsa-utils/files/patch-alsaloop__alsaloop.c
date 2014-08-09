--- alsaloop/alsaloop.c~
+++ alsaloop/alsaloop.c
@@ -760,7 +761,11 @@ static void thread_job1(void *_data)
 			snd_output_printf(output, "pool took %lius\n", timediff(tv2, tv1));
 		}
 		if (err < 0) {
+#ifdef ERESTART
 			if (err == -EINTR || err == -ERESTART)
+#else
+			if (err == -EINTR)
+#endif
 				continue;
 			logit(LOG_CRIT, "Poll failed: %s\n", strerror(-err));
 			my_exit(thread, EXIT_FAILURE);
