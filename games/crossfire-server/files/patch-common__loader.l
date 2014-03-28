--- ./common/loader.l.orig	2012-03-18 07:31:50.000000000 +0100
+++ ./common/loader.l	2014-03-27 18:59:52.047466456 +0100
@@ -856,8 +856,8 @@
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
