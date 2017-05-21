--- src/forward.c.orig	2017-05-12 14:16:02 UTC
+++ src/forward.c
@@ -899,7 +899,7 @@ void reply_query(int fd, int family, tim
 		    status = dnssec_validate_ds(now, header, n, daemon->namebuff, daemon->keyname, forward->class);
 		  else
 		    status = dnssec_validate_reply(now, header, n, daemon->namebuff, daemon->keyname, &forward->class, 
-						   option_bool(OPT_DNSSEC_NO_SIGN) && (server->flags && SERV_DO_DNSSEC), NULL, NULL);
+						   option_bool(OPT_DNSSEC_NO_SIGN) && (server->flags & SERV_DO_DNSSEC), NULL, NULL);
 		}
 	      
 	      /* Can't validate, as we're missing key data. Put this
@@ -1477,7 +1477,7 @@ static int tcp_key_recurse(time_t now, i
 	new_status = dnssec_validate_ds(now, header, n, name, keyname, class);
       else 
 	new_status = dnssec_validate_reply(now, header, n, name, keyname, &class,
-					   option_bool(OPT_DNSSEC_NO_SIGN) && (server->flags && SERV_DO_DNSSEC), NULL, NULL);
+					   option_bool(OPT_DNSSEC_NO_SIGN) && (server->flags & SERV_DO_DNSSEC), NULL, NULL);
       
       if (new_status != STAT_NEED_DS && new_status != STAT_NEED_KEY)
 	break;
