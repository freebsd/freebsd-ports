--- ../solenv/inc/unxfbsdi.mk	2001/10/24 17:21:47	1.4
+++ ../solenv/inc/unxfbsdi.mk	2002/03/03 19:39:21
@@ -42,12 +42,12 @@
 LINKFLAGS=
 LINKFLAGSAPPGUI= -Wl,-export-dynamic
 LINKFLAGSAPPCUI= -Wl,-export-dynamic
-LINKFLAGSSHLGUI= -shared
-LINKFLAGSSHLCUI= -shared
+LINKFLAGSSHLGUI= -shared -Wl,-export-dynamic
+LINKFLAGSSHLCUI= -shared -Wl,-export-dynamic
 LINKFLAGSTACK=
 LINKFLAGSPROF=
 LINKFLAGSDEBUG=-g
-LINKFLAGSOPT=
+LINKFLAGSOPT=-O
 
 .IF "$(NO_BSYMBOLIC)"==""
 .IF "$(PRJNAME)" != "envtest"
