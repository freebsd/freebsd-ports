--- src/nes/unif.cpp.orig	2014-10-01 15:17:53 UTC
+++ src/nes/unif.cpp
@@ -191,7 +191,7 @@
  MDFN_printf(_("Dumped by: %s\n"),name);
  MDFN_printf(_("Dumped with: %s\n"),method);
  {
-  char *months[12]={_("January"),_("February"),_("March"),_("April"),_("May"),_("June"),_("July"),
+  const char *months[12]={_("January"),_("February"),_("March"),_("April"),_("May"),_("June"),_("July"),
 		    _("August"),_("September"),_("October"),_("November"),_("December")};
   MDFN_printf(_("Dumped on: %s %d, %d\n"),months[(m-1)%12],d,y);
  }
