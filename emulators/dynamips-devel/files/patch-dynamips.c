--- dynamips.c.orig	Wed Mar 21 10:07:17 2007
+++ dynamips.c	Wed Mar 21 13:39:57 2007
@@ -61,6 +61,7 @@
 /* Hypervisor */
 int hypervisor_mode = 0;
 int hypervisor_tcp_port = 0;
+char hypervisor_ip_address[263]; /* 256(MAXHOSTNAMELEN)+1(:)+5(port)+NULL */
 
 /* Log file */
 char *log_file_name = NULL;
@@ -227,7 +228,7 @@
    printf("Usage: %s [options] <ios_image>\n\n",argv[0]);
    
    printf("Available options:\n"
-          "  -H <tcp_port>      : Run in hypervisor mode\n\n"
+          "  -H [ip_address:]<tcp_port> : Run in hypervisor mode\n\n"
           "  -P <platform>      : Platform to emulate (7200, 3600, "
           "2691, 3725 or 3745) "
           "(default: 7200)\n\n"
@@ -1061,6 +1062,7 @@
 static int run_hypervisor(int argc,char *argv[])
 {
    char *options_list = "H:l:hN:";
+   char *index;
    int i,option;
 
    for(i=1;i<argc;i++)
@@ -1079,7 +1081,15 @@
       {
          /* Hypervisor TCP port */
          case 'H':
-            hypervisor_tcp_port = atoi(optarg);
+	    strncpy(hypervisor_ip_address,optarg,sizeof(hypervisor_ip_address));
+	    index=strrchr(hypervisor_ip_address,':');
+	    if (index != NULL) {
+		*index++='\000';
+            	hypervisor_tcp_port = atoi(index);
+	    } else {
+		hypervisor_tcp_port = atoi(hypervisor_ip_address);
+		hypervisor_ip_address[0]='\000';
+	    }
             break;
 
          /* Log file */
@@ -1244,7 +1254,7 @@
       /* Free resources used by instance */
       vm_release(vm);
    } else {
-      hypervisor_tcp_server(hypervisor_tcp_port);
+      hypervisor_tcp_server(hypervisor_ip_address,hypervisor_tcp_port);
    }
 
    dynamips_reset();
