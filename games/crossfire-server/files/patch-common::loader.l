--- common/loader.l.orig	2010-04-26 15:23:21.000000000 +0900
+++ common/loader.l	2010-05-25 04:25:03.000000000 +0900
@@ -830,8 +830,8 @@
 ^maxsp{S}           op->stats.maxsp = IVAL;
 ^grace{S}           op->stats.grace = IVAL;
 ^maxgrace{S}        op->stats.maxgrace = IVAL;
-^exp{S}             op->stats.exp = atoll(yval());
-^perm_exp{S}        op->perm_exp = atoll(yval());
+^exp{S}             op->stats.exp = strtoll(yval(), (char **)NULL, 10);
+^perm_exp{S}        op->perm_exp = strtoll(yval(), (char **)NULL, 10);
 ^food{S}            op->stats.food = IVAL;
 ^dam{S}             op->stats.dam = IVAL;
 ^wc{S}              op->stats.wc = IVAL;
