--- ros/src/WOKLibs/pkgIndex.tcl.orig	Fri Sep 21 10:07:48 2001
+++ ros/src/WOKLibs/pkgIndex.tcl	Tue Aug  1 08:49:51 2006
@@ -30,6 +30,36 @@
 
 ###########################################
 
+if { $tcl_platform(os) == "FreeBSD" }  {
+package ifneeded Woktools 2.0 "tclPkgSetup $dir/bsd Woktools 2.0 {
+                                        {libwoktoolscmd.so load {
+					    msgprint msgisset msgissetcmd msgissetlong msgset msgsetcmd
+					    msgsetlong msgunset msgunsetcmd msgunsetlong msgsetheader
+					    msgunsetheader msgissetheader msginfo}}}"
+
+package ifneeded Wokutils 2.0 "tclPkgSetup $dir Wokutils 2.0 {
+    {libwokutilscmd.so load { wokcmp} } }"
+
+package ifneeded Wok 2.0 "package require Woktools;
+                             tclPkgSetup $dir/bsd Wok 2.0 {
+				 {libwokcmd.so load {
+				     Sinfo Wcreate Winfo Wrm Wdeclare fcreate finfo frm pinfo screate
+				     sinfo srm ucreate uinfo umpmake umake urm w_info wcreate
+				     wokcd wokclose wokinfo wokparam wokprofile wokenv wrm wmove
+				     stepinputaddstepinputinfo stepoutputadd stepoutputinfo stepaddexecdepitem }}}"
+
+package ifneeded Ms 2.0 "package require Woktools;
+                             tclPkgSetup $dir/bsd Ms 2.0 {
+				 {libmscmd.so load {
+				     mscheck msclear msclinfo msextract msgeninfo msinfo msinstinfo
+				     msmmthinfo msmthinfo mspkinfo msschinfo msrm msstdinfo
+				     mstranslate msxmthinfo}}}"
+
+
+				 }
+
+###########################################
+
 if { $tcl_platform(os) == "SunOS" }  {
 package ifneeded Woktools 2.0 "tclPkgSetup $dir/sun Woktools 2.0 {
                                         {libwoktoolscmd.so load {
