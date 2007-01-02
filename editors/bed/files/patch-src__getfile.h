--- src/getfile.h.orig	Thu May 23 16:28:24 2002
+++ src/getfile.h	Mon Jan  1 23:48:02 2007
@@ -267,7 +267,7 @@
 
 extern WINDOW *getshowwin(int l,int c,int by,int bx) ;
 
-#define initdialog(nr) {item **showformsarray;int showformsiter=0,showformsmaxar=(nr);  showformsarray=new (item *)[showformsmaxar];
+#define initdialog(nr) {item **showformsarray;int showformsiter=0,showformsmaxar=(nr);  showformsarray=new item *[showformsmaxar];
 #define dodialog(ant,l,c,sel) if((takescr=getshowwin((l),(c),(thelines-(l))/2,(thecols-(c))/2))){ (ant)=show(showformsarray,showformsiter,(sel));};for(int dodialogiter=0;dodialogiter<showformsiter;dodialogiter++) delete showformsarray[dodialogiter];delete[] showformsarray;};
 #define dodialogpost(ant,l,c,sel,post) if((takescr=getshowwin((l),(c),(thelines-(l))/2,(thecols-(c))/2))){(post);(ant)=show(showformsarray,showformsiter,(sel));};for(int dodialogiter=0;dodialogiter<showformsiter;dodialogiter++) delete showformsarray[dodialogiter];delete[] showformsarray;};
 #define showdialog(ant,l,c,sel) if((takescr=getshowwin((l),c,(thelines-(l))/2,(thecols-c)/2))){ant=show(showformsarray,showformsiter,sel);};
@@ -278,7 +278,7 @@
 #endif
 
 
-#define begindialog(l,c,nr) if((takescr=getshowwin((l),(c),(thelines-(l))/2,(thecols-(c))/2))){item **showformsarray;int showformsiter=0,showformsmaxar=nr;  showformsarray=new (item *)[showformsmaxar]; 
+#define begindialog(l,c,nr) if((takescr=getshowwin((l),(c),(thelines-(l))/2,(thecols-(c))/2))){item **showformsarray;int showformsiter=0,showformsmaxar=nr;  showformsarray=new item *[showformsmaxar]; 
 
 #define enddialog(ant,sel) ant=show(showformsarray,showformsiter,(sel));for(int dodialogiter=0;dodialogiter<showformsiter;dodialogiter++) delete showformsarray[dodialogiter];delete[] showformsarray;};
 
@@ -299,7 +299,7 @@
 #define lcsconfig(l,c,sel,...) plcsconfig(l,c,sel,0,__VA_ARGS__) 
 #define plcsconfig(l,c,sel,post,...) {int throwawayant;palcsconfig(throwawayant,l,c,sel,post,__VA_ARGS__) } 
 #define alcsconfig(ant,l,c,sel,...) palcsconfig(ant,l,c,sel,0,__VA_ARGS__)  
-#define palcsconfig(ant,l,c,sel,post,...) {item **showformsarray;int showformsiter=0; int showformsmaxar=sizeof((item* []){__VA_ARGS__})/sizeof(item *); if((takescr=getshowwin(l,c,(thelines-l)/2,(thecols-c)/2))) { showformsarray=new (item *)[showformsmaxar],__VA_ARGS__;post;ant=show(showformsarray,showformsmaxar,sel);for(showformsiter=0;showformsiter<showformsmaxar;showformsiter++) delete showformsarray[showformsiter];delete[] showformsarray;};} 
+#define palcsconfig(ant,l,c,sel,post,...) {item **showformsarray;int showformsiter=0; int showformsmaxar=sizeof((item* []){__VA_ARGS__})/sizeof(item *); if((takescr=getshowwin(l,c,(thelines-l)/2,(thecols-c)/2))) { showformsarray=new item *[showformsmaxar],__VA_ARGS__;post;ant=show(showformsarray,showformsmaxar,sel);for(showformsiter=0;showformsiter<showformsmaxar;showformsiter++) delete showformsarray[showformsiter];delete[] showformsarray;};} 
 #define options(name,sel,...)  {int startformsiter=showformsiter; Common *comptr=new Common(name,0);__VA_ARGS__,comptr->last=(orcheck*)showformsarray[startformsiter+sel];}; 
 
 #endif
