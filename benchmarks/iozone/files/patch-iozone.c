Fix warnings from modern compilers -- formats, use of 0 instead of NULL.
Also remove redundant casts and fix printf-formatting.

	-mi
--- iozone.c	2015-10-20 14:12:13.000000000 +0000
+++ iozone.c
@@ -8679,5 +8679,5 @@
 			if(r_traj_flag)
 			{
-				traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&compute_time, (long)0);
+				traj_offset=get_traj(r_traj_fd, &traj_size, &compute_time, 0);
 				reclen=traj_size;
 #if defined(Windows)
@@ -14765,5 +14765,5 @@
 		if(r_traj_flag)
 		{
-			traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&delay,(long)0);
+			traj_offset=get_traj(r_traj_fd, &traj_size, &delay, 0);
 			reclen=traj_size;
 #if defined(Windows)
@@ -15318,5 +15318,5 @@
 		if(r_traj_flag)
 		{
-			traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&delay,(long)0);
+			traj_offset=get_traj(r_traj_fd, &traj_size, &delay, 0);
 			reclen=traj_size;
 			I_LSEEK(fd,traj_offset,SEEK_SET);
@@ -15878,5 +15878,5 @@
 		if(r_traj_flag)
 		{
-			traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&delay,(long)0);
+			traj_offset=get_traj(r_traj_fd, &traj_size, &delay, 0);
 			reclen=traj_size;
 #if defined(Windows)
@@ -18745,11 +18745,5 @@
 	int xx;
 	int *yy;
-#ifdef _64BIT_ARCH_
-	long long meme;
-	meme = (long long)x;
-#else
-	long meme;
-	meme = (long)x;
-#endif
+	intptr_t meme = (intptr_t)x;
 	yy=(int *)x;
 
@@ -18770,6 +18764,6 @@
 	if(debug1 )
 	{
-		printf("\nthread created has an id of %lx\n",ts);
-		printf("meme %ld\n",meme);
+		printf("\nthread created has an id of %p\n", ts);
+		printf("meme %lld\n", (long long)meme);
 	}
 	return((long long)meme);
@@ -22167,5 +22161,5 @@
 			fflush(newstdout);
 		}
-		thread_write_test((long)0);
+		thread_write_test(NULL);
 		break;
 #ifdef HAVE_PREAD
@@ -22176,5 +22170,5 @@
 			fflush(newstdout);
 		}
-		thread_pwrite_test((long)0);
+		thread_pwrite_test(NULL);
 		break;
 #endif
@@ -22185,5 +22179,5 @@
 			fflush(newstdout);
 		}
-		thread_rwrite_test((long)0);
+		thread_rwrite_test(NULL);
 		break;
 	case THREAD_READ_TEST : 
@@ -22193,5 +22187,5 @@
 			fflush(newstdout);
 		}
-		thread_read_test((long)0);
+		thread_read_test(NULL);
 		break;
 #ifdef HAVE_PREAD
@@ -22202,5 +22196,5 @@
 			fflush(newstdout);
 		}
-		thread_pread_test((long)0);
+		thread_pread_test(NULL);
 		break;
 #endif
@@ -22211,5 +22205,5 @@
 			fflush(newstdout);
 		}
-		thread_rread_test((long)0);
+		thread_rread_test(NULL);
 		break;
 	case THREAD_STRIDE_TEST : 
@@ -22219,5 +22213,5 @@
 			fflush(newstdout);
 		}
-		thread_stride_read_test((long)0);
+		thread_stride_read_test(NULL);
 		break;
 	case THREAD_RANDOM_READ_TEST : 
@@ -22227,5 +22221,5 @@
 			fflush(newstdout);
 		}
-		thread_ranread_test((long)0);
+		thread_ranread_test(NULL);
 		break;
 	case THREAD_RANDOM_WRITE_TEST : 
@@ -22235,5 +22229,5 @@
 			fflush(newstdout);
 		}
-		thread_ranwrite_test((long)0);
+		thread_ranwrite_test(NULL);
 		break;
 	case THREAD_REVERSE_READ_TEST : 
@@ -22243,5 +22237,5 @@
 			fflush(newstdout);
 		}
-		thread_reverse_read_test((long)0);
+		thread_reverse_read_test(NULL);
 		break;
 	case THREAD_RANDOM_MIX_TEST : 
@@ -22251,5 +22245,5 @@
 			fflush(newstdout);
 		}
-		thread_mix_test((long)0);
+		thread_mix_test(NULL);
 		break;
 	case THREAD_FWRITE_TEST : 
@@ -22259,5 +22253,5 @@
 			fflush(newstdout);
 		}
-		thread_fwrite_test((long)0);
+		thread_fwrite_test(NULL);
 		break;
 	case THREAD_FREAD_TEST : 
@@ -22267,5 +22261,5 @@
 			fflush(newstdout);
 		}
-		thread_fread_test((long)0);
+		thread_fread_test(NULL);
 		break;
 	case THREAD_CLEANUP_TEST : 
@@ -22275,5 +22269,5 @@
 			fflush(newstdout);
 		}
-		thread_cleanup_test((long)0);
+		thread_cleanup_test(NULL);
 		break;
 	};
