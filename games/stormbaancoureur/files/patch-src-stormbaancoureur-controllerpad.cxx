--- src-stormbaancoureur/controllerpad.cxx.orig	Mon Jul 17 00:26:08 2006
+++ src-stormbaancoureur/controllerpad.cxx	Mon Jul 17 00:28:23 2006
@@ -14,7 +14,6 @@
 #include <windows.h>
 #include <mmsystem.h>
 #else
-#include <linux/joystick.h>
 #include <sys/ioctl.h>  // for ioctl()
 #include <unistd.h>     // for close()
 #include <stdio.h>      // for perror()
@@ -81,100 +80,7 @@
 accel_axis(-1),
 accel_button(-1)
 {
-#ifdef WIN32
-  JOYINFOEX joyinfo;
-  JOYCAPS joycaps;
-  MMRESULT result;
-  int axisCounter;
-
-  id = 0;
-
-  joyinfo.dwSize = sizeof(joyinfo);
-  joyinfo.dwFlags = JOY_RETURNALL;
-
-  result = joyGetPosEx(id, &joyinfo);
-  if(result != JOYERR_NOERROR) {
-    fprintf(stderr, "No input devices found\n");
-    return;
-  }
-  else {
-    result = joyGetDevCaps(id, &joycaps, sizeof(joycaps));
-    if(result != JOYERR_NOERROR) {
-      fprintf(stderr, "No input devices found\n");
-      return;
-    }
-  }
-
-  opened = true;
-
-  fprintf(stderr, "x min %d max %d\n", joycaps.wXmin, joycaps.wXmax);
-  buttoncount = joycaps.wNumButtons;
-  axiscount = joycaps.wNumAxes;
-#else
-  fd = open(devfile.c_str(), O_RDONLY | O_NONBLOCK);
-  if (fd==-1)
-  {
-    if (errno != ENODEV)
-      perror("open() on joystick device failed");
-    return;
-  }
-  opened = true;
-
-  int retval;
-
-  int version;
-  retval = ioctl(fd, JSIOCGVERSION, &version);
-  if (retval == -1)
-    perror("ioctl JSIOCGVERSION failed");
-
-  unsigned char lo = version;
-  unsigned char md = (version>>8);
-  unsigned char hi = (version>>16);
-
-  retval = ioctl(fd, JSIOCGAXES, &axiscount);
-  if (retval == -1)
-    perror("ioctl JSIOCGAXES failed");
-
-  retval = ioctl(fd, JSIOCGBUTTONS, &buttoncount);
-  if (retval == -1)
-    perror("ioctl JSIOCGBUTTONS failed");
-
-  char n[128];
-  retval = ioctl(fd, JSIOCGNAME(128), n);
-  if (retval == -1)
-    perror("ioctl JSIOCGNAME failed");
-
-  name = n;
-  fprintf(stderr,"joystick name: %s\n", name.c_str());
-  fprintf(stderr,"driver version: %d.%d.%d\n", hi,md,lo);
-  fprintf(stderr,"button count: %d, axiscount: %d\n", buttoncount, axiscount);
-#endif
-
-  // search db
-  assert(sizeof(joydb_names) == sizeof(joydb_descs));
-  int cnt = sizeof(joydb_names) / sizeof(void *) - 1;
-  for (int i=0; i<cnt && !joydb_entry; i++)
-  {
-    if (!strcmp(joydb_names[i], name.c_str()))
-      joydb_entry = joydb_descs[i];
-  }
-
-  fprintf
-  ( 
-    stderr,
-    "Known in joystick description database: %s\n",
-    (joydb_entry)?"yes":"no"
-  );
-
-  for (int i=0; i<axiscount; i++)
-    AxisValues.push_back(0);
-  for (int i=0; i<buttoncount; i++)
-  {
-    ButtonValues.push_back(false);
-    ButtonChanged.push_back(false);
-  }
-
-  Introspect();
+	return;
 }
 
 
@@ -194,80 +100,6 @@
 
 void ControllerPad::Sustain(float dt)
 {
-#ifdef WIN32
-  MMRESULT result;
-  DWORD flags[6 /*MAX_AXES*/] = { JOY_RETURNX, JOY_RETURNY, JOY_RETURNZ, 
-    JOY_RETURNR, JOY_RETURNU, JOY_RETURNV };
-  DWORD pos[6 /*MAX_AXES*/];
-  JOYINFOEX joyinfo;
-
-  joyinfo.dwSize = sizeof(joyinfo);
-  joyinfo.dwFlags = JOY_RETURNALL | JOY_RETURNPOVCTS;
-
-#if 0
-  if(!hats) {
-    joyinfo.dwFlags &= ~(JOY_RETURNPOV | JOY_RETURNPOVCTS);
-  }
-#endif
-
-  // get the actual data
-  result = joyGetPosEx(id, &joyinfo);
-
-  if(result != JOYERR_NOERROR) {
-    SetMMerror("joyGetPosEx", result);
-    return;
-  }
-
-  /* joystick motion events */
-  pos[0] = joyinfo.dwXpos;
-  pos[1] = joyinfo.dwYpos;
-  pos[2] = joyinfo.dwZpos;
-  pos[3] = joyinfo.dwRpos;
-  pos[4] = joyinfo.dwUpos;
-  pos[5] = joyinfo.dwVpos;
-
-  for(int axisCounter = 0; axisCounter < axiscount; axisCounter++) {
-    if(joyinfo.dwFlags & flags[axisCounter]) {
-      AxisValues[axisCounter] = float(pos[axisCounter]);
-    }
-  }
-#else
-  struct js_event ev;
-  int retval;
-  do
-  {
-    retval = read(fd, &ev, sizeof(ev));
-    if (retval == -1)
-    {
-      if (errno != EAGAIN)
-      {
-        perror("read() on joystick failed");
-        fprintf(stderr,"joystick read failure\n");
-      }
-    }
-    int type = ev.type;
-    switch(type)
-    {
-      case JS_EVENT_BUTTON:
-        if (ev.number < ButtonValues.size())
-        {
-          ButtonValues[ev.number] = ev.value;
-          ButtonChanged[ev.number] = true;
-        }
-        else
-          fprintf(stderr,"Illegal buttonnr %d\n", ev.number);
-        break;
-      case JS_EVENT_AXIS:
-        if (ev.number < AxisValues.size())
-          AxisValues[ev.number] = ev.value;
-        else
-          fprintf(stderr,"Illegal axisnr %d", ev.number);
-        break;
-      default:
-        break;
-    }
-  } while (retval>0);
-#endif
 }
 
 
