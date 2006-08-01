--- src/uparport.cc	Sat Jun 24 13:21:15 2006
+++ src/uparport.cc	Sat Jun 24 14:31:29 2006
@@ -25,23 +25,23 @@
 struct parport::pintable parport::pin_table[26] =
     {
         { NA, NA ,0x00, &parport::errimg },		/* pin 0	Invalid pin #	*/
-        { PPRCONTROL, PPWCONTROL,0x01, &parport::controlimg }, /* pin 1	(out)	!strobe	*/
-        { PPRDATA, PPWDATA ,0x01, &parport::dataimg },/* pin 2	(out)	Data 0	*/
-        { PPRDATA, PPWDATA ,0x02, &parport::dataimg },/* pin 3	(out)	Data 1	*/
-        { PPRDATA, PPWDATA ,0x04, &parport::dataimg },/* pin 4	(out)	Data 2	*/
-        { PPRDATA, PPWDATA ,0x08, &parport::dataimg },/* pin 5	(out)	Data 3	*/
-        { PPRDATA, PPWDATA ,0x10, &parport::dataimg },/* pin 6	(out)	Data 4	*/
-        { PPRDATA, PPWDATA ,0x20, &parport::dataimg },/* pin 7	(out)	Data 5	*/
-        { PPRDATA, PPWDATA ,0x40, &parport::dataimg },/* pin 8	(out)	Data 6	*/
-        { PPRDATA, PPWDATA ,0x80, &parport::dataimg },/* pin 9	(out)	Data 7	*/
-        { PPRSTATUS, NA ,0x40, &parport::statusimg },/* pin 10	(in)	!ack	*/
-        { PPRSTATUS, NA ,0x80, &parport::statusimg },	/* pin 11	(in)	busy	*/
-        { PPRSTATUS, NA ,0x20, &parport::statusimg },	/* pin 12	(in)	Pout	*/
-        { PPRSTATUS, NA ,0x10, &parport::statusimg },	/* pin 13	(in)	Select	*/
-        { PPRCONTROL, PPWCONTROL,0x02, &parport::controlimg },/* pin 14	(out)	!feed	*/
-        { PPRSTATUS, NA ,0x08, &parport::statusimg },/* pin 15	(in)	!error	*/
-        { PPRCONTROL, PPWCONTROL,0x04, &parport::controlimg },/* pin 16	(out)	!init	*/
-        { PPRCONTROL, PPWCONTROL,0x08, &parport::controlimg },/* pin 17	(out)	!SI	*/
+        { PPIGCTRL, PPISCTRL ,0x01, &parport::controlimg }, /* pin 1	(out)	!strobe	*/
+        { PPIGDATA, PPISDATA ,0x01, &parport::dataimg },/* pin 2	(out)	Data 0	*/
+        { PPIGDATA, PPISDATA ,0x02, &parport::dataimg },/* pin 3	(out)	Data 1	*/
+        { PPIGDATA, PPISDATA ,0x04, &parport::dataimg },/* pin 4	(out)	Data 2	*/
+        { PPIGDATA, PPISDATA ,0x08, &parport::dataimg },/* pin 5	(out)	Data 3	*/
+        { PPIGDATA, PPISDATA ,0x10, &parport::dataimg },/* pin 6	(out)	Data 4	*/
+        { PPIGDATA, PPISDATA ,0x20, &parport::dataimg },/* pin 7	(out)	Data 5	*/
+        { PPIGDATA, PPISDATA ,0x40, &parport::dataimg },/* pin 8	(out)	Data 6	*/
+        { PPIGDATA, PPISDATA ,0x80, &parport::dataimg },/* pin 9	(out)	Data 7	*/
+        { PPIGSTATUS, NA ,0x40, &parport::statusimg },/* pin 10	(in)	!ack	*/
+        { PPIGSTATUS, NA ,0x80, &parport::statusimg },	/* pin 11	(in)	busy	*/
+        { PPIGSTATUS, NA ,0x20, &parport::statusimg },	/* pin 12	(in)	Pout	*/
+        { PPIGSTATUS, NA ,0x10, &parport::statusimg },	/* pin 13	(in)	Select	*/
+        { PPIGCTRL, PPISCTRL,0x02, &parport::controlimg },/* pin 14	(out)	!feed	*/
+        { PPIGSTATUS, NA ,0x08, &parport::statusimg },/* pin 15	(in)	!error	*/
+        { PPIGCTRL, PPISCTRL,0x04, &parport::controlimg },/* pin 16	(out)	!init	*/
+        { PPIGCTRL, PPISCTRL,0x08, &parport::controlimg },/* pin 17	(out)	!SI	*/
         { NA, NA , 0x00, &parport::errimg  },			/* pin 18	GND		*/
         { NA, NA , 0x00, &parport::errimg  },			/* pin 19	GND		*/
         { NA, NA , 0x00, &parport::errimg  },			/* pin 20	GND		*/
@@ -68,7 +68,6 @@
 int parport::yield()
 {
     if(fd == -1) return -1;
-    return ioctl(fd,PPYIELD) ;
 }
 
 // --------------------------------------------------------
@@ -83,22 +82,15 @@
 
     int k;
 
-    if( ((sscanf(np,"/dev/parport%d",&k) == 1) || (sscanf(np,"/dev/parports/%d",&k) == 1))
+    if( ((sscanf(np,"/dev/ppi%d",&k) == 1) || (sscanf(np,"/dev/ppi/%d",&k) == 1))
     		 && (k >= 0) && (k < 10))
     {
         // seems correct ..
         fd = open(np, O_RDWR) ;
 
-        if( fd != -1)
+        if( fd != 0)
         {
-            if( (k = ioctl(fd, PPCLAIM)) != 0)
-            {
-                char b[200] ;
-                sprintf(b,"parport::setport (%.150s must be rw enabled)", np);
-                perror(b) ;
-                ::close(fd) ;
-                fd = -1 ;
-            }
+		return ;
         }
         else
             perror("Cannot open parallel port") ;
@@ -110,7 +102,7 @@
 
 int parport::writedata(unsigned char x)
 {
-    int s =  ioctl(fd,PPWDATA,&x);
+    int s =  ioctl(fd,PPISDATA,&x);
     if( s )
         perror("parport::writedata") ;
     else
@@ -120,7 +112,7 @@
 
 int parport::readdata(unsigned char& x)
 {
-    int s =  ioctl(fd,PPRDATA,&x);
+    int s =  ioctl(fd,PPIGDATA,&x);
     if( s )
         perror( "parport::readdata")  ;
     else
@@ -131,7 +123,7 @@
 
 int parport::writecontrol(unsigned char x)
 {
-    int s =  ioctl(fd,PPWCONTROL,&x);
+    int s =  ioctl(fd, PPISCTRL,&x);
     if( s ) perror( "parport::writecontrol") ;
     else controlimg = x ;
     return s ;
@@ -139,7 +131,7 @@
 
 int parport::readcontrol(unsigned char& x)
 {
-    int s =  ioctl(fd,PPRCONTROL,&x);
+    int s =  ioctl(fd, PPIGCTRL,&x);
     if( s )
         perror("parport::readcontrol");
     else
@@ -160,7 +152,7 @@
 
 int parport::readstatus(unsigned char& x)
 {
-    int s =  ioctl(fd,PPRSTATUS,&x);
+    int s =  ioctl(fd,PPIGSTATUS,&x);
     if( s )
         perror("parport::readstatus") ;
     else
@@ -235,34 +227,18 @@
 	int fd = open(pname, O_RDWR) ;
 	if( fd == -1 ) return -2 ;
  
-	int k = ioctl(fd, PPCLAIM) ;
-
-	if( k != 0 )
-	{
-			::close(fd) ;
-			return  -1 ;
-	}
-
-  ioctl(fd,PPRELEASE) ;
-	
-  ::close(fd) ;
+	::close(fd) ;
 
 	return 0 ;
-
 }
 /** No descriptions */
 void parport::close()
 {
-		if( fd != -1)
-    {
-        int stat = ioctl(fd,PPRELEASE) ;
-        ::close(fd) ;
-        if( stat != 0)
-        {
-            perror("parport::~parport") ;
-        }
-    }
-    fd = -1 ;
+	if( fd != -1)
+    	{
+		::close(fd) ;
+	}
+	fd = -1 ;
 }
 bool parport::isok()
 {
