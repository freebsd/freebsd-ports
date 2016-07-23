--- iozone.c.orig	2015-10-20 14:12:13 UTC
+++ iozone.c
@@ -360,7 +360,7 @@ typedef off_t off64_t;
 #ifndef SCO_Unixware_gcc
 #ifndef UWIN
 #ifndef __DragonFly__
-typedef long long off64_t;
+typedef int64_t off64_t;
 #endif
 #endif
 #endif
@@ -1918,7 +1918,7 @@ char **argv;
 #ifdef NO_PRINT_LLD
 			sscanf(optarg,"%ld",&kilobytes64);
 #else
-			sscanf(optarg,"%lld",&kilobytes64);
+			sscanf(optarg,"%ld",&kilobytes64);
 #endif
 			if(optarg[strlen(optarg)-1]=='k' ||
 				optarg[strlen(optarg)-1]=='K'){
@@ -1942,7 +1942,7 @@ char **argv;
 #ifdef NO_PRINT_LLD
 	    		sprintf(splash[splash_line++],"\tFile size set to %ld kB\n",kilobytes64);
 #else
-	    		sprintf(splash[splash_line++],"\tFile size set to %lld kB\n",kilobytes64);
+	    		sprintf(splash[splash_line++],"\tFile size set to %ld kB\n",kilobytes64);
 #endif
 			sflag++;
 			break;
@@ -2316,7 +2316,7 @@ char **argv;
 #ifdef NO_PRINT_LLD
 			sprintf(splash[splash_line++],"\tUsing minimum file size of %ld kilobytes.\n",minimum_file_size);
 #else
-			sprintf(splash[splash_line++],"\tUsing minimum file size of %lld kilobytes.\n",minimum_file_size);
+			sprintf(splash[splash_line++],"\tUsing minimum file size of %ld kilobytes.\n",minimum_file_size);
 #endif
 			break;
 		case 'g':	/* Set maximum file size for auto mode */
@@ -2339,7 +2339,7 @@ char **argv;
 #ifdef NO_PRINT_LLD
 			sprintf(splash[splash_line++],"\tUsing maximum file size of %ld kilobytes.\n",maximum_file_size);
 #else
-			sprintf(splash[splash_line++],"\tUsing maximum file size of %lld kilobytes.\n",maximum_file_size);
+			sprintf(splash[splash_line++],"\tUsing maximum file size of %ld kilobytes.\n",maximum_file_size);
 #endif
 			break;
 		case 'z':	/* Set no cross over */
@@ -2447,7 +2447,7 @@ char **argv;
 					#ifdef NO_PRINT_LLD
 						sscanf(subarg,"%ld",&burst_size_kb_64);
 					#else
-						sscanf(subarg,"%lld",&burst_size_kb_64);
+						sscanf(subarg,"%ld",&burst_size_kb_64);
 					#endif
 					if(subarg[strlen(subarg)-1]=='k' ||
 						subarg[strlen(subarg)-1]=='K'){
@@ -3108,7 +3108,7 @@ char **argv;
 		printf("\tBurst size set to %ld Kbytes.\n\tBurst sleep duration set to %ld msec\n",
 		burst_size_kb_64, burst_sleep_duration_msec);
 #else
-		printf("\tBurst size set to %lld Kbytes.\n\tBurst sleep duration set to %lld msec\n",
+		printf("\tBurst size set to %ld Kbytes.\n\tBurst sleep duration set to %lld msec\n",
 		burst_size_kb_64, burst_sleep_duration_msec);
 #endif
 	if(!rflag)
@@ -3345,7 +3345,7 @@ long long reclength;
 		if(!silent) printf("%8ld",reclen/1024);
 	}
 #else
-	if(!silent) printf("%16lld",kilobytes64);
+	if(!silent) printf("%16ld",kilobytes64);
 	if(r_traj_flag || w_traj_flag)
 	{
 		if(!silent) printf("%8lld",(long long )0);
@@ -3403,7 +3403,7 @@ long long reclength;
 	    	printf("\n\tiozone %ld %ld ", kilobytes64,  goodrecl);
 	    	printf("\t(i.e. record size = %ld bytes)\n",  goodrecl);
 #else
-	    	printf("\n\tiozone %lld %lld ", kilobytes64,  goodrecl);
+	    	printf("\n\tiozone %ld %lld ", kilobytes64,  goodrecl);
 	    	printf("\t(i.e. record size = %lld bytes)\n",  goodrecl);
 #endif
 	   }
@@ -3543,7 +3543,7 @@ void auto_test()
             printf("Error: record length %ld is greater than filesize %ld kB\n ",
                                 min_rec_size,min_file_size);
 #else
-            printf("Error: record length %lld is greater than filesize %lld kB\n ",
+            printf("Error: record length %lld is greater than filesize %ld kB\n ",
                                 min_rec_size,min_file_size);
 #endif
                 exit(23);
@@ -3738,7 +3738,7 @@ throughput_test()
 	if(!silent) printf("\tEach %s writes a %ld kByte file in telemetry controlled records\n",
 		port,kilobytes64);
 #else
-	if(!silent) printf("\tEach %s writes a %lld kByte file in telemetry controlled records\n",
+	if(!silent) printf("\tEach %s writes a %ld kByte file in telemetry controlled records\n",
 		port,kilobytes64);
 #endif
 	}
@@ -3748,7 +3748,7 @@ throughput_test()
 	if(!silent) printf("\tEach %s writes a %ld kByte file in %ld kbyte records\n",
 		port,kilobytes64,reclen/1024);
 #else
-	if(!silent) printf("\tEach %s writes a %lld kByte file in %lld kByte records\n",
+	if(!silent) printf("\tEach %s writes a %ld kByte file in %lld kByte records\n",
 		port,kilobytes64,reclen/1024);
 #endif
 	}
@@ -7182,8 +7182,8 @@ char sverify;
 	printf("where %8.8lx loop %ld\n",where,i);
 #else
 	printf("Error in file: Found ?%llx? Expecting ?%llx? addr %lx\n",*where, (long long)((pattern_buf<<32)|pattern_buf),((long)where));
-	printf("Error in file: Position %lld \n",file_position);
-	printf("Record # %lld Record size %lld kb \n",recnum,recsize/1024);
+	printf("Error in file: Position %ld \n",file_position);
+	printf("Record # %ld Record size %lld kb \n",recnum,recsize/1024);
 	printf("where %px loop %lld\n",where,(long long)i);
 #endif
 		   return(1);
@@ -7226,9 +7226,9 @@ char sverify;
 	printf("Error in file: Position %ld \n",file_position);
 	printf("Record # %ld Record size %ld kb \n",recnum,recsize/1024);
 #else
-	printf("Error in file: Position %lld %lld %lld \n",i,j,k);
-	printf("Error in file: Position %lld \n",file_position);
-	printf("Record # %lld Record size %lld kb \n",recnum,recsize/1024);
+	printf("Error in file: Position %ld %lld %lld \n",i,j,k);
+	printf("Error in file: Position %ld \n",file_position);
+	printf("Record # %ld Record size %lld kb \n",recnum,recsize/1024);
 #endif
 	printf("Found pattern: Char >>%c<< Expecting >>%c<<\n", *where2,*pattern_ptr);
 	printf("Found pattern: Hex >>%x<< Expecting >>%x<<\n", *where2,*pattern_ptr);
@@ -7835,9 +7835,9 @@ long long *data2;
 				else
 				fprintf(rwqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((qtime_stop-qtime_start-time_res))*1000000,reclen);
 #else
-				fprintf(wqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((qtime_stop-qtime_start-time_res))*1000000,reclen);
+				fprintf(wqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((qtime_stop-qtime_start-time_res))*1000000,reclen);
 				else
-				fprintf(rwqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((qtime_stop-qtime_start-time_res))*1000000,reclen);
+				fprintf(rwqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((qtime_stop-qtime_start-time_res))*1000000,reclen);
 #endif
 			}
 			w_traj_ops_completed++;
@@ -8331,7 +8331,7 @@ long long *data1,*data2;
 				printf("\nError freading block %lu %lx\n", i,
 					(unsigned long long)buffer);
 #else
-				printf("\nError freading block %llu %llx\n", i,
+				printf("\nError freading block %ld %llx\n", i,
 					(unsigned long long)buffer);
 #endif
 #else
@@ -8678,7 +8678,7 @@ long long *data1,*data2;
 			}
 			if(r_traj_flag)
 			{
-				traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&compute_time, (long)0);
+				traj_offset=get_traj(r_traj_fd, &traj_size, &compute_time, 0);
 				reclen=traj_size;
 #if defined(Windows)
 			if(unbuffered)
@@ -8749,7 +8749,7 @@ long long *data1,*data2;
 				printf("\nError reading block %ld %lx\n", i,
 					(unsigned long long)nbuff);
 #else
-				printf("\nError reading block %lld %llx\n", i,
+				printf("\nError reading block %ld %llx\n", i,
 					(unsigned long long)nbuff);
 #endif
 #else
@@ -8798,9 +8798,9 @@ long long *data1,*data2;
 				else
 				fprintf(rrqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,(qtime_stop-qtime_start-time_res)*1000000,reclen);
 #else
-				fprintf(rqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,(qtime_stop-qtime_start-time_res)*1000000,reclen);
+				fprintf(rqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,(qtime_stop-qtime_start-time_res)*1000000,reclen);
 				else
-				fprintf(rrqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,(qtime_stop-qtime_start-time_res)*1000000,reclen);
+				fprintf(rrqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,(qtime_stop-qtime_start-time_res)*1000000,reclen);
 #endif
 			}
 			r_traj_ops_completed++;
@@ -9226,7 +9226,7 @@ long long *data1, *data2;
 				 printf("\nError reading block at %ld\n",
 					 offset64); 
 #else
-				 printf("\nError reading block at %lld\n",
+				 printf("\nError reading block at %ld\n",
 					 offset64); 
 #endif
 				 perror("read");
@@ -9350,7 +9350,7 @@ long long *data1, *data2;
 						printf("\nError writing block at %ld\n",
 							offset64); 
 #else
-						printf("\nError writing block at %lld\n",
+						printf("\nError writing block at %ld\n",
 							offset64); 
 #endif
 						if(wval==-1)
@@ -9667,7 +9667,7 @@ long long *data1,*data2;
 #ifdef NO_PRINT_LLD
 					printf("\nError reading block %ld\n", i); 
 #else
-					printf("\nError reading block %lld\n", i); 
+					printf("\nError reading block %ld\n", i); 
 #endif
 					perror("read");
 					exit(79);
@@ -10272,8 +10272,8 @@ long long *data1, *data2;
 		    		printf("\nError reading block %ld, fd= %d Filename %s Read returned %ld\n", i, fd,filename,uu);
 		    		printf("\nSeeked to %ld Reclen = %ld\n", savepos64,reclen);
 #else
-		    		printf("\nError reading block %lld, fd= %d Filename %s Read returned %lld\n", i, fd,filename,uu);
-		    		printf("\nSeeked to %lld Reclen = %lld\n", savepos64,reclen);
+		    		printf("\nError reading block %ld, fd= %d Filename %s Read returned %lld\n", i, fd,filename,uu);
+		    		printf("\nSeeked to %ld Reclen = %lld\n", savepos64,reclen);
 #endif
 				perror("read");
 		    		exit(88);
@@ -11799,7 +11799,7 @@ long long who;
 #ifdef NO_PRINT_LLD
 		if(!silent) printf("  %c%ld%c",'"',rec_size/1024,'"');
 #else
-		if(!silent) printf("  %c%lld%c",'"',rec_size/1024,'"');
+		if(!silent) printf("  %c%ld%c",'"',rec_size/1024,'"');
 #endif
 	}
 	if(!silent) printf("\n");
@@ -11817,7 +11817,7 @@ long long who;
 #ifdef NO_PRINT_LLD
 	if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #else
-	if(!silent) printf("%c%lld%c  ",'"',current_file_size,'"');
+	if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #endif
 	for(i=0;i<=max_y;i++){
 		if(report_array[0][i] != current_file_size){
@@ -11832,7 +11832,7 @@ long long who;
 #ifdef NO_PRINT_LLD
 			if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #else
-			if(!silent) printf("%c%lld%c  ",'"',current_file_size,'"');
+			if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #endif
 		}
 		if(bif_flag)
@@ -11840,7 +11840,7 @@ long long who;
 #ifdef NO_PRINT_LLD
 		if(!silent) printf(" %ld ",report_array[who][i]);
 #else
-		if(!silent) printf(" %lld ",report_array[who][i]);
+		if(!silent) printf(" %ld ",report_array[who][i]);
 #endif
 	}
 	if(bif_flag)
@@ -12029,7 +12029,7 @@ long long who;
 #ifdef NO_PRINT_LLD
 		if(!silent) printf("  %c%ld%c",'"',rec_size/1024,'"');
 #else
-		if(!silent) printf("  %c%lld%c",'"',rec_size/1024,'"');
+		if(!silent) printf("  %c%ld%c",'"',rec_size/1024,'"');
 #endif
 	}
 	if(!silent) printf("\n");
@@ -12047,7 +12047,7 @@ long long who;
 #ifdef NO_PRINT_LLD
 	if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #else
-	if(!silent) printf("%c%lld%c  ",'"',current_file_size,'"');
+	if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #endif
 	for (i = 0; i <= max_y; i++) {
 		if (report_array[0][i] != current_file_size) {
@@ -12062,7 +12062,7 @@ long long who;
 #ifdef NO_PRINT_LLD
 			if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #else
-			if(!silent) printf("%c%lld%c  ",'"',current_file_size,'"');
+			if(!silent) printf("%c%ld%c  ",'"',current_file_size,'"');
 #endif
 		}
 		if (bif_flag)
@@ -13061,7 +13061,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
 			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-			fprintf(thread_wqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
 		}
 		w_traj_ops_completed++;
@@ -13715,7 +13715,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
 			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-			fprintf(thread_wqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
 		}
 		w_traj_ops_completed++;
@@ -14325,7 +14325,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
 			fprintf(thread_rwqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-			fprintf(thread_rwqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+			fprintf(thread_rwqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
 		}
 		if(rlocking)
@@ -14764,7 +14764,7 @@ thread_read_test(x)
 		}
 		if(r_traj_flag)
 		{
-			traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&delay,(long)0);
+			traj_offset=get_traj(r_traj_fd, &traj_size, &delay, 0);
 			reclen=traj_size;
 #if defined(Windows)
 			if(unbuffered)
@@ -14840,7 +14840,7 @@ thread_read_test(x)
 		    		printf("\nError reading block %ld, fd= %d\n", i,
 					 fd);
 #else
-		    		printf("\nError reading block %lld, fd= %d\n", i,
+		    		printf("\nError reading block %ld, fd= %d\n", i,
 					 fd);
 #endif
 				perror("read");
@@ -14914,7 +14914,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
                         fprintf(thread_rqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-                        fprintf(thread_rqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+                        fprintf(thread_rqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
                 }
 
@@ -15317,7 +15317,7 @@ thread_pread_test(x)
 		}
 		if(r_traj_flag)
 		{
-			traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&delay,(long)0);
+			traj_offset=get_traj(r_traj_fd, &traj_size, &delay, 0);
 			reclen=traj_size;
 			I_LSEEK(fd,traj_offset,SEEK_SET);
 		}
@@ -15375,7 +15375,7 @@ thread_pread_test(x)
 		    		printf("\nError preading block %ld, fd= %d\n", i,
 					 fd);
 #else
-		    		printf("\nError preading block %lld, fd= %d\n", i,
+		    		printf("\nError preading block %ld, fd= %d\n", i,
 					 fd);
 #endif
 				perror("pread");
@@ -15449,7 +15449,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
                         fprintf(thread_rqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-                        fprintf(thread_rqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+                        fprintf(thread_rqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
                 }
 
@@ -15877,7 +15877,7 @@ thread_rread_test(x)
 		}
 		if(r_traj_flag)
 		{
-			traj_offset=get_traj(r_traj_fd, (long long *)&traj_size,(float *)&delay,(long)0);
+			traj_offset=get_traj(r_traj_fd, &traj_size, &delay, 0);
 			reclen=traj_size;
 #if defined(Windows)
 			if(unbuffered)
@@ -15953,7 +15953,7 @@ thread_rread_test(x)
 		    		printf("\nError writing block %ld, fd= %d\n", i,
 					 fd);
 #else
-		    		printf("\nError writing block %lld, fd= %d\n", i,
+		    		printf("\nError writing block %ld, fd= %d\n", i,
 					 fd);
 #endif
 				perror("read");
@@ -16027,7 +16027,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
                         fprintf(thread_rrqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-                        fprintf(thread_rrqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+                        fprintf(thread_rrqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
                 }
 
@@ -16503,7 +16503,7 @@ thread_reverse_read_test(x)
 #ifdef NO_PRINT_LLD
 				printf("\nError reading block %ld\n", i); 
 #else
-				printf("\nError reading block %lld\n", i); 
+				printf("\nError reading block %ld\n", i); 
 #endif
 				perror("read");
 				if (!no_unlink)
@@ -16585,7 +16585,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
                         fprintf(thread_revqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-                        fprintf(thread_revqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+                        fprintf(thread_revqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
                 }
 	}
@@ -17013,7 +17013,7 @@ thread_stride_read_test(x)
 #ifdef NO_PRINT_LLD
 		    		printf("\nError reading block %ld, fd= %d\n", i, fd);
 #else
-		    		printf("\nError reading block %lld, fd= %d\n", i, fd);
+		    		printf("\nError reading block %ld, fd= %d\n", i, fd);
 #endif
 				perror("read");
 				if (!no_unlink)
@@ -17130,7 +17130,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
                         fprintf(thread_strqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-                        fprintf(thread_strqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+                        fprintf(thread_strqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
                 }
 	}
@@ -17736,7 +17736,7 @@ thread_ranread_test(x)
 				printf("\nError reading block at %ld\n",
 					 offset); 
 #else
-				printf("\nError reading block at %lld\n",
+				printf("\nError reading block at %ld\n",
 					 offset); 
 #endif
 				perror("ranread");
@@ -17814,7 +17814,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
                         fprintf(thread_randrfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-                        fprintf(thread_randrfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+                        fprintf(thread_randrfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
                 }
 	}
@@ -18492,7 +18492,7 @@ printf("Desired rate %g  Actual rate %g 
 #ifdef NO_PRINT_LLD
 			fprintf(thread_randwqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-			fprintf(thread_randwqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+			fprintf(thread_randwqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
 		}
 		w_traj_ops_completed++;
@@ -18744,13 +18744,7 @@ void *x;
 	pthread_attr_t attr;
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
 
 
@@ -18769,8 +18763,8 @@ void *x;
 		printf("Thread create failed. Returned %d Errno = %d\n",xx,errno);
 	if(debug1 )
 	{
-		printf("\nthread created has an id of %lx\n",ts);
-		printf("meme %ld\n",meme);
+		printf("\nthread created has an id of %p\n", ts);
+		printf("meme %lld\n", (long long)meme);
 	}
 	return((long long)meme);
 }
@@ -22166,7 +22160,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_write_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_write_test((long)0);
+		thread_write_test(NULL);
 		break;
 #ifdef HAVE_PREAD
 	case THREAD_PWRITE_TEST : 
@@ -22175,7 +22169,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_pwrite_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_pwrite_test((long)0);
+		thread_pwrite_test(NULL);
 		break;
 #endif
 	case THREAD_REWRITE_TEST : 
@@ -22184,7 +22178,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_rewrite_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_rwrite_test((long)0);
+		thread_rwrite_test(NULL);
 		break;
 	case THREAD_READ_TEST : 
 		if(cdebug>=1)
@@ -22192,7 +22186,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_read_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_read_test((long)0);
+		thread_read_test(NULL);
 		break;
 #ifdef HAVE_PREAD
 	case THREAD_PREAD_TEST : 
@@ -22201,7 +22195,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_read_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_pread_test((long)0);
+		thread_pread_test(NULL);
 		break;
 #endif
 	case THREAD_REREAD_TEST : 
@@ -22210,7 +22204,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_reread_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_rread_test((long)0);
+		thread_rread_test(NULL);
 		break;
 	case THREAD_STRIDE_TEST : 
 		if(cdebug>=1)
@@ -22218,7 +22212,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_stride_read_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_stride_read_test((long)0);
+		thread_stride_read_test(NULL);
 		break;
 	case THREAD_RANDOM_READ_TEST : 
 		if(cdebug>=1)
@@ -22226,7 +22220,7 @@ become_client()
 			fprintf(newstdout,"Child %d running random read test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_ranread_test((long)0);
+		thread_ranread_test(NULL);
 		break;
 	case THREAD_RANDOM_WRITE_TEST : 
 		if(cdebug>=1)
@@ -22234,7 +22228,7 @@ become_client()
 			fprintf(newstdout,"Child %d running random write test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_ranwrite_test((long)0);
+		thread_ranwrite_test(NULL);
 		break;
 	case THREAD_REVERSE_READ_TEST : 
 		if(cdebug>=1)
@@ -22242,7 +22236,7 @@ become_client()
 			fprintf(newstdout,"Child %d running reverse read test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_reverse_read_test((long)0);
+		thread_reverse_read_test(NULL);
 		break;
 	case THREAD_RANDOM_MIX_TEST : 
 		if(cdebug>=1)
@@ -22250,7 +22244,7 @@ become_client()
 			fprintf(newstdout,"Child %d running mixed workload test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_mix_test((long)0);
+		thread_mix_test(NULL);
 		break;
 	case THREAD_FWRITE_TEST : 
 		if(cdebug>=1)
@@ -22258,7 +22252,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_fwrite_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_fwrite_test((long)0);
+		thread_fwrite_test(NULL);
 		break;
 	case THREAD_FREAD_TEST : 
 		if(cdebug>=1)
@@ -22266,7 +22260,7 @@ become_client()
 			fprintf(newstdout,"Child %d running thread_fread_test\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_fread_test((long)0);
+		thread_fread_test(NULL);
 		break;
 	case THREAD_CLEANUP_TEST : 
 		if(cdebug>=1)
@@ -22274,7 +22268,7 @@ become_client()
 			fprintf(newstdout,"Child %d running cleanup\n",(int)chid);
 			fflush(newstdout);
 		}
-		thread_cleanup_test((long)0);
+		thread_cleanup_test(NULL);
 		break;
 	};
 	if(cdebug>=1)
@@ -23009,7 +23003,7 @@ char *shell;
 #ifdef _HPUX_SOURCE
 	strcpy(shell,"remsh");
 #else
-	strcpy(shell,"rsh");
+	strcpy(shell,"ssh");
 #endif
 	return;
 }	
@@ -25030,7 +25024,7 @@ void * thread_fwrite_test( x)
 #ifdef NO_PRINT_LLD
 			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-			fprintf(thread_wqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
 		}
                 w_traj_ops_completed++;
@@ -25489,7 +25483,7 @@ void * thread_fread_test( x)
 #ifdef NO_PRINT_LLD
 			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1ld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #else
-			fprintf(thread_wqfd,"%10.1lld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
+			fprintf(thread_wqfd,"%10.1ld %10.0f %10.1lld\n",(traj_offset)/1024,((thread_qtime_stop-thread_qtime_start-time_res))*1000000,reclen);
 #endif
 		}
                 w_traj_ops_completed++;
