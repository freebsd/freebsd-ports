$FreeBSD$

--- rogue/message.c	20 Jul 2000 10:35:07 -0000	1.7.2.1
+++ rogue/message.c	21 Aug 2003 19:58:51 -0000
@@ -60,7 +60,7 @@
 char msgs[NMESSAGES][DCOLS] = {"", "", "", "", ""};
 short msg_col = 0, imsg = -1;
 boolean msg_cleared = 1, rmsg = 0;
-char hunger_str[8] = "";
+char hunger_str[HUNGER_STR_LEN] = "";
 const char *more = "-more-";
 
 extern boolean cant_int, did_int, interrupted, save_is_interactive, flush;
