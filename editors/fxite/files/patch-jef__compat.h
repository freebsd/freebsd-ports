--- jef/compat.h.orig	2013-10-03 09:22:51 UTC
+++ jef/compat.h
@@ -1,3 +1,25 @@
+/*
+  FXiTe - The Free eXtensIble Text Editor
+  Copyright (c) 2009-2014 Jeffrey Pohlmeyer <yetanothergeek@gmail.com>
+
+  This program is free software; you can redistribute it and/or modify it
+  under the terms of the GNU General Public License version 3 as
+  published by the Free Software Foundation.
+
+  This software is distributed in the hope that it will be useful,
+  but WITHOUT ANY WARRANTY; without even the implied warranty of
+  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+  GNU General Public License for more details.
+
+  You should have received a copy of the GNU General Public License
+  along with this program; if not, write to the Free Software
+  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
+*/
+
+#if (FOX_MAJOR==1) && (FOX_MINOR==6) && !defined(FOX_1_6)
+# define FOX_1_6
+#endif
+
 #ifdef FOX_1_6
 # define ONE_SECOND ((FXuint)1000)
 # define PathMatch(pattern,file,flags) FXPath::match(pattern,file,flags)
@@ -20,8 +42,16 @@ FXbool LocaleIsUTF8();
 # define FILEMATCH_NOESCAPE FXPath::NoEscape
 # define FILEMATCH_FILE_NAME FXPath::PathName
 # define FILEMATCH_CASEFOLD FXPath::CaseFold
-# define REX_FORWARD    FXRex::Forward
-# define REX_BACKWARD   FXRex::Backward
+# if (FOX_MAJOR>1) || (FOX_MINOR>7) || (FOX_LEVEL>49)
+#  define FOX_1_7_50_OR_NEWER
+# endif
+# ifdef FOX_1_7_50_OR_NEWER
+#  define REX_FORWARD    0
+#  define REX_BACKWARD   0
+# else
+#  define REX_FORWARD    FXRex::Forward
+#  define REX_BACKWARD   FXRex::Backward
+# endif
 # define REX_CAPTURE    FXRex::Capture
 # define REX_NEWLINE    FXRex::Newline
 # define REX_NORMAL     FXRex::Normal
@@ -35,6 +65,9 @@ FXbool LocaleIsUTF8();
 # if (FOX_MAJOR>1)||(FOX_MINOR>7)||(FOX_LEVEL>26)
 #  define fxgetpid() (FXProcess::current())
 # endif
+# if (FOX_MAJOR>1) || (FOX_MINOR>7) || (FOX_LEVEL>44)
+#  define FOX_1_7_45_OR_NEWER
+# endif
 #endif
 
 
@@ -69,8 +102,31 @@ bool IsDesktopCurrent(FXMainWindow*tw);
 # endif
 #endif
 
+#ifdef FOX_1_7_45_OR_NEWER
+# define Dictionary FXDictionary
+# define DictKeyName(d,n)     ((d).key(n).text())
+# define TotalSlotsInDict(d)  ((d)->no())
+# define UsedSlotsInDict(d)   ((d)->used())
+# define ReplaceInDict(d,k,v) ((d)->at(k)=(v))
+# define LookupInDict(d,k)    ((d)->at(k))
+#else
+# define Dictionary FXDict
+# define DictKeyName(d,n)     ((d).key(n))
+# define TotalSlotsInDict(d)  ((d)->size())
+# define UsedSlotsInDict(d)   ((d)->no())
+# define ReplaceInDict(d,k,v) ((d)->replace((k),(v)))
+# define LookupInDict(d,k)    ((d)->find(k))
+#endif
 
 FXID GetNetActiveWindow();
 
 void WaitForWindowFocus(FXTopWindow*w, FXuint msecs=1000);
 
+// #define SetPadLRTB(o,l,r,t,b) \
+//   (o)->setPadLeft(l); \
+//   (o)->setPadRight(r); \
+//   (o)->setPadTop(t); \
+//   (o)->setPadBottom(b);
+// 
+// #define SetPad(o,p) SetPadLRTB(o,p,p,p,p)
+
