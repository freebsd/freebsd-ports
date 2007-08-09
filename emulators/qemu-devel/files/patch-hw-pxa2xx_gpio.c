Index: qemu/hw/pxa2xx_gpio.c
@@ -152,6 +152,9 @@
     case GPDR:		/* GPIO Pin-Direction registers */
         return s->dir[bank];
 
+    case GPSR:		/* GPIO Pin-Output Set registers */
+        return s->olevel[bank];
+
     case GRER:		/* GPIO Rising-Edge Detect Enable registers */
         return s->rising[bank];
 
