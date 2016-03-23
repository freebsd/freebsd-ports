--- dns-terror/dns-terror.cc.orig	2003-05-17 18:04:55 UTC
+++ dns-terror/dns-terror.cc
@@ -331,8 +331,7 @@ submit_query(adns_state ads, BoolStringM
   }
   
   r = adns_submit(ads, rev, adns_r_ptr_raw,
-		  (enum adns_queryflags)
-		  (adns_qf_quoteok_cname|adns_qf_quoteok_anshost), lp, &qu);
+		  adns_queryflags (adns_qf_quoteok_cname|adns_qf_quoteok_anshost), lp, &qu);
   if (r)
     fatal_errno("adns_submit", r);
   if (verbose)
