--- f.file.cc.orig	2026-09-30 11:06:25 UTC
+++ f.file.cc
@@ -133,12 +133,11 @@ void new_session(ch *args)
    xx += 100;                                                                          //  shift down and right
    yy += 100;
 
-   cc = readlink("/proc/self/exe",progexe,300);                                        //  get own program path
-   if (cc <= 0) {
-      zmessageACK(Mwin,"cannot get /proc/self/exe");
+   cc = get_prog_path(progexe, sizeof progexe);
+   if (cc == -1) {
+      zmessageACK(Mwin, "could not obtain program path");
       return;
    }
-   progexe[cc] = 0;
 
    if (! args) args = "";
 
@@ -2839,30 +2838,18 @@ void quitxx()
 void m_uninstall(GtkWidget *, ch *)
 {
    zdialog  *zd;
-   ch       *pp, baseloc[300];
    ch       text[200];
-   int      cc;
 
    F1_help_topic = TX("HELP MENU");
 
    printf("m_uninstall \n");
 
-   cc = readlink("/proc/self/exe",baseloc,300);                                        //  get own program path
-   if (cc <= 0) {                                                                      //  [baseloc]/bin/fotocx
-      zmessageACK(Mwin,"cannot get /proc/self/exe");
-      return;
-   }
-   baseloc[cc] = 0;
-
-   pp = strstr(baseloc,"/bin/");
-   if (pp) *(pp+1) = 0;
-   
-   snprintf(text,200,"Delete fotocx program files: \n"
-                     "$ sudo find %s -path \"*fotocx*\" -type l,f,d -delete \n"
+   snprintf(text, sizeof text, "Uninstall fotocx package:\n"
+                     "$ sudo pkg del fotocx\n"
                      "\n"
                      "Delete fotocx user data: \n"
                      "$ rm -f -d -R %s",
-                     baseloc, get_zhomedir());
+                     get_zhomedir());
    
    zd = zdialog_new(TX("copy and paste commands"),Mwin,"X",null);
    zdialog_add_widget(zd,"text","text","dialog",text,"space=3");
