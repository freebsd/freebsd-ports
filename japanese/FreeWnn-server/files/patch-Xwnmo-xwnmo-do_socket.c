Index: Xwnmo/xwnmo/do_socket.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Xwnmo/xwnmo/do_socket.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Xwnmo/xwnmo/do_socket.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Xwnmo/xwnmo/do_socket.c	20 Dec 2008 07:23:12 -0000	1.2
@@ -118,8 +118,6 @@ static int rc = 0;
 #define sock_clr(array,pos)     (array[pos/BINTSIZE] &= ~(1<<(pos%BINTSIZE)))
 #define sock_tst(array,pos)     (array[pos/BINTSIZE] & (1<<(pos%BINTSIZE)))
 
-extern int read (), write ();
-
 #define _Read(fd, data, size)   read((fd), (data), (size))
 #define _Write(fd, data, size)  write((fd), (data), (size))
 
