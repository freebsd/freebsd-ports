--- dynamips.c.orig	Fri Sep  7 12:03:11 2007
+++ dynamips.c	Fri Sep 14 10:18:10 2007
@@ -193,7 +193,7 @@
           "  -R <rom_file>      : Load an alternate ROM (default: embedded)\n"
           "  -k <clock_div>     : Set the clock divisor (default: %d)\n"
           "\n"
-          "  -T <port>          : Console is on TCP <port>\n"
+          "  -T [<ip_address>:]<port> : Console is on TCP <port>\n"
           "  -U <si_desc>       : Console in on serial interface <si_desc>\n"
           "                       (default is on the terminal)\n"
           "\n"
@@ -374,6 +374,8 @@
    int instance_id;
    int option;
    char *str;
+   char *index;
+   size_t len;
 
    /* Get the instance ID */
    instance_id = 0;
@@ -541,7 +543,25 @@
          /* TCP server for Console Port */
          case 'T':
             vm->vtty_con_type = VTTY_TYPE_TCP;
-            vm->vtty_con_tcp_port = atoi(optarg);
+
+            index = strrchr(optarg,':');
+
+            if (!index) {
+               vm->vtty_con_tcp_port = atoi(optarg);
+            } else {
+               len = index - optarg;
+               hypervisor_ip_address = malloc(len + 1);
+
+               if (!hypervisor_ip_address) {
+                  fprintf(stderr,"Unable to set console IP address!\n");
+                  exit(EXIT_FAILURE);
+               }
+
+               memcpy(hypervisor_ip_address,optarg,len);
+               hypervisor_ip_address[len] = '\0';
+
+	       vm->vtty_con_tcp_port = atoi(++index);
+            }
             break;
 
          /* Serial interface for Console port */
@@ -687,6 +707,8 @@
 
                memcpy(hypervisor_ip_address,optarg,len);
                hypervisor_ip_address[len] = '\0';
+
+	       hypervisor_tcp_port = atoi(++index);
             }
             break;
 
