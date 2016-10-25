--- src/cdrom/CDAccess_CCD.cpp.orig	2015-02-22 20:50:48 UTC
+++ src/cdrom/CDAccess_CCD.cpp
@@ -346,7 +346,7 @@ void CDAccess_CCD::CheckSubQSanity(void)
      if(prev_lba != INT_MAX && abs(lba - prev_lba) > 100)
       throw MDFN_Error(0, _("Garbage subchannel Q data detected(excessively large jump in AMSF)"));
 
-     if(abs(lba - s) > 100)
+     if(abs((long long)lba - (long long)s) > 100)
       throw MDFN_Error(0, _("Garbage subchannel Q data detected(AMSF value is out of tolerance)"));
 
      prev_lba = lba;
