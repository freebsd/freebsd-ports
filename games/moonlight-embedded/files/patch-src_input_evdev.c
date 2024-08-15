--- src/input/evdev.c.orig	2024-02-20 04:01:31 UTC
+++ src/input/evdev.c
@@ -45,6 +45,8 @@
 #endif
 #include <math.h>
 
+static bool isUseKbdmux = false;
+
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define int16_to_le(val) val
 #else
@@ -758,7 +760,7 @@ static int evdev_handle(int fd) {
       struct input_event ev;
       while ((rc = libevdev_next_event(devices[i].dev, LIBEVDEV_READ_FLAG_NORMAL, &ev)) >= 0) {
         if (rc == LIBEVDEV_READ_STATUS_SYNC)
-          fprintf(stderr, "Error: cannot keep up\n");
+          fprintf(stderr, "Error:%s(%d) cannot keep up\n", libevdev_get_name(devices[i].dev), i);
         else if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
           if (!handler(&ev, &devices[i]))
             return LOOP_RETURN;
@@ -775,6 +777,39 @@ static int evdev_handle(int fd) {
   return LOOP_OK;
 }
 
+void is_use_kbdmux() {
+  const char* tryFirstInput = "/dev/input/event0";
+  const char* trySecondInput = "/dev/input/event1";
+
+  int fdFirst = open(tryFirstInput, O_RDWR|O_NONBLOCK);
+  int fdSecond = open(trySecondInput, O_RDWR|O_NONBLOCK);
+  if (fdFirst <= 0 && fdSecond <= 0) {
+    //Suppose use kbdmux because of default behavior
+    isUseKbdmux = true;
+    return;
+  }
+
+  struct libevdev *evdevFirst = libevdev_new();
+  libevdev_set_fd(evdevFirst, fdFirst);
+  const char* nameFirst = libevdev_get_name(evdevFirst);
+  struct libevdev *evdevSecond = libevdev_new();
+  libevdev_set_fd(evdevSecond, fdSecond);
+  const char* nameSecond = libevdev_get_name(evdevSecond);
+
+  libevdev_free(evdevFirst);
+  libevdev_free(evdevSecond);
+  close(fdFirst);
+  close(fdSecond);
+
+  if (strcmp(nameFirst, "System keyboard multiplexer") == 0 ||
+      strcmp(nameSecond, "System keyboard multiplexer") == 0) {
+    isUseKbdmux = true;
+    return;
+  }
+
+  return;
+}
+
 void evdev_create(const char* device, struct mapping* mappings, bool verbose, int rotate) {
   int fd = open(device, O_RDWR|O_NONBLOCK);
   if (fd <= 0) {
@@ -851,6 +886,33 @@ void evdev_create(const char* device, struct mapping* 
      libevdev_has_event_code(evdev, EV_ABS, ABS_WHEEL) ||
      libevdev_has_event_code(evdev, EV_ABS, ABS_GAS) ||
      libevdev_has_event_code(evdev, EV_ABS, ABS_BRAKE));
+  bool is_acpibutton =
+    strcmp(name, "Sleep Button") == 0 ||
+    strcmp(name, "Power Button") == 0;
+  // Just use System keyboard multiplexer for FreeBSD,see kbdcontrol(1) and kbdmux(4)
+  // Trying to grab kbdmux0 and keyboard it's self at the same time results in
+  // the keyboard becoming unresponsive on FreeBSD.
+  bool is_likekeyboard =
+    is_keyboard && isUseKbdmux && strcmp(name, "System keyboard multiplexer") != 0;
+/*
+    (is_keyboard && guid[0] <= 3) ||
+    strcmp(name, "AT keyboard") == 0;
+*/
+
+  // In some cases,acpibutton can be mistaken for a keyboard and freeze the keyboard when tring grab.
+  if (is_acpibutton) {
+    if (verbose)
+      printf("Skip acpibutton: %s\n", name);
+    libevdev_free(evdev);
+    close(fd);
+    return;
+  }
+  // In some cases,Do not grab likekeyboard for avoiding keyboard unresponsive
+  if (is_likekeyboard) {
+    if (verbose)
+      printf("Do NOT grab like-keyboard: %s,version: %d,bustype: %d\n", name, guid[6], guid[0]);
+    is_keyboard = false;
+  }
 
   if (is_accelerometer) {
     if (verbose)
