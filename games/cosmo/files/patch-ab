--- setup.c.orig	Sat May 11 15:48:32 1996
+++ setup.c	Sat Aug  3 17:06:39 2002
@@ -106,7 +106,8 @@
     {
       i++;
       if(i>=ac) break;
-      strcpy(display,av[i]);
+      strncpy(display,av[i],sizeof(display));
+      display[sizeof(display) - 1] = '\0';     
     }
     else if(!strcmp(av[i],"-cmap"))
     {
@@ -120,7 +121,8 @@
     {
       i++;
       if(i>=ac) show_usage();
-      strcpy(bgfn,av[i]);
+      strncpy(bgfn,av[i],sizeof(bgfn));
+      bgfn[sizeof(bgfn) - 1] = '\0';   
     }
     else if(!strcmp(av[i],"-rough"))
     {
@@ -139,7 +141,7 @@
     {
       i++;
       if(i>=ac) show_usage();
-      if(strcmp(av[i],"no")) strcpy(pad_dev,av[i]);
+      if(strcmp(av[i],"no")) strncpy(pad_dev,av[i],sizeof(pad_dev)); pad_dev[sizeof(pad_dev) - 1] = '\0'; 
                         else upad=0;
     }
 #endif
@@ -154,10 +156,14 @@
 
   user.uid=getuid();
   p=getpwuid(user.uid);
-  strcpy(user.name,p->pw_name);
-  strcpy(home_dir,p->pw_dir);
+  strncpy(user.name,p->pw_name,sizeof(user.name));
+  user.name[sizeof(user.name) - 1] = '\0';
+
+  strncpy(home_dir,p->pw_dir,sizeof(home_dir));
+  home_dir[sizeof(home_dir) -1] = '\0';
   if( home_dir[strlen(home_dir)-1] != '/' ) strcat(home_dir,"/");
-  strcpy(rc_file,home_dir);
+  strncpy(rc_file,home_dir,sizeof(rc_file));
+  rc_file[sizeof(rc_file) - 1 ] = '\0';
   strcat(rc_file,".cosmorc");
 }
 
@@ -195,14 +201,16 @@
     show_error("Too Few Arguments",buf,line,2);
     return;
   }
-  strcpy(colorname,p);
+  strncpy(colorname,p,sizeof(colorname));
+  colorname[sizeof(colorname) - 1] = '\0';
 
   if( (p=getnword(buf,2))==NULL )
   {
     show_error("Too Few Arguments",buf,line,3);
     return;
   }
-  strcpy(color,p);
+  strncpy(color,p,sizeof(color));
+  color[sizeof(color)] = '\0';
 
        if( !strcmp(colorname,"Background") ) strcpy(colors[Back],color);
   else if( !strcmp(colorname,"Foreground") ) strcpy(colors[Fore],color);
@@ -298,7 +306,8 @@
     i=1;
     while(p[i]!='/'&&p[i]!='\0') name[i-1]=p[i++];
     name[i-1]='\0';
-    if(i==1) strcpy(name,user.name);
+    if(i==1) strncpy(name,user.name,sizeof(name));
+    name[sizeof(name) -1] = '\0';
 
     do
     {
