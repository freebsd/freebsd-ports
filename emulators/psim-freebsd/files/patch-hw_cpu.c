diff -r -u sim/ppc/hw_cpu.c /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/hw_cpu.c
--- sim/ppc/hw_cpu.c	Thu Apr 15 18:35:09 1999
+++ /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/hw_cpu.c	Sun Oct  7 16:16:57 2001
@@ -110,6 +110,8 @@
 {
   hw_cpu_device *hw_cpu = (hw_cpu_device*)device_data(me);
   /* populate the node with properties */
+  device_add_string_property(me, "device_type", "cpu");
+  device_add_integer_property(me, "timebase-frequency", 0x00fe502a);
   /* clear our data */
   memset(hw_cpu, 0x0, sizeof(hw_cpu_device));
   hw_cpu->cpu_nr = device_find_integer_property(me, "cpu-nr");
@@ -148,6 +150,42 @@
   }
 }
 
+/* An instance of the cpu */
+  
+typedef struct _hw_cpu_instance {
+  unsigned_word pos;
+  hw_cpu_device *cpu;
+  device *me;
+} hw_cpu_instance;
+
+static void
+hw_cpu_instance_delete(device_instance *instance)
+{
+  hw_cpu_instance *data = device_instance_data(instance);
+  zfree(data);
+}
+
+static const device_instance_callbacks hw_cpu_instance_callbacks = {
+  hw_cpu_instance_delete,
+  NULL,
+  NULL,
+  NULL,
+};
+
+static device_instance *     
+hw_cpu_create_instance(device *me,    
+                          const char *path,
+                          const char *args)
+{
+  hw_cpu_device *cpu = device_data(me);
+  hw_cpu_instance *data = ZALLOC(hw_cpu_instance);
+  data->cpu = cpu;
+  data->me = me;
+  return device_create_instance_from(me, NULL,
+                                     data,
+                                     path, args,
+                                     &hw_cpu_instance_callbacks);
+}
 
 static device_callbacks const hw_cpu_callbacks = {
   { hw_cpu_init_address, }, /* init */
@@ -156,6 +194,7 @@
   { NULL, }, /* DMA */
   { hw_cpu_interrupt_event, NULL, hw_cpu_interrupt_ports }, /* interrupts */
   { NULL, NULL, },
+  hw_cpu_create_instance,
 };
 
 const device_descriptor hw_cpu_device_descriptor[] = {
