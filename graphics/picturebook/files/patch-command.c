--- command.c.old	Wed Aug  2 01:15:04 2000
+++ command.c	Thu Oct 16 07:21:39 2003
@@ -112,7 +112,7 @@
 
 	avi_start(fd);
 
-	printf("capturing %3.1f seconds to %s\n", captime, fname);
+	fprintf(stderr, "capturing %3.1f seconds to %s\n", captime, fname);
 
 	mchip_set_framerate(framerate);
 
@@ -123,11 +123,11 @@
 		double t1 = timer_end();
 		n = mchip_cont_compression_read(buf, sizeof(buf));
 		avi_add(fd, buf, n);
-		printf("."); fflush(stdout); 
+		fprintf(stderr, "."); fflush(stdout); 
 		frame_delay(framerate, t1);
 	}
 	avi_end(fd, mchip_hsize(), mchip_vsize(), i/timer_end());
-	printf("\ncaptured %d frames\n", i);
+	fprintf(stderr, "\ncaptured %d frames\n", i);
 	close(fd);
 }
 
@@ -146,7 +146,7 @@
 		f = find_next_file("snap.%d.jpg");
 		write_file(f, img, n);
 		display_image(f);
-		printf("captured to %s\n", f);
+		fprintf(stderr, "captured to %s\n", f);
 		while (spic_capture_pressed()) sdelay(1);
 	} else {
 		char *f;
@@ -171,12 +171,12 @@
 				timer_start();
 			}
 			frames++;
-			printf("."); fflush(stdout);
+			fprintf(stderr, "."); fflush(stdout);
 		} while (spic_capture_pressed());
 		avi_end(fd, mchip_hsize(), mchip_vsize(), 
 			frames/timer_end());
 		close(fd);
-		printf("\ncaptured %d frames to %s\n", frames, f);
+		fprintf(stderr, "\ncaptured %d frames to %s\n", frames, f);
 		display_image(NULL);
 	}
 }
@@ -197,11 +197,11 @@
 
 	mchip_continuous_start();
 
-	printf("
-started snap mode
- press capture button to take photo
- rotate jogger to change mode
- press jogger to exit
+	printf("\n\
+started snap mode\n\
+ press capture button to take photo\n\
+ rotate jogger to change mode\n\
+ press jogger to exit\n\
 \n");
 
 	sdelay(100);
