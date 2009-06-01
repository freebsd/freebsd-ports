--- po/nls.mk.orig	2009-01-21 15:32:14.000000000 +0100
+++ po/nls.mk	2009-06-01 12:30:35.000000000 +0200
@@ -8,6 +8,9 @@
 	${MSGCAT} libhylafax/messages.pot hylafax-client/messages.pot hylafax-server/messages.pot >> $@.tmp
 	mv $@.tmp $@
 
+FIXMATCH=	${DEPTH}/*/messages.po
+SYSUSER=	root
+SYSGROUP=	wheel
 
 # A bit more trikery here
 # We want $(wildcard...) because we don't want to try to "rebuild" thes messages.pot
@@ -15,18 +18,18 @@
 # But legacy makes (SCO) don't support $(wildcard...).  Luckly, they don't support $(...)
 # At all, so they just drop it all.  Real makes support $(wildcard)
 # That's why we use the $(...${...})
-libhylafax/messages.pot: $(wildcard ${patsubst %, ${DEPTH}/%/messages.po, libhylafax})
+libhylafax/messages.pot: ${FIXMATCH:Mlibhylafax}
 	test -d libhylafax || mkdir libhylafax
 	${MSGCAT} $^ > $@.tmp
 	mv $@.tmp $@
 
-hylafax-client/messages.pot: $(wildcard ${patsubst %, ${DEPTH}/%/messages.po, ${CLIENTS}})
+hylafax-client/messages.pot: ${FIXMATCH:Mclient}
 	test -d hylafax-client || mkdir hylafax-client
 	${MSGCAT} $^ > $@.tmp
 	mv $@.tmp $@
 
 
-hylafax-server/messages.pot: $(wildcard ${patsubst %, ${DEPTH}/%/messages.po, ${SERVERS}})
+hylafax-server/messages.pot: ${FIXMATCH:Mserver}
 	test -d hylafax-server || mkdir hylafax-server
 	${MSGCAT} $^ > $@.tmp
 	mv $@.tmp $@
