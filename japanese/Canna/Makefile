# New ports collection makefile for:	Canna
# Version required:	3.2p2
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.18 1997/10/17 15:59:04 itojun Exp $
#

DISTNAME=	Canna32p2
PKGNAME=	ja-Canna-3.2.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna32/

MAINTAINER=	max@FreeBSD.ORG

USE_IMAKE=	yes
PREFIX?=	${LOCALBASE}
ALL_TARGET=	canna

MAN1=	cannaserver.1 ctow.1 dicar.1 dpromdic.1 splitword.1 wtoc.1 \
	mkromdic.1 mkbindic.1 dpbindic.1 cannakill.1 canvert.1 \
	cannacheck.1 cannastat.1 cshost.1 catdic.1 cpdic.1 lsdic.1 \
	mkdic.1 mvdic.1 rmdic.1 addwords.1 delwords.1
MAN3= 	RkRgnBun.3 RkDefineDic.3 RkDeleteDic.3 RkEndBun.3 \
	RkEnlarge.3 RkFinalize.3 RkGetDicList.3 RkGetKanji.3 \
	RkGetLex.3 RkGetStat.3 RkGetYomi.3 RkGoto.3 RkInitialize.3 \
	RkIntro.3 RkLeft.3 RkMountD.3 RkNext.3 RkNfer.3 RkPrev.3 \
	RkRemountDic.3 RkResize.3 RkRight.3 RkShorten.3 RkStoreYomi.3 \
	RkUnmountDic.3 RkXfer.3 cannalib.3 uilib.3 RkCloseRoma.3 \
	RkCvtEuc.3 RkCvtHan.3 RkCvtHira.3 RkCvtKana.3 RkCvtRoma.3 \
	RkCvtZen.3 RkMapPhonogram.3 RkMapRoma.3 RkOpenRoma.3

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/canna.sh

pre-install:
	${MKDIR} /var/run/canna
	chown bin.bin /var/run/canna

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	@if [ ! -f ${STARTUP_SCRIPT} ]; then 				\
		echo "Installing ${STARTUP_SCRIPT} startup file."; 	\
		echo '#!/bin/sh' > ${STARTUP_SCRIPT}; 			\
		echo 'canna=${PREFIX}/sbin/cannaserver' 		\
		  >> ${STARTUP_SCRIPT} ;				\
		echo 'if [ -f $$canna ]; then' >> ${STARTUP_SCRIPT} ;	\
		echo '    rm -f /var/run/canna/Canna.pid' >> ${STARTUP_SCRIPT};\
		echo '    mkdir -p /var/run/canna' >> ${STARTUP_SCRIPT};\
		echo '    chown bin:bin /var/run/canna' >> ${STARTUP_SCRIPT};\
		echo "    echo -n ' Canna'" >> ${STARTUP_SCRIPT};	\
		echo '     $$canna' >> ${STARTUP_SCRIPT} ;		\
		echo "fi" >> ${STARTUP_SCRIPT} ;			\
		chmod 755 ${STARTUP_SCRIPT} ;				\
		chown bin.bin ${STARTUP_SCRIPT};			\
	fi
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
