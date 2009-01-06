--- blight_input/plugin.c	2008-10-13 21:31:47.000000000 -0500
+++ blight_input/plugin.c	2008-12-15 02:11:02.000000000 -0500
@@ -20,7 +20,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <dirent.h>
+#ifdef __linux__
 #include <linux/input.h>
+#endif
 
 #include "plugin.h"
 
@@ -453,9 +455,11 @@
 
 BYTE lastCommand[6];
 
+#ifdef __linux__
 struct ff_effect ffeffect[3];
 struct ff_effect ffstrong[3];
 struct ff_effect ffweak[3];
+#endif
 
 BYTE DataCRC( BYTE *Data, int iLenght )
 {
@@ -513,6 +517,7 @@
 void
 ControllerCommand(int Control, BYTE *Command)
 {
+#ifdef __linux__
     BYTE *Data = &Command[5];
     struct input_event play;
 
@@ -580,6 +585,7 @@
             /*printf( "Write eeprom\n" );*/
             break;
         }
+#endif
 }
 
 /******************************************************************
@@ -860,7 +866,9 @@
 void
 GetKeys( int Control, BUTTONS *Keys )
 {
+#ifdef __linux__
     struct input_event play;
+#endif
     int b, axis_val, axis_max_val, axis_val_tmp;
     SDL_Event event;
     Uint8 *keystate = SDL_GetKeyState( NULL );
@@ -1086,6 +1094,7 @@
 #endif
     *(int *)Keys = *(int *)&controller[Control].buttons;
 
+#ifdef __linux__
     /* handle mempack / rumblepak switching (only if rumble is active on joystick) */
     if (controller[Control].event_joystick != 0)
     {
@@ -1108,6 +1117,7 @@
                 perror("Error starting rumble effect");
         }
     }
+#endif
 }
 
 int InitiateRumble(int cntrl)
@@ -1165,6 +1175,7 @@
         return 0;
     }
 
+#ifdef __linux__
     if (ioctl(controller[cntrl].event_joystick, EVIOCGBIT(EV_FF, sizeof(unsigned long) * 4), features) == -1)
     {
         printf("["PLUGIN_NAME"]: Linux kernel communication failed for force feedback (rumble).\n", temp);
@@ -1205,6 +1216,7 @@
     ioctl(controller[cntrl].event_joystick, EVIOCSFF, &ffweak[cntrl]);
 
     printf("["PLUGIN_NAME"]: Rumble activated on N64 joystick #%i\n", cntrl + 1);
+#endif
 }
 
 /******************************************************************
