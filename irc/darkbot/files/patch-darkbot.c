--- darkbot.c.orig	Tue Oct 28 15:22:21 2003
+++ darkbot.c	Tue Oct 28 15:22:21 2003
@@ -3476,8 +3476,7 @@
           strlwr (s2);
           if (*s2 == '~') {
             S
-              ("PRIVMSG %s :%s, rdb files can only be called from the data of a topic, they cannot be used in the
- topic itself.\n",
+              ("PRIVMSG %s :%s, rdb files can only be called from the data of a topic, they cannot be used in the topic itself.\n",
                target, source);
             R;
           }
@@ -5026,14 +5025,12 @@
 #else
   if (pre_CLIENTS == 0 || pre_CLIENTS == L_CLIENTS) {
     S
-      ("PRIVMSG %s :\1ACTION \37(\37%2d servers\37)\37: %2d opers + \2%4d\2 users \37(\37%s%% %5d global \2!\2 %3
-ld avg\37)\37\1\n",
+      ("PRIVMSG %s :\1ACTION \37(\37%2d servers\37)\37: %2d opers + \2%4d\2 users \37(\37%s%% %5d global \2!\2 %3ld avg\37)\37\1\n",
        CHAN, NUM_SERV, IRCOPS, L_CLIENTS, tmp,
        G_USERS, G_USERS / NUM_SERV);}
   else
     S
-      ("PRIVMSG %s :\1ACTION \37(\37%2d servers\37)\37: %2d opers + \2%4d\2 users [\37%c%2d\37] \37(\37%s%% %5d g
-lobal \2!\2 %3ld avg\37)\37\1\n",
+      ("PRIVMSG %s :\1ACTION \37(\37%2d servers\37)\37: %2d opers + \2%4d\2 users [\37%c%2d\37] \37(\37%s%% %5d global \2!\2 %3ld avg\37)\37\1\n",
        CHAN, NUM_SERV, IRCOPS, L_CLIENTS,
        Stat[0], pre_CLIENTS, tmp, G_USERS, G_USERS / NUM_SERV);
 #endif
