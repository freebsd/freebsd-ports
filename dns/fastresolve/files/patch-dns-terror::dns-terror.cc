--- dns-terror/dns-terror.cc.orig	Mon Oct  4 13:28:02 2004
+++ dns-terror/dns-terror.cc	Mon Oct  4 13:28:53 2004
@@ -331,8 +331,7 @@
   }
   
   r = adns_submit(ads, rev, adns_r_ptr_raw,
-		  (enum adns_queryflags)
-		  (adns_qf_quoteok_cname|adns_qf_quoteok_anshost), lp, &qu);
+		  adns_queryflags (adns_qf_quoteok_cname|adns_qf_quoteok_anshost), lp, &qu);
   if (r)
     fatal_errno("adns_submit", r);
   if (verbose)
