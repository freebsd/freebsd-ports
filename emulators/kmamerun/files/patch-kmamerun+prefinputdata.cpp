*** kmamerun/prefinputdata.cpp.orig	Sat Jan 18 14:06:30 2003
--- kmamerun/prefinputdata.cpp	Sat Jan 18 14:07:10 2003
***************
*** 35,40 ****
--- 35,41 ----
    comboJoyType->insertItem(i18n("Fm Town Pad support"));
    comboJoyType->insertItem(i18n("X11 input extension joystick"));
    comboJoyType->insertItem(i18n("new i386 linux 1.x..x joystick driver"));
+   comboJoyType->insertItem(i18n("NetBSD USB joystick driver"));
  
    checkGrabMouse= new QCheckBox(this,"NoName");
    checkGrabMouse->setGeometry(10,100,410,30);
