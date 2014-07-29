--- ncurses/_curses_wrap.c.orig	Sun Apr 23 05:52:02 2000
+++ ncurses/_curses_wrap.c	Sun Dec 15 05:30:05 2002
@@ -1136,7 +1136,7 @@
 extern bool isendwin();
 extern bool is_linetouched(WINDOW *,int );
 extern bool is_wintouched(WINDOW *);
-extern const char *keyname(int );
+/*extern const char *keyname(int );*/
 extern int keypad(WINDOW *,bool );
 extern char killchar();
 extern int leaveok(WINDOW *,bool );
@@ -1147,7 +1147,7 @@
 extern int mvwin(WINDOW *,int ,int );
 extern int napms(int );
 extern WINDOW *newpad(int ,int );
-extern SCREEN *newterm(const char *,FILE *,FILE *);
+/*extern SCREEN *newterm(const char *,FILE *,FILE *);*/
 extern WINDOW *newwin(int ,int ,int ,int );
 extern int nl();
 extern int nocbreak();
@@ -1197,15 +1197,15 @@
 extern int syncok(WINDOW *,bool );
 extern chtype termattrs();
 extern char *termname();
-extern int tigetflag(const char *);
-extern int tigetnum(const char *);
-extern char *tigetstr(const char *);
+/*extern int tigetflag(const char *);*/
+/*extern int tigetnum(const char *);*/
+/*extern char *tigetstr(const char *);*/
 extern int typeahead(int );
 extern int ungetch(int );
 extern void use_env(bool );
 extern int vidattr(chtype );
-extern int vwprintw(WINDOW *,const char *,va_list );
-extern int vwscanw(WINDOW *,const char *,va_list );
+/*extern int vwprintw(WINDOW *,const char *,va_list );*/
+/*extern int vwscanw(WINDOW *,const char *,va_list );*/
 extern int waddch(WINDOW *,const chtype );
 extern int waddchnstr(WINDOW *,const chtype *,int );
 extern int waddnstr(WINDOW *,const char *,int );
@@ -1252,7 +1252,7 @@
 extern int mcprint(char *,int );
 extern int has_key(int );
 extern char *_nc_tracebits();
-extern char *_tracechar(const unsigned char );
+/*extern char *_tracechar(const unsigned char );*/
 extern void trace(const unsigned int );
 extern const char *_nc_visbuf(const char *);
 extern void GetYX(WINDOW *,int *,int *);
@@ -4442,7 +4442,8 @@
 }
 
 static PyObject *_wrap__tracechar(PyObject *self, PyObject *args) {
-    PyObject * _resultobj;
+    return Py_None;
+/*    PyObject * _resultobj;
     char * _result;
     unsigned char  _arg0;
 
@@ -4451,11 +4452,12 @@
         return NULL;
     _result = (char *)_tracechar(_arg0);
     _resultobj = Py_BuildValue("s", _result);
-    return _resultobj;
+    return _resultobj;*/
 }
 
 static PyObject *_wrap_trace(PyObject *self, PyObject *args) {
-    PyObject * _resultobj;
+    return Py_None;
+/*    PyObject * _resultobj;
     unsigned int  _arg0;
 
     self = self;
@@ -4464,7 +4466,7 @@
     trace(_arg0);
     Py_INCREF(Py_None);
     _resultobj = Py_None;
-    return _resultobj;
+    return _resultobj;*/
 }
 
 static PyObject *_wrap__nc_visbuf(PyObject *self, PyObject *args) {
