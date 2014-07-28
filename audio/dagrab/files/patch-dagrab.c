--- dagrab.c.orig	Sat Feb 19 17:32:46 2000
+++ dagrab.c	Tue Nov 18 00:05:29 2003
@@ -94,26 +94,21 @@
 #include <string.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <getopt.h>
 #include <dirent.h>
 #include <netdb.h>
-#include <unistd.h>
 #include <pwd.h>
 #include <ctype.h>
-#define __need_timeval   /* needed by glibc */
-#include <time.h>
-#include <linux/cdrom.h>
-#ifdef USE_UCDROM
-#include <linux/ucdrom.h>
-#endif
-#include <sys/vfs.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <sys/cdio.h>
+#include <sys/cdrio.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #define CDDEVICE "/dev/cdrom"
-#define N_BUF 8
+#define N_BUF 12
 #define OVERLAP 2
 #define KEYLEN 12
 #define OFS 12
@@ -123,12 +118,18 @@
 #define D_MODE 0660
 #define CDDB_MAX  65535
 #define CDDB_PORT 888
+#ifndef CDDB_PATH
 #define CDDB_PATH "/usr/lib/X11/xmcd/cddb"
+#endif
 #define CDDB_HOST "freedb.freedb.org"
 //#define USE_CDDB (opt_save||opt_name)
 #define USE_CDDB opt_cddb
 #define PROGNAME "dagrab"
 #define VERSION "0.3.5"
+#define CD_MSF_OFFSET 150
+#define CDROM_DATA_TRACK 4
+#define CDROM_LEADOUT 0xaa
+#define CD_FRAMESIZE_RAW 2352
 #define KW_TRACK 0
 #define KW_FULLD 1
 #define KW_AUTHOR 2
@@ -206,16 +207,20 @@
 
 struct Wavefile cd_newave(unsigned size)
 {
-  struct Wavefile dummy={{'R','I','F','F'},0x24+size,{'W','A','V','E'},
-			 {'f','m','t',' '},0x10,1,2,44100,4*44100,4,16,
-			 {'d','a','t','a'},size };
-  /*dummy.Dlen=size;
-		  dummy.Rlen=0x24+size;*/
-  dummy.sample_rate = opt_srate;
-  dummy.channel = 2 - opt_mono;
-  dummy.byte_rate = opt_srate << dummy.channel;
-  dummy.align = dummy.channel * dummy.sample >> 3;
-  dummy.Dlen >>= opt_mono;
+  struct Wavefile dummy={{'R','I','F','F'},		/* Rid */
+			 0x24 + (size >> opt_mono),	/* Rlen */
+			 {'W','A','V','E'},		/* Wid */
+			 {'f','m','t',' '},		/* Fid */
+			 0x10,				/* Flen */
+			 1,				/* tag */
+			 2 - opt_mono,			/* channel */
+			 opt_srate,			/* sample_rate */
+			 opt_srate << (2 - opt_mono),	/* byte_rate */
+			 16 * (2 - opt_mono) >> 3,	/* align */
+			 16,				/* sample */
+			 {'d','a','t','a'},		/* Did */
+			 size >> opt_mono		/* Dlen */
+			 };
   return dummy;
 }
 
@@ -226,16 +231,16 @@
   return buf;
 }
 
-int cd_get_tochdr(struct cdrom_tochdr *Th)
+int cd_get_tochdr(struct ioc_toc_header *Th)
 {
-	return ioctl(cdrom_fd,CDROMREADTOCHDR,Th);
+	return ioctl(cdrom_fd,CDIOREADTOCHEADER,Th);
 }
 
-int cd_get_tocentry(int trk,struct cdrom_tocentry *Te,int mode)
+int cd_get_tocentry(int trk,struct ioc_read_toc_single_entry *Te,int mode)
 {
-  Te->cdte_track=trk;
-  Te->cdte_format=mode;
-  return ioctl(cdrom_fd,CDROMREADTOCENTRY,Te);
+  Te->track=trk;
+  Te->address_format=mode;
+  return ioctl(cdrom_fd,CDIOREADTOCENTRY,Te);
 }
 
 void cd_read_audio(int lba,int num,char *buf)
@@ -244,16 +249,27 @@
 	/*NOTE: if num>CDROM_NBLOCKS_BUFFER as defined in ide_cd.c (8 in linux 2.0.32)
 	  jitter correction may be required inside the block. */					   
 {
-	struct cdrom_read_audio ra;
+/* CDIOCREADAUDIO has been removed in FreeBSD 5.1-CURRENT */
+#if defined (__FreeBSD__) &&  (__FreeBSD_version >= 501106)
+	int bsize = 2352;
+        if(ioctl(cdrom_fd,CDRIOCSETBLOCKSIZE,&bsize) == -1) {
+		fprintf(stderr, "setblocksize");
+		exit(1);
+        }
+	if (pread(cdrom_fd, buf, num*bsize, lba*bsize) != num*bsize){
+		fprintf(stderr,"\n%s: read device at lba %d length %d: %s\n",
+				progname,lba,num,strerror(errno));
+#else
+	struct ioc_read_audio ra;
 
-	ra.addr.lba=lba;
-	ra.addr_format=CDROM_LBA;
+	ra.address.lba=lba;
+	ra.address_format=CD_LBA_FORMAT;
 	ra.nframes=num;
-	ra.buf=buf;
-	if(ioctl(cdrom_fd,CDROMREADAUDIO,&ra)){
-		/*fprintf(stderr,"%s: read raw ioctl failed \n",progname);*/
+	ra.buffer=buf;
+	if(ioctl(cdrom_fd,CDIOCREADAUDIO,&ra)){
 		fprintf(stderr,"\n%s: read raw ioctl failed at lba %d length %d: %s\n",
 				progname,lba,num,strerror(errno));
+#endif
 		exit(1);
 	}
 }
@@ -471,7 +487,7 @@
   DIR *d;
   struct dirent *e;
   char *id2,*p,*cddb,*loc;
-  int i,cddbs,locs;
+  int i,cddbs,locs=0;
   char id[12];
   char *path;
   char path2[500];
@@ -645,10 +661,10 @@
 int cd_getinfo(char *cd_dev,struct cd_trk_list *tl)
 {
 	int i;
-	struct cdrom_tochdr Th;
-	struct cdrom_tocentry Te;
+	struct ioc_toc_header Th;
+	struct ioc_read_toc_single_entry Te;
 
-	if ((cdrom_fd=open(cd_dev,O_RDONLY|O_NONBLOCK))==-1){
+	if ((cdrom_fd=open(cd_dev,O_RDONLY))==-1){
 		fprintf(stderr,"%s: error opening device %s\n",progname,cd_dev);
 		exit(1);
 	}
@@ -656,7 +672,7 @@
 		fprintf(stderr,"%s: read TOC ioctl failed: %s\n",progname,strerror(errno));
 		exit(1);
 	}
-	tl->min=Th.cdth_trk0;tl->max=Th.cdth_trk1;
+	tl->min=Th.starting_track;tl->max=Th.ending_track;
 	if((tl->starts=(int *)malloc((tl->max-tl->min+2)*sizeof(int)))==NULL){
 		fprintf(stderr,"%s: list data allocation failed\n",progname);
 		exit(1);
@@ -668,21 +684,21 @@
 
 	for (i=tl->min;i<=tl->max;i++)
 	{
-		if(cd_get_tocentry(i,&Te,CDROM_LBA)){
+		if(cd_get_tocentry(i,&Te,CD_LBA_FORMAT)){
 			fprintf(stderr,"%s: read TOC entry ioctl failed: %s\n",
 				progname,strerror(errno));
 			exit(1);
 		}
-		tl->starts[i-tl->min]=Te.cdte_addr.lba;
-		tl->types[i-tl->min]=Te.cdte_ctrl&CDROM_DATA_TRACK;
+		tl->starts[i-tl->min]=ntohl(Te.entry.addr.lba);
+		tl->types[i-tl->min]=Te.entry.control&CDROM_DATA_TRACK;
 	}
 	i=CDROM_LEADOUT;
-	if(cd_get_tocentry(i,&Te,CDROM_LBA)){
+	if(cd_get_tocentry(i,&Te,CD_LBA_FORMAT)){
 		fprintf(stderr,"%s: read TOC entry ioctl failed: %s\n",progname,strerror(errno));
 		exit(1);
 	}
-	tl->starts[tl->max-tl->min+1]=Te.cdte_addr.lba;
-	tl->types[tl->max-tl->min+1]=Te.cdte_ctrl&CDROM_DATA_TRACK;
+	tl->starts[tl->max-tl->min+1]=ntohl(Te.entry.addr.lba);
+	tl->types[tl->max-tl->min+1]=Te.entry.control&CDROM_DATA_TRACK;
 	
         i=cddb_main(tl);
 	if(i==-1) {
@@ -796,6 +812,7 @@
 	struct Wavefile header;
 	int fd,bytes,i,n,q,space;
 	int bcount, sc, missing, speed = 0, ldp, now;
+	ssize_t wlen;
 
 	if(tn<tl->min || tn>tl->max) return (-1);
 	space = ((tl->starts[tn-tl->min+1]-tl->starts[tn-tl->min]) * 
@@ -879,8 +896,10 @@
 					d = p1[c];
 					buf3[c] = ((short)(d&65535) + (short)(d>>16)) >> 1;
 				}
-				write(fd,buf3,n>>1);
-			} else if(write(fd,p1,n)==-1){
+				wlen = write(fd,buf3,n>>1);
+			} else 
+				wlen = write(fd,p1,n);
+			if (wlen == -1){
 				fprintf(stderr,"%s: error writing wave file %s: %s\n",
 					progname,nam,strerror(errno));
 				exit(1);
@@ -896,7 +915,17 @@
 	/* dump last bytes */
 	if (bytes<(tl->starts[tn+1]-tl->starts[tn])*CD_FRAMESIZE_RAW){
 		n=(tl->starts[tn+1]-tl->starts[tn])*CD_FRAMESIZE_RAW-bytes;
-		if(write(fd,p1,n)==-1){
+		if(opt_mono) {
+			register int c, d;
+			for(c = 0; c < (n>>2); c++) {
+				d = p1[c];
+				buf3[c] = ((short)(d&65535) + (short)(d>>16)) >> 1;
+			}
+			wlen = write(fd,buf3,n>>1);
+		} else 
+			wlen = write(fd,p1,n);
+
+		if(wlen==-1){
 			fprintf(stderr,"%s: error writing wave file %s: %s\n",progname,nam,strerror(errno));
 			exit(1);
 		};
@@ -961,7 +990,7 @@
 int main(int ac,char **av)
 {
 	int i,l,disp_TOC=0;
-	char c;
+	int c;
 	int all_tracks=0;
 	struct cd_trk_list tl;
 	char cd_dev[BLEN+1]=CDDEVICE;
@@ -969,10 +998,8 @@
 	char filter[BLEN+1] = "";
 	char path[500];
 	FILE *f;
-
 	progname=av[0];
-	optind=0;
-	while((c=getopt(ac,av,"d:f:n:o:k:r:t:m:e:H:P:D:pshaivCSN"))!=EOF){
+	while((c=getopt(ac,av,"pshaivCSNd:f:n:o:k:r:t:m:e:H:P:D:"))!=-1){
 		switch(c){
 			case 'h':usage();break;
 			case 'd':CPARG(cd_dev);break;
