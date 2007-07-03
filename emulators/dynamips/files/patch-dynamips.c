--- dynamips.c.orig	Wed Feb 14 20:37:58 2007
+++ dynamips.c	Fri Apr  6 21:11:38 2007
@@ -61,6 +61,7 @@
 /* Hypervisor */
 int hypervisor_mode = 0;
 int hypervisor_tcp_port = 0;
+char hypervisor_ip_address[263]="\000"; /* 256(MAXHOSTNAMELEN)+1(:)+5(port)+NULL */
 
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
@@ -254,7 +255,7 @@
           "  -R <rom_file>      : Load an alternate ROM (default: embedded)\n"
           "  -k <clock_div>     : Set the clock divisor (default: %d)\n"
           "\n"
-          "  -T <port>          : Console is on TCP <port>\n"
+          "  -T [ip_address:]<port> : Console is on TCP <port>\n"
           "  -U <si_desc>       : Console in on serial interface <si_desc>\n"
           "                       (default is on the terminal)\n"
           "\n"
@@ -780,6 +781,7 @@
    int instance_id;
    int res,option;
    char *str;
+   char *index;
 
    /* Get the instance ID */
    instance_id = 0;
@@ -944,7 +946,15 @@
          /* TCP server for Console Port */
          case 'T':
             vm->vtty_con_type = VTTY_TYPE_TCP;
-            vm->vtty_con_tcp_port = atoi(optarg);
+	    strncpy(hypervisor_ip_address,optarg,sizeof(hypervisor_ip_address));
+	    index=strrchr(hypervisor_ip_address,':');
+	    if (index != NULL) {
+		*index++='\000';
+		vm->vtty_con_tcp_port = atoi(index);
+	    } else {
+		vm->vtty_con_tcp_port = atoi(hypervisor_ip_address);
+		hypervisor_ip_address[0]='\000';
+	    }
             break;
 
          /* Serial interface for Console port */
@@ -1061,6 +1071,7 @@
 static int run_hypervisor(int argc,char *argv[])
 {
    char *options_list = "H:l:hN:";
+   char *index;
    int i,option;
 
    for(i=1;i<argc;i++)
@@ -1079,7 +1090,15 @@
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
@@ -1244,7 +1263,7 @@
       /* Free resources used by instance */
       vm_release(vm);
    } else {
-      hypervisor_tcp_server(hypervisor_tcp_port);
+      hypervisor_tcp_server(hypervisor_ip_address,hypervisor_tcp_port);
    }
 
    dynamips_reset();
