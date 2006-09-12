--- lsetad.c.orig	Tue Aug 15 15:27:44 2006
+++ lsetad.c	Mon Sep 11 15:46:13 2006
@@ -39,7 +39,7 @@
 #define ABOVE_MAX_SPEED 768000
 #if SND_DEV == 1
 #define DEVNAME_BASE "/dev/dsp"
-#else 
+#else
 #define DEVNAME_BASE "/dev/sound/dsp"
 #endif
 
@@ -83,15 +83,12 @@
 sdr=-1;
 }
 
-
 void display_sdi(void)
 {
 FILE *sdifile;
-int  ch_cnt;
-char ch_read[80];
+char *p;
 char work_line [80];
-int  work_line_pos ; 
-int  sdi_screen_line_counter; 
+int  sdi_screen_line_counter;
 char sdi_intro_msg [26]= "SOUND DRIVER INFORMATION:" ;
 char sdi_error_msg [46]= "No OSS or ALSA sound-driver information found";
 char sndstat_filename [25];
@@ -111,59 +108,46 @@
 // if OSS not active, try  ALSA
 if (sdifile==NULL)
   {
-  strcpy (sndstat_filename,"/proc/asound/oss/sndstat");   
-  sdifile=fopen (sndstat_filename,"r"); 
-  }
-if (sdifile==NULL) 
-  {
-  settextcolor(LIGHT_RED); 
-  lir_text ( 80, sdi_screen_line_counter++, sdi_error_msg);
-  fprintf (sndlog,"\n%s",sdi_error_msg ); 
-  goto display_sdi_x;
+  strcpy (sndstat_filename,"/proc/asound/oss/sndstat");
+  sdifile=fopen (sndstat_filename,"r");
   }
-fprintf (sndlog,"\n(output of 'cat %s' command): \n\n",sndstat_filename );
-memset (work_line, '\0',sizeof(work_line));
-work_line_pos =0; 
-settextcolor(LIGHT_GREEN);
-ch_cnt=fread(ch_read,1,1,sdifile);
-while (ch_cnt== 1)
+if (sdifile!=NULL)
   {
-// check if work_line is ready for output processing
-  if ((ch_read[0] =='\n') || (work_line_pos == 78))
+  fprintf (sndlog,"\n(output of 'cat %s' command): \n\n",sndstat_filename );
+  settextcolor(LIGHT_GREEN);
+  while(fgets(work_line, sizeof(work_line)-1, sdifile) != NULL)
     {
+// check if work_line is ready for output processing
+    p=strchr(work_line, '\n');
+    if(p != NULL)p[0]=0;
+    if (*work_line != '\0')
+      {
 // display work_line only if it is not blank
 // and there are enough lines available on the screen
 // and there are at least 40 characters available on a line
-    if ((work_line_pos >1) && 
-       ( sdi_screen_line_counter < screen_last_line) &&  
-       ((screen_last_col - 40)>= 80))
-      {
-      if (ch_read[0] !='\n') work_line[work_line_pos]=ch_read[0]; 
-      sdi_screen_line_counter++;
-      lir_text (80, sdi_screen_line_counter, work_line);
-      }
+      if (sdi_screen_line_counter < screen_last_line &&
+                                               (screen_last_col - 40)>= 80)
+        {
+        sdi_screen_line_counter++;
+        lir_text (80, sdi_screen_line_counter, work_line);
+        }
 // write  to soundboard_init.log
-    if (ch_read[0] =='\n')  work_line[work_line_pos]=ch_read[0]; 
-    if (ch_read[0] !='\n') 
-      {
-// this is a truncated line. Add newline character
-      work_line[work_line_pos]=ch_read[0]; 
-      work_line[work_line_pos+1]='\n';
-      }
-    fprintf (sndlog,"%s",work_line); 
-    memset (work_line, '\0',sizeof(work_line));   
-    work_line_pos=-1;
-    }
-  work_line[work_line_pos]=ch_read[0]; 
-  work_line_pos++;
-  ch_cnt=fread(ch_read,1,1,sdifile);
+      fprintf (sndlog,"%s\n",work_line);
+      }
+    }
+  fclose(sdifile);
+  }
+else
+  {
+  settextcolor(LIGHT_RED);
+  lir_text ( 80, sdi_screen_line_counter++, sdi_error_msg);
+  fprintf (sndlog,"\n%s",sdi_error_msg );
   }
-fclose(sdifile);
-display_sdi_x:;
 fprintf(sndlog,sndlog_sep);
 fflush(sndlog);
 }
 
+
 void clear_sdi(void)
 {
 int x, w;
@@ -209,6 +193,8 @@
         thread_status_flag[THREAD_SCREEN]!=THRFLAG_IDLE &&
         thread_status_flag[THREAD_SCREEN]!=THRFLAG_SEM_WAIT)
     {
+    if(thread_command_flag[THREAD_RX_ADINPUT] == 
+                                           THRFLAG_KILL)goto rxadin_error_exit;
     lir_sleep(10000);
     }
   }
@@ -239,7 +225,7 @@
     }
 #endif
   if(hware_flag != 0)
-    {    
+    {
     dt1=current_time();
     if(dt1 - hware_time > 0.005)
       {
@@ -265,7 +251,7 @@
       measured_ad_speed=total_reads*ad_read_fragments/dt1;
       }
     }
-// Here we post to the screen routine every 0.1 second.      
+// Here we post to the screen routine every 0.1 second.
   screen_loop_counter--;
   if(screen_loop_counter == 0)
     {
@@ -304,8 +290,8 @@
         rxin_int[4*i+2]=rxin_int2[2*i  ];
         rxin_int[4*i+3]=rxin_int2[2*i+1];
         }
-      }    
-    }    
+      }
+    }
   if(network_flag == 1)
     {
     if(network_modeno == 1)
@@ -321,14 +307,14 @@
         }
       write(network_sockfd, rxin_isho, ad_read_bytes);
       }
-    }  
+    }
   finish_rx_read(rxin_isho);
   if(kill_all_flag) goto rxadin_error_exit;
   }
-rxadin_error_exit:;  
+rxadin_error_exit:;
 while( audio_out == audio_in)lir_sleep(10000);
-close_rx_sndin();  
-rx_adin_init_error:;  
+close_rx_sndin();
+rx_adin_init_error:;
 thread_status_flag[THREAD_RX_ADINPUT]=THRFLAG_RETURNED;
 while(thread_command_flag[THREAD_RX_ADINPUT] != THRFLAG_NOT_ACTIVE)
   {
@@ -360,7 +346,7 @@
   lir_sleep(3000);
   i++;
   if(i<10)goto buftest;
-  }  
+  }
 i=da_totbytes-da_info.bytes;
 i/=(da_output_channels*da_output_bytes);
 return i;
@@ -375,13 +361,13 @@
 for(i=0; i<daout_block; i++)da_wrbuf[i]=0;
 write(audio_out,da_wrbuf,daout_block);
 if(ioctl(audio_out,SNDCTL_DSP_GETOSPACE, &da_info) == -1)lirerr(errcod);
-} 
+}
 
 
 void lir_empty_da_device_buffer(void)
 {
 int i;
-if( audio_out == -1) 
+if( audio_out == -1)
   {
   open_rx_sndout();
   if(kill_all_flag) return;
@@ -402,7 +388,7 @@
   if(da_info.fragstotal - da_info.fragments <= 4)
     {
     write(audio_out,da_wrbuf,daout_block);
-    } 
+    }
   if(ioctl(audio_out,SNDCTL_DSP_RESET,0)==-1)
     {
     if(ui.da_stopstart == 0)
@@ -470,7 +456,7 @@
   if(i<25)goto buftest;
   err_restart_da(23855);
   if(kill_all_flag) return;
-  }  
+  }
 write(audio_out,da_wrbuf,daout_block);
 }
 
@@ -490,11 +476,11 @@
   lirerr(9236);
   return;
   }
-if (n+2 == MAX_DEVNAMES) 
+if (n+2 == MAX_DEVNAMES)
   {
   sprintf(dev_name, "%s", DEVNAME_BASE);
-  } 
-else 
+  }
+else
   {
   sprintf(dev_name, "%s%d", DEVNAME_BASE, n);
   }
@@ -525,6 +511,11 @@
 if(i&AFMT_S16_LE)ui.max_output_bytes=2;
 ui.max_output_speed=ABOVE_MAX_SPEED;
 ui.min_output_speed=1;
+//
+// To allow a separate #ifdef __FreeBSD__
+// - Diane Bruce VA3DB, Sept 6, 2006
+//
+#ifdef __linux__
 if(ioctl(audio_out, SNDCTL_DSP_SPEED, &ui.max_output_speed) == -1)
   {
   lirerr(1072);
@@ -535,7 +526,8 @@
   lirerr(1073);
   return;
   }
-if(ui.max_output_speed==ABOVE_MAX_SPEED || 
+#endif
+if(ui.max_output_speed==ABOVE_MAX_SPEED ||
    ui.min_output_speed <= 1 ||
    ui.max_output_speed < ui.min_output_speed)
   {
@@ -592,7 +584,7 @@
   i>>=1;
   frag++;
   }
-if(frag < 4)frag=4;  
+if(frag < 4)frag=4;
 frag|=0x7fff0000;
 return frag;
 }
@@ -614,7 +606,7 @@
     free(da_wrbuf);
     da_wrbuf=NULL;
     }
-  }  
+  }
 audio_out=-1;
 }
 
@@ -623,7 +615,7 @@
 float t1;
 int i, j, frag;
 audio_buf_info ad_info;
-if( disksave_flag == 2 || 
+if( disksave_flag == 2 ||
     network_flag == 2 ||
     ui.ad_device_no == SDR14_DEVICE_CODE ||
     ( (ui.input_mode&NO_DUPLEX) != 0 && audio_out != -1) )
@@ -632,7 +624,7 @@
   }
 if( (audio_in) != -1)
   {
-  if( ui.ad_device_mode == O_RDWR)return;    
+  if( ui.ad_device_mode == O_RDWR)return;
   lirerr(100031);
   return;
   }
@@ -662,22 +654,22 @@
   i>>=1;
   frag++;
   }
-if(frag < 4)frag=4;  
+if(frag < 4)frag=4;
 if(ui.ad_device_no > 255)
   {
   frag--;
-  if(frag < 4)frag=4;  
+  if(frag < 4)frag=4;
   frag=frag|0x7fff0000;
   if(ioctl(audio_in2, SNDCTL_DSP_SETFRAGMENT, &frag) == -1)
     {
-    lirerr(1175);  
+    lirerr(1175);
     return;
     }
   }
 frag=frag|0x7fff0000;
 if(ioctl(audio_in, SNDCTL_DSP_SETFRAGMENT, &frag) == -1)
   {
-  lirerr(1008);  
+  lirerr(1008);
   return;
   }
 i=AFMT_S16_LE;
@@ -721,7 +713,7 @@
 i=j;
 if(ioctl(audio_in, SNDCTL_DSP_CHANNELS, &i) == -1)
   {
-  lirerr(1009);  
+  lirerr(1009);
   return;
   }
 if(i != j)
@@ -734,7 +726,7 @@
   i=j;
   if(ioctl(audio_in2, SNDCTL_DSP_CHANNELS, &i) == -1)
     {
-    lirerr(1178);  
+    lirerr(1178);
     return;
     }
   if(i != j)
@@ -791,7 +783,7 @@
   i=PCM_ENABLE_INPUT;
   if(ioctl(audio_in2,SNDCTL_DSP_SETTRIGGER,&i)==-1)
     {
-    lirerr(1184); 
+    lirerr(1184);
     return;
     }
   }
@@ -814,7 +806,7 @@
     }
   }
 ioctl(audio_in,SNDCTL_DSP_GETBLKSIZE,&i);
-}  
+}
 
 
 
@@ -854,7 +846,7 @@
     }
   }
 // *******************************************
-if(ui.ad_device_no == ui.da_device_no && 
+if(ui.ad_device_no == ui.da_device_no &&
    ui.ad_device_mode == O_RDWR &&
    network_flag != 2)
   {
@@ -887,7 +879,7 @@
       {
       lirerr(1191);
       }
-    else  
+    else
       {
       lirerr(1017);
       }
@@ -907,7 +899,7 @@
   i=da_output_channels;
   if(ioctl(audio_out, SNDCTL_DSP_CHANNELS, &i) == -1)
     {
-    lirerr(1019);  
+    lirerr(1019);
     return;
     }
   if(i != da_output_channels)
@@ -923,7 +915,7 @@
     {
     i=AFMT_S16_LE;
     }
-  j=i;    
+  j=i;
   if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &i) == -1)
     {
     lirerr(1020);
@@ -957,7 +949,7 @@
   lirerr(1025);
   return;
   }
-for(i=0; i<daout_block; i++)da_wrbuf[i]=0;  
+for(i=0; i<daout_block; i++)da_wrbuf[i]=0;
 ioctl(audio_out, SNDCTL_DSP_GETBLKSIZE,&i);
 if(ioctl(audio_out,SNDCTL_DSP_GETOSPACE, &da_info) == -1)err_restart_da(1149);
 da_totbytes=da_info.fragstotal*da_info.fragsize;
@@ -1010,7 +1002,7 @@
 return 0;
 }
 
-int find_output_devices(int line, int *dev_flag, int *dev_wr_bits, 
+int find_output_devices(int line, int *dev_flag, int *dev_wr_bits,
           int *dev_wr_channels, int *dev_max_wr_speed, int *dev_min_wr_speed)
 {
 char s[80];
@@ -1039,7 +1031,7 @@
       dev_wr_bits[device_no]=0;
       }
     else
-      {  
+      {
       SNDLOG"\n8-bit output supported");
       dev_wr_bits[device_no]=8;
       }
@@ -1047,7 +1039,7 @@
 // We simply assume that all cards that can do 16 bit are capable
 // of doing 8 bit as well.
     j=AFMT_S16_LE;
-    if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1  || j != AFMT_S16_LE) 
+    if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1  || j != AFMT_S16_LE)
       {
       SNDLOG"\nCould not set 16-bit output");
       }
@@ -1058,7 +1050,7 @@
     SNDLOG"\n16-bit output supported");
     sndlog_sync();
     if(dev_wr_bits[device_no]==0) goto errdev;
-    sndlog_sync();  
+    sndlog_sync();
     j=2;
     if(ioctl(audio_out, SNDCTL_DSP_CHANNELS, &j) == -1)
       {
@@ -1077,6 +1069,11 @@
     SNDLOG"\nNo of output channels= %d",j);
     sndlog_sync();
     dev_wr_channels[device_no]=j;
+//
+// To allow a separate #ifdef __FreeBSD__
+// - Diane Bruce VA3DB, Sept 6, 2006
+//
+#ifdef __linux__
     j=ABOVE_MAX_SPEED;
     if(ioctl(audio_out, SNDCTL_DSP_SPEED, &j) == -1 || j==ABOVE_MAX_SPEED)
       {
@@ -1087,7 +1084,7 @@
         SNDLOG"\nioctl(SPEED) failed");
         goto errdev;
         }
-      }    
+      }
     dev_max_wr_speed[device_no]=j;
     SNDLOG"\nMax output speed %d", dev_max_wr_speed[device_no]);
     j=1;
@@ -1099,28 +1096,50 @@
         SNDLOG"\nioctl(SPEED) failed");
        goto errdev;
         }
-      }    
+      }
     dev_min_wr_speed[device_no]=j;
     SNDLOG"\nMin output speed %d", dev_min_wr_speed[device_no]);
     sndlog_sync();
+#endif
+//
+// This code finds min max speed of sound card for FreeBSD
+// It probably works for other BSDs as well
+// Diane Bruce, db@db.net VA3DB
+// Sept 7, 2006
+//
+#ifdef __FreeBSD__
+      {
+      snd_capabilities capab;
+      int status;
+      bzero((void *)&capab, sizeof(capab));
+      status = ioctl(audio_out, AIOGCAP, &capab);
+      if (status < 0)goto errdev;
+      dev_min_wr_speed[device_no] = capab.rate_min;
+      dev_max_wr_speed[device_no]= capab.rate_max;
+      ui.min_output_speed = capab.rate_min;
+      ui.max_output_speed = capab.rate_max;
+      SNDLOG"\nMax output speed %d", dev_max_wr_speed[device_no]);
+      SNDLOG"\nMin output speed %d", dev_min_wr_speed[device_no]);
+      }
+#endif
     if(close(audio_out)==-1)
       {
-      goto errdev;  
+      goto errdev;
       }
     sprintf(s,"%02d  %s  %7d - %7d Hz   %d Chan.   %d bit WRONLY",
                 device_no, dev_name,
-                dev_min_wr_speed[device_no], 
-                dev_max_wr_speed[device_no], 
-                dev_wr_channels[device_no], 
+                dev_min_wr_speed[device_no],
+                dev_max_wr_speed[device_no],
+                dev_wr_channels[device_no],
                 dev_wr_bits[device_no]);
     lir_text(0,n+2,s);
     n++;
-    ui.da_device_no=device_no;  
+    ui.da_device_no=device_no;
     dev_flag[device_no]=4;
     }
-  else 
+  else
     {
-skipdev:;    
+skipdev:;
     dev_flag[device_no]=0;
     sndlog_sync();
     }
@@ -1156,7 +1175,7 @@
 int speed_warning;
 int i, j, k, n, nn, cn, m, min, max, olbytes;
 int wrcnt;
-int rdwr_channels, caps;  
+int rdwr_channels, caps;
 int trySpeed, deltaSpeed;
 int rdwr_max_speed;
 int rdwr_min_speed;
@@ -1228,7 +1247,7 @@
       lir_text(5,13,press_any_key);
       await_keyboard();
       if(kill_all_flag) goto sdr14_errexit;
-      clear_screen();  
+      clear_screen();
       ui.ad_device_no=-1;
       }
     else
@@ -1300,7 +1319,7 @@
       parfile_end(sdr14_file);
       }
     }
-  else  
+  else
     {
     if(lir_inkey != 'N')goto qsdr;
     clear_screen();
@@ -1311,7 +1330,7 @@
 if(ui.ad_device_no == -1)
   {
 // look for other hardwares
-  }  
+  }
 if(ui.ad_device_no != -1)
   {
   if(ui.da_device_no == -1)
@@ -1331,8 +1350,8 @@
     {
     goto setad_x;
     }
-  }    
-// If none of the supported SDR hardwares is found, use the 
+  }
+// If none of the supported SDR hardwares is found, use the
 // sound cards for input and output.
 // ----------------------------------------------------------
 // First step through all devices and check which ones
@@ -1386,7 +1405,7 @@
         k=0;
         }
       else
-        {  
+        {
         SNDLOG"\n16bit format supported");
         }
 #ifdef AFMT_S32_LE
@@ -1400,8 +1419,8 @@
       else
         {
         SNDLOG"\n32bit format NOT supported");
-        }          
-#endif   
+        }
+#endif
       sndlog_sync();
       if(k == 0)goto cls;
 // Find max no of channels.
@@ -1423,8 +1442,13 @@
       else
         {
         SNDLOG"\nMax no of channels = %d",m);
-        }  
+        }
       sndlog_sync();
+//
+// To allow a separate #ifdef __FreeBSD__
+// - Diane Bruce VA3DB, Sept 6, 2006
+//
+#ifdef __linux__
 // Find maximum speed
       rdwr_max_speed=ABOVE_MAX_SPEED;
       if(ioctl(audio_out, SNDCTL_DSP_SPEED, &rdwr_max_speed)==-1)
@@ -1444,6 +1468,25 @@
       lirerr(1040);
       goto setad_errexit;
 minok:;
+#endif
+//
+// This code finds min max speed of sound card for FreeBSD
+// It probably works for other BSDs as well
+// Diane Bruce, db@db.net VA3DB
+// Sept 7, 2006
+//
+#ifdef __FreeBSD__
+        {
+        snd_capabilities capab;
+        int status;
+        bzero((void *)&capab, sizeof(capab));
+        status = ioctl(audio_out, AIOGCAP, &capab);
+        if (status < 0)goto setad_errexit;
+        rdwr_min_speed = capab.rate_min;
+        rdwr_max_speed = capab.rate_max;
+        SNDLOG"\nMax output speed %d", rdwr_max_speed);
+        }
+#endif
       SNDLOG"\nMin sampling speed = %d Hz",rdwr_min_speed);
       sndlog_sync();
       if(mode != 1)
@@ -1487,30 +1530,30 @@
           dev_min_rd_speed[device_no]=rdwr_min_speed;
           dev_rd_bits[device_no]=rdwr_fmt;
           break;
-          
+
           case 1:
           dev_wr_channels[device_no]=rdwr_channels;
           dev_max_wr_speed[device_no]=rdwr_max_speed;
           dev_min_wr_speed[device_no]=rdwr_min_speed;
           dev_wr_bits[device_no]=rdwr_fmt;
           break;
-          
+
           case 2:
           dev_rdwr_channels[device_no]=rdwr_channels;
           dev_max_rdwr_speed[device_no]=rdwr_max_speed;
           dev_min_rdwr_speed[device_no]=rdwr_min_speed;
           dev_rdwr_bits[device_no]=rdwr_fmt;
           break;
-          }  
+          }
         }
       SNDLOG"\n");
-      }          
-    }      
+      }
+    }
   if(dev_flag[device_no] != 0)
     {
   SNDLOG"\nFLAG= %d",dev_flag[device_no]);
 // One device may be different hardwares for input and output.
-// Put them on different lines if characteristics differ.    
+// Put them on different lines if characteristics differ.
     k=0;
     j=0;
 // Store equal pairs in k
@@ -1524,7 +1567,7 @@
          dev_max_rd_speed[device_no]==dev_max_wr_speed[device_no] &&
          dev_min_rd_speed[device_no]==dev_min_wr_speed[device_no] &&
          dev_rd_bits[device_no]==dev_wr_bits[device_no]) k|=1;
-      } 
+      }
     if( (dev_flag[device_no]&5) == 5)
       {
       j|=2;
@@ -1550,33 +1593,33 @@
         {
         sprintf(ss,"%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit",
                     device_no,dev_name,
-                    dev_min_rd_speed[device_no], 
-                    dev_max_rd_speed[device_no], 
-                    dev_max_rd_channels[device_no], 
+                    dev_min_rd_speed[device_no],
+                    dev_max_rd_speed[device_no],
+                    dev_max_rd_channels[device_no],
                     dev_rd_bits[device_no]);
         }
       else
-        {  
+        {
         if( (dev_flag[device_no]&2) == 2)
           {
           sprintf(ss,"%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit",
                      device_no,dev_name,
-                     dev_min_wr_speed[device_no], 
-                     dev_max_wr_speed[device_no], 
-                     dev_wr_channels[device_no], 
+                     dev_min_wr_speed[device_no],
+                     dev_max_wr_speed[device_no],
+                     dev_wr_channels[device_no],
                      dev_wr_bits[device_no]);
           }
         }
       for(j=0; j<3; j++)
         {
-        k=1<<j;  
+        k=1<<j;
         if( (dev_flag[device_no]&k) != 0)
           {
           column=0;
           while(ss[column]!=0)column++;
           sprintf(&ss[column],"  %s",devmode_txt[j]);
           }
-        }  
+        }
       if( (dev_flag[device_no]&5) == 0)
         {
         color=0x17;
@@ -1610,19 +1653,19 @@
           sprintf(&ss[maxcolumn],
                      "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
                       device_no,dev_name,
-                      dev_min_wr_speed[device_no], 
-                      dev_max_wr_speed[device_no], 
-                      dev_wr_channels[device_no], 
+                      dev_min_wr_speed[device_no],
+                      dev_max_wr_speed[device_no],
+                      dev_wr_channels[device_no],
                       dev_wr_bits[device_no],devmode_txt[1]);
           sprintf(ss,"%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
                       device_no,dev_name,
-                      dev_min_rd_speed[device_no], 
-                      dev_max_rd_speed[device_no], 
-                      dev_max_rd_channels[device_no], 
+                      dev_min_rd_speed[device_no],
+                      dev_max_rd_speed[device_no],
+                      dev_max_rd_channels[device_no],
                       dev_rd_bits[device_no],devmode_txt[0]);
           }
         else
-          {  
+          {
 // There is rdwr, read and write.
           if(k == 0)
             {
@@ -1632,23 +1675,23 @@
             sprintf(&ss[2*maxcolumn],
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
                       device_no,dev_name,
-                      dev_min_wr_speed[device_no], 
-                      dev_max_wr_speed[device_no], 
-                      dev_wr_channels[device_no], 
+                      dev_min_wr_speed[device_no],
+                      dev_max_wr_speed[device_no],
+                      dev_wr_channels[device_no],
                       dev_wr_bits[device_no],devmode_txt[1]);
             sprintf(&ss[maxcolumn],
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
                       device_no,dev_name,
-                      dev_min_rd_speed[device_no], 
-                      dev_max_rd_speed[device_no], 
-                      dev_max_rd_channels[device_no], 
+                      dev_min_rd_speed[device_no],
+                      dev_max_rd_speed[device_no],
+                      dev_max_rd_channels[device_no],
                       dev_rd_bits[device_no],devmode_txt[0]);
             sprintf(ss,
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
                       device_no,dev_name,
-                      dev_min_rdwr_speed[device_no], 
-                      dev_max_rdwr_speed[device_no], 
-                      dev_rdwr_channels[device_no], 
+                      dev_min_rdwr_speed[device_no],
+                      dev_max_rdwr_speed[device_no],
+                      dev_rdwr_channels[device_no],
                       dev_rdwr_bits[device_no],devmode_txt[2]);
             }
           else
@@ -1661,16 +1704,16 @@
               sprintf(&ss[maxcolumn],
                         "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
                         device_no,dev_name,
-                        dev_min_wr_speed[device_no], 
-                        dev_max_wr_speed[device_no], 
-                        dev_wr_channels[device_no], 
+                        dev_min_wr_speed[device_no],
+                        dev_max_wr_speed[device_no],
+                        dev_wr_channels[device_no],
                         dev_wr_bits[device_no],devmode_txt[1]);
               sprintf(ss,
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s  %s",
                         device_no,dev_name,
-                        dev_min_rd_speed[device_no], 
-                        dev_max_rd_speed[device_no], 
-                        dev_max_rd_channels[device_no], 
+                        dev_min_rd_speed[device_no],
+                        dev_max_rd_speed[device_no],
+                        dev_max_rd_channels[device_no],
                         dev_rd_bits[device_no],
                         devmode_txt[0],devmode_txt[2]);
               }
@@ -1680,24 +1723,24 @@
               sprintf(&ss[maxcolumn],
                         "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s  %s",
                         device_no,dev_name,
-                        dev_min_wr_speed[device_no], 
-                        dev_max_wr_speed[device_no], 
+                        dev_min_wr_speed[device_no],
+                        dev_max_wr_speed[device_no],
                         dev_wr_channels[device_no], dev_wr_bits[device_no],
                         devmode_txt[1],devmode_txt[2]);
               sprintf(ss,
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
                         device_no,dev_name,
-                        dev_min_rd_speed[device_no], 
-                        dev_max_rd_speed[device_no], 
-                        dev_max_rd_channels[device_no], 
+                        dev_min_rd_speed[device_no],
+                        dev_max_rd_speed[device_no],
+                        dev_max_rd_channels[device_no],
                         dev_rd_bits[device_no],
                         devmode_txt[0]);
               }
-            }  
+            }
           }
         }
       }
-    while (m >0)   
+    while (m >0)
       {
       m--;
       line++;
@@ -1715,15 +1758,15 @@
         bottom_line=maxline;
         line=1;
         }
-      settextcolor(color);  
+      settextcolor(color);
       column=0;
       while(ss[m*maxcolumn+column]!=0)column++;
       while(column < maxcolumn)
         {
         ss[m*maxcolumn+column]=' ';
-        column++; 
+        column++;
         }
-      ss[(m+1)*maxcolumn-1]=0;  
+      ss[(m+1)*maxcolumn-1]=0;
       lir_text(0,line,&ss[m*maxcolumn]);
       lir_refresh_screen();
       SNDLOG"\n%s    color=%d m=%d",&ss[m*maxcolumn],color,m);
@@ -1732,7 +1775,7 @@
     SNDLOG"\n");
     }
   }
-settextcolor(7);  
+settextcolor(7);
 line++;
 clear_lines(line,line);
 if(bottom_line > line)line=bottom_line;
@@ -1750,7 +1793,7 @@
   lir_text(0,line+10,
         "Sound board drivers are usually configured during Linux install");
   lir_text(20,line+12,press_any_key);
-  await_keyboard();  
+  await_keyboard();
   if(kill_all_flag) goto setad_errexit;
   SNDLOG"\nNo input device found");
   goto setad_errexit;
@@ -1761,7 +1804,7 @@
 get_addev:;
   settextcolor(14);
   lir_text(0,line,"Select device for input by first number on line");
-  display_sdi(); 
+  display_sdi();
   settextcolor(7);
   ui.ad_device_no=lir_get_integer(48, line, 3, 0,MAX_DEVNAMES-1);
   if(kill_all_flag)goto setad_errexit;
@@ -1802,7 +1845,7 @@
 // channels with the Lynx Two card (model A).
 // Do not confuse other users by asking for a second input device
 // unless the selected device has 32 bits but only allows 2 channels.
-if( dev_rd_bits[ui.ad_device_no] == 32 && 
+if( dev_rd_bits[ui.ad_device_no] == 32 &&
     dev_max_rd_channels[ui.ad_device_no]==2 &&
     (dev_flag[ui.ad_device_no]&1) != 0)
   {
@@ -1811,7 +1854,7 @@
   line=1;
   for(i=0; i<MAX_DEVNAMES; i++)
     {
-    if(i != ui.ad_device_no && 
+    if(i != ui.ad_device_no &&
        dev_max_rd_speed[i] == dev_max_rd_speed[ui.ad_device_no] &&
        dev_rd_bits[i] == 32 &&
        (dev_flag[i]&1) != 0)
@@ -1829,12 +1872,12 @@
         if(kill_all_flag) goto setad_errexit;
         if(lir_inkey == 'N')
           {
-          SNDLOG"\nUser skipped dual devices"); 
+          SNDLOG"\nUser skipped dual devices");
           goto skip_dual_devices;
           }
-        if(lir_inkey != 'Y')goto gt_dual;  
+        if(lir_inkey != 'Y')goto gt_dual;
         clear_screen();
-        SNDLOG"\nUser wants to try to open two read devices"); 
+        SNDLOG"\nUser wants to try to open two read devices");
         make_devname(ui.ad_device_no);
         audio_in=open( dev_name, O_RDONLY, 0);
         if(audio_in == -1)
@@ -1854,11 +1897,11 @@
           }
         if( (caps&DSP_CAP_TRIGGER) == 0)
           {
-          SNDLOG"\nDevice does not have DSP_CAP_TRIGGER"); 
+          SNDLOG"\nDevice does not have DSP_CAP_TRIGGER");
           close(audio_in);
           goto skip_dual_devices;
           }
-        j=2;  
+        j=2;
         if(ioctl(audio_in, SNDCTL_DSP_CHANNELS, &j) == -1)
           {
           lirerr(1185);
@@ -1882,9 +1925,9 @@
         SNDLOG"\n%s opened as second read device",dev_name);
         sprintf(s,"%2d:%12s  %7d - %7d Hz   %d Chan.   %d bit",
                 i,dev_name,
-                dev_min_rd_speed[i], 
-                dev_max_rd_speed[i], 
-                dev_max_rd_channels[i], 
+                dev_min_rd_speed[i],
+                dev_max_rd_speed[i],
+                dev_max_rd_channels[i],
                 dev_rd_bits[i]);
         lir_text(0,line,s);
         close(audio_in2);
@@ -1916,7 +1959,7 @@
   for(i=0; i<MAX_DEVNAMES; i++)
     {
     dev_flag[i]&=255;
-    }    
+    }
   audio_in2=open( dev_name, O_RDONLY|O_NONBLOCK, 0);
   if(audio_in2 == -1)
     {
@@ -1935,7 +1978,7 @@
     }
   if( (caps&DSP_CAP_TRIGGER) == 0)
     {
-    SNDLOG"\nSecond input device does not have DSP_CAP_TRIGGER"); 
+    SNDLOG"\nSecond input device does not have DSP_CAP_TRIGGER");
     close(audio_in);
     close(audio_in2);
     goto skip_dual_devices;
@@ -1959,8 +2002,8 @@
   {
   if( (1 & dev_flag[ui.ad_device_no]) != 0)
     {
-gt_rdo:;    
-    sprintf(s,"Open %s as RDONLY or RDWR? (O/W)  =>",dev_name);  
+gt_rdo:;
+    sprintf(s,"Open %s as RDONLY or RDWR? (O/W)  =>",dev_name);
     lir_text(10,10,s);
     await_processed_keyboard();
     if(kill_all_flag) goto setad_errexit;
@@ -1970,7 +2013,7 @@
     }
   else
     {
-rdwr:;    
+rdwr:;
     ui.ad_device_mode=O_RDWR;
     mode=2;
     SNDLOG"\nUser selected RDWR");
@@ -1981,7 +2024,7 @@
   SNDLOG"\nOnly RDONLY available");
   }
 sndlog_sync();
-clear_screen();  
+clear_screen();
 sprintf(s,"For analog input: %s opened in %s mode",dev_name,devmode_txt[mode]);
 lir_text(0,0,s);
 audio_in=open( dev_name, ui.ad_device_mode, 0);
@@ -2031,7 +2074,7 @@
   ui.rx_channels=1;
   ui.ad_channels=2;
   break;
-    
+
   case '3':
   ui.input_mode=TWO_CHANNELS;
   ui.rx_channels=2;
@@ -2288,7 +2331,7 @@
 sprintf(s,"Now trying to open a second device while %s is open",dev_name);
 lir_text(0,6,s);
 lir_text(0,7,"This may cause your system to hang. Try ctrlC to exit (or reboot)");
-lir_text(0,8,"Try another input device or install another sound system."); 
+lir_text(0,8,"Try another input device or install another sound system.");
 // Find devices that we may use for output.
 n=0;
 cn=0;
@@ -2314,16 +2357,16 @@
         dev_flag[i]=0;
         }
       else
-        {  
+        {
         sprintf(&s[column],"  %d Hz   %d Chan.   16 bit RDWR",
                                           ui.input_speed, ui.ad_channels);
         n++;
-        ui.da_device_no=i;  
+        ui.da_device_no=i;
         }
       }
     }
   else
-    { 
+    {
 // Remove duplex flags on all devices except the one we use for input
     dev_flag[i]&=0xffff-4;
     if( (dev_flag[i]&2) != 0 )
@@ -2331,7 +2374,7 @@
       audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
       if(read_test_ad(testbuff)!=0)goto clr_wrdev;
       if(audio_out != -1)
-        { 
+        {
 #ifdef SNDCTL_DSP_COOKEDMODE
         j=0;
         ioctl(audio_out, SNDCTL_DSP_COOKEDMODE, &j);
@@ -2351,13 +2394,13 @@
           dev_wr_bits[i]=0;
           }
         else
-          {  
+          {
           SNDLOG"\n8-bit output supported");
           dev_wr_bits[i]=8;
           }
        sndlog_sync();
        j=AFMT_S16_LE;
-        if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1  || j != AFMT_S16_LE) 
+        if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1  || j != AFMT_S16_LE)
           {
           SNDLOG"\nCould not set 16-bit output");
           }
@@ -2368,7 +2411,7 @@
         SNDLOG"\n16-bit output supported");
         sndlog_sync();
         if(dev_wr_bits[i]==0) goto skip_wr_dev;
-        sndlog_sync();  
+        sndlog_sync();
         j=2;
         if(ioctl(audio_out, SNDCTL_DSP_CHANNELS, &j) == -1)
           {
@@ -2397,7 +2440,7 @@
             SNDLOG"\nioctl(SPEED) failed");
             goto skip_wr_dev;
             }
-          }    
+          }
         dev_max_wr_speed[i]=j;
         SNDLOG"\nMax output speed %d", dev_max_wr_speed[i]);
         j=1;
@@ -2409,7 +2452,7 @@
             SNDLOG"\nioctl(SPEED) failed");
             goto skip_wr_dev;
             }
-          }    
+          }
         dev_min_wr_speed[i]=j;
         SNDLOG"\nMin output speed %d", dev_min_wr_speed[i]);
         sndlog_sync();
@@ -2426,7 +2469,7 @@
           SNDLOG"\nWrite failed");
           goto skip_wr_dev;
           }
-        sound_start_time=current_time();  
+        sound_start_time=current_time();
         wrcnt=0;
         j=ad_info.bytes;
         while(wrcnt+ad_info.bytes < 3*1024+j )
@@ -2438,7 +2481,7 @@
             SNDLOG"\nSNDCTL_DSP_GETOSPACE failed");
             goto skip_wr_dev;
             }
-          if( current_time() - sound_start_time > 0.7)  
+          if( current_time() - sound_start_time > 0.7)
             {
             SNDLOG"\nTimeout");
             goto skip_wr_dev;
@@ -2456,7 +2499,7 @@
           lirerr(1095);
           goto setad_errexit;
           }
-        olbytes=ad_info.bytes;       
+        olbytes=ad_info.bytes;
         gettimeofday(&tim2,NULL);
         while(ad_info.bytes-olbytes < 512)
           {
@@ -2475,31 +2518,31 @@
           }
         if(close(audio_out)==-1)
           {
-          goto skip_wr_dev;  
+          goto skip_wr_dev;
           }
         sprintf(&s[column]," %7d - %7d Hz   %d Chan.   %d bit WRONLY",
-                dev_min_wr_speed[i], 
-                dev_max_wr_speed[i], 
-                dev_wr_channels[i], 
+                dev_min_wr_speed[i],
+                dev_max_wr_speed[i],
+                dev_wr_channels[i],
                 dev_wr_bits[i]);
         cn=1;
         n++;
-        ui.da_device_no=i;  
+        ui.da_device_no=i;
         }
-      else 
+      else
         {
-        goto clr_wrdev;  
+        goto clr_wrdev;
 skip_wr_dev:;
         sndlog_sync();
         if(close(audio_out)==-1)
           {
-          lirerr(1067);  
+          lirerr(1067);
           goto setad_errexit;
           }
 clr_wrdev:;
         dev_flag[i]&=0xffff-2;
         }
-      }         
+      }
     }
   if(cn != 0)
     {
@@ -2542,7 +2585,7 @@
     while(s[column] != 0)column++;
     audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
     if(audio_out != -1)
-      { 
+      {
       #ifdef SNDCTL_DSP_COOKEDMODE
         j=0;
         ioctl(audio_out, SNDCTL_DSP_COOKEDMODE, &j);
@@ -2556,11 +2599,11 @@
         dev_wr_bits[i]=0;
         }
       else
-        {  
+        {
         dev_wr_bits[i]=8;
         }
       j=AFMT_S16_LE;
-      if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1  || j != AFMT_S16_LE) 
+      if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1  || j != AFMT_S16_LE)
         {
         SNDLOG"\nCould not set 16-bit output");
         }
@@ -2569,7 +2612,7 @@
         dev_wr_bits[i]=16;
         }
       if(dev_wr_bits[i]==0) goto skip_wr_dev_nodup;
-      sndlog_sync();  
+      sndlog_sync();
       j=2;
       if(ioctl(audio_out, SNDCTL_DSP_CHANNELS, &j) == -1)
         {
@@ -2597,7 +2640,7 @@
           SNDLOG"\nioctl(SPEED) failed");
           goto skip_wr_dev_nodup;
           }
-        }    
+        }
       dev_max_wr_speed[i]=j;
       SNDLOG"\nMax output speed %d", dev_max_wr_speed[i]);
       sndlog_sync();
@@ -2613,17 +2656,17 @@
         if(ioctl(audio_out,SNDCTL_DSP_GETOSPACE, &ad_info) == -1)
                                                goto skip_wr_dev_nodup;
         }
-      if(close(audio_out)==-1)goto skip_wr_dev_nodup;  
+      if(close(audio_out)==-1)goto skip_wr_dev_nodup;
       sprintf(&s[column]," %d Hz   %d Chan.   %d bit WRONLY",
               dev_max_wr_speed[i], dev_wr_channels[i], dev_wr_bits[i]);
       cn=1;
       n++;
-      ui.da_device_no=i;  
+      ui.da_device_no=i;
       dev_flag[i] |= 2;
       }
-    else 
+    else
       {
-      goto clr_wrdev_nodup;  
+      goto clr_wrdev_nodup;
 skip_wr_dev_nodup:;
       sndlog_sync();
       if(close(audio_out)==-1)
@@ -2655,10 +2698,10 @@
     lirerr(1139);
     goto setad_errexit;
     }
-  ui.input_mode|=NO_DUPLEX;  
+  ui.input_mode|=NO_DUPLEX;
   ad_info.bytes=0;
   }
-dadev_select:;  
+dadev_select:;
 if(n > 1)
   {
 get_dadev:;
@@ -2666,7 +2709,7 @@
   j=0;
   settextcolor(14);
   lir_text(0,line,"Select device for output by line number");
-  display_sdi(); 
+  display_sdi();
   settextcolor(7);
   while(i<2)
     {
@@ -2683,7 +2726,7 @@
     }
   ui.da_device_no=j;
 // Mod3:    Modified error message handling in get_dadev and get_addev
-  if( (6 & dev_flag[ui.da_device_no]) == 0) 
+  if( (6 & dev_flag[ui.da_device_no]) == 0)
     {
     settextcolor(15);
     lir_text(43,line,"???");
@@ -2693,10 +2736,10 @@
     clear_lines(line,line+1);
     goto get_dadev;
     }
-// -------------------------------------------------------  
+// -------------------------------------------------------
 // The original code was:
 // if( (6 & dev_flag[ui.da_device_no]) == 0) goto get_dadev;
-// -------------------------------------------------------  
+// -------------------------------------------------------
   }
 make_devname(ui.da_device_no);
 SNDLOG"\nUser selected %s for output.",dev_name);
@@ -2711,7 +2754,7 @@
   {
   ui.da_stopstart=1;
   }
-else  
+else
   {
   if(lir_inkey != 'N')goto get_da_stopstart;
   ui.da_stopstart=0;
@@ -2720,7 +2763,7 @@
 // If we selected the same device for input and output,
 // check if it was opened ad RDWR or if we shall open it
 // for output now
-if( ui.da_device_no == ui.ad_device_no && 
+if( ui.da_device_no == ui.ad_device_no &&
     ui.ad_device_mode == O_RDWR &&
     (ui.input_mode&NO_DUPLEX) == 0 )
   {
@@ -2751,20 +2794,20 @@
   close_rx_sndout();
   }
 close_rx_sndin();
-sprintf(s,"Min output channels: %d",ui.min_output_channels);  
+sprintf(s,"Min output channels: %d",ui.min_output_channels);
 lir_text(0,8,s);
-sprintf(s,"Max output channels: %d",ui.max_output_channels);  
+sprintf(s,"Max output channels: %d",ui.max_output_channels);
 lir_text(0,9,s);
 da_output_channels=ui.min_output_channels;
 da_output_bytes=ui.max_output_bytes;
-sprintf(s,"Output no of bits=%d",8*ui.max_output_bytes);  
+sprintf(s,"Output no of bits=%d",8*ui.max_output_bytes);
 lir_text(35,7,s);
 if(ui.max_output_bytes != ui.min_output_bytes)
   {
-  sprintf(s,"or %d",8*ui.min_output_bytes);  
+  sprintf(s,"or %d",8*ui.min_output_bytes);
   lir_text(56,7,s);
   }
-// Reopen with the current parameters. 
+// Reopen with the current parameters.
 // We will not goto setad_errexit here if something goes wrong.
 if(  (ui.input_mode&NO_DUPLEX) == 0 && ui.ad_device_no != SDR14_DEVICE_CODE)
   {
