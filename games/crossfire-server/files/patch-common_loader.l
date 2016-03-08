--- common/loader.l.orig	2014-04-05 22:30:50 UTC
+++ common/loader.l
@@ -858,8 +858,8 @@ A       .+
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
