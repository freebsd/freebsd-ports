--- common/loader.l.orig	Sat Mar 27 06:59:28 2004
+++ common/loader.l	Thu Aug 26 05:54:55 2004
@@ -632,8 +632,8 @@
 ^maxsp{S}	op->stats.maxsp = IVAL;
 ^grace{S}	op->stats.grace = IVAL;
 ^maxgrace{S}	op->stats.maxgrace = IVAL;
-^exp{S}		op->stats.exp = atoll(yval());
-^perm_exp{S}	op->perm_exp = atoll(yval());
+^exp{S}		op->stats.exp = strtoll(yval(), (char **)NULL, 10);
+^perm_exp{S}	op->perm_exp = strtoll(yval(), (char **)NULL, 10);
 ^food{S}	op->stats.food = IVAL;
 ^dam{S}		op->stats.dam = IVAL;
 ^wc{S}		op->stats.wc = IVAL;
