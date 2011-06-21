--- kernel/OS/FreeBSD/os_freebsd.c.orig	2011-01-05 16:06:40.000000000 -0500
+++ kernel/OS/FreeBSD/os_freebsd.c	2011-06-21 17:52:41.000000000 -0400
@@ -315,7 +315,7 @@ oss_get_cardinfo (int cardnum, oss_card_
 
   if (cards[cardnum]->name != NULL)
     strncpy (ci->longname, cards[cardnum]->name, 128);
-  ci->shortname[127] = 0;
+  ci->longname[127] = 0;
 
   if (cards[cardnum]->nick != NULL)
     strncpy (ci->shortname, cards[cardnum]->nick, 16);
