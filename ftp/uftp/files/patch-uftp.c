--- uftp.c.orig	2008-12-19 03:56:50.000000000 +0300
+++ uftp.c	2008-12-22 18:39:33.000000000 +0300
@@ -180,7 +180,7 @@ void announce()
         continue;
       }
       if (header->tx_id!=txID) {
-        logfunc(applog,0,0,0,0,"Invalid txID: %08lX, should be %08lX\n",header->tx_id,txID);
+        logfunc(applog,0,0,0,0,"Invalid txID: %08X, should be %08X\n",header->tx_id,txID);
         abort_msg("Invalid txID",&sin);
         continue;
       }
@@ -361,7 +361,7 @@ int getnaks(int pass, int section)
         continue;
       }
       if (header->tx_id!=txID) {
-        logfunc(applog,0,0,0,0,"Invalid txID: %08lX, should be %08lX\n",header->tx_id,txID);
+        logfunc(applog,0,0,0,0,"Invalid txID: %08X, should be %08X\n",header->tx_id,txID);
         continue;
       }
       if (header->func==ABORT) {
@@ -411,7 +411,7 @@ int getnaks(int pass, int section)
           } else if (gotdest[i]==1) {
             found=-1;
           } else {
-            logfunc(applog,0,0,0,0,"Got %ld NAKs for pass %ld section %ld from %s\n",header->nak_count,header->pass,header->section_num,destlist[i].name);
+            logfunc(applog,0,0,0,0,"Got %d NAKs for pass %d section %d from %s\n",header->nak_count,header->pass,header->section_num,destlist[i].name);
             if ((header->pass==pass)&&(header->section_num==section)) {
               gotdest[i]=1;
               destlist[i].naks+=header->nak_count;
@@ -501,8 +501,8 @@ void xfer()
   } else {
     weight_time=(int)floor(((double)weight/100)*((double)filesize/(rate/8)/1024));
     max_time=(weight_time>min_time)?weight_time:min_time;
-    logfunc(applog,0,0,0,0,"Transfer rate: %ld Kbps (%ld KB/s)\n",rate,rate/8);
-    logfunc(applog,0,0,0,0,"Wait between packets: %ld %cs\n",wait,MICRO);
+    logfunc(applog,0,0,0,0,"Transfer rate: %d Kbps (%d KB/s)\n",rate,rate/8);
+    logfunc(applog,0,0,0,0,"Wait between packets: %d %cs\n",wait,MICRO);
   }
   logfunc(applog,0,0,0,0,"Maximum file transfer time: %d seconds\n",max_time);
   aborted=0;
@@ -576,7 +576,7 @@ void xfer()
             break;
           }
           if (verbose>=2)
-            logfunc(applog,0,0,0,0,"Resending %ld\n",i);
+            logfunc(applog,0,0,0,0,"Resending %d\n",i);
           if ((offset=lseek_func(file,((f_offset_t)i*BLOCKSIZE)-prev_offset,SEEK_CUR))==-1) {
             logfunc(applog,0,1,errno,0,"lseek failed for file");
             continue;
@@ -584,9 +584,9 @@ void xfer()
           if (offset!=(f_offset_t)i*BLOCKSIZE) {
             logfunc(applog,0,0,0,0,"sizeof f_offset_t = %d\n",sizeof(f_offset_t));
             if (sizeof(f_offset_t)>4)
-              logfunc(applog,0,0,0,0,"block %ld: offset is %s, should be %s\n",i,printll(offset),printll((f_offset_t)i*BLOCKSIZE));
+              logfunc(applog,0,0,0,0,"block %d: offset is %s, should be %s\n",i,printll(offset),printll((f_offset_t)i*BLOCKSIZE));
             else
-              logfunc(applog,0,0,0,0,"block %ld: offset is %ld, should be %ld\n",i,offset,(f_offset_t)i*BLOCKSIZE);
+              logfunc(applog,0,0,0,0,"block %d: offset is %ld, should be %ld\n",i,offset,(f_offset_t)i*BLOCKSIZE);
             continue;
           }
           if ((numbytes=read(file,data,BLOCKSIZE))==-1) {
@@ -624,7 +624,7 @@ void xfer()
     numnaks+=getnaks(header->pass=pass,header->section_num);
     gettimestamp(w1);
     logfunc(applog,0,0,0,0,"average wait time = %.2f %cs\n",(count==0)?0:(float)avg/count,MICRO);
-    logfunc(applog,0,0,0,0,"Received %ld distinct NAKs for pass %d\n",numnaks,pass);
+    logfunc(applog,0,0,0,0,"Received %d distinct NAKs for pass %d\n",numnaks,pass);
     pass++;
   } while (numnaks);
   close(file);
@@ -892,7 +892,7 @@ int main(int argc, char *argv[])
     logfunc(applog,0,0,0,0,"Bytes: %s  Blocks: %d  Sections: %d\n",printll(filesize),numblocks,numsections);
   else
     logfunc(applog,0,0,0,0,"Bytes: %d  Blocks: %d  Sections: %d\n",filesize,numblocks,numsections);
-  logfunc(applog,0,0,0,0,"Using private multicast address %s  id %08lX\n",inet_ntoa(receive_dest.sin_addr),txID);
+  logfunc(applog,0,0,0,0,"Using private multicast address %s  id %08X\n",inet_ntoa(receive_dest.sin_addr),txID);
   if (rate==-1) {
     wait=0;
   } else {
