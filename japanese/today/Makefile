# New ports collection makefile for:	today
# Version required:	2.10b
# Date created:		24 June 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
# $Id: Makefile,v 1.6 1997/09/19 11:57:50 max Exp $
#

DISTNAME=	td210bs
PKGNAME=	ja-today-2.10b
CATEGORIES=	japanese games
MASTER_SITES=	ftp://ftp.waseda.ac.jp/pub/archive/fj.binaries.msdos/
EXTRACT_SUFX=	.lzh
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} td210bm.lzh

MAINTAINER=	rewsirow@ff.iij4u.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfqw=${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes

post-extract:
	@${ECHO_MSG} "===>  Extracting tbl file for ${DISTNAME}"
	@(cd ${WRKDIR}; lha xqf tbl.lzh )
	@${ECHO_MSG} "===>  Renaming file for ${DISTNAME}"
	@(cd ${WRKDIR}; \
	${MV} rdcalend.c rdcalendar.c ; \
	${MV} rdcalend.h rdcalendar.h )
	@${ECHO_MSG} "===>  Converting Kanji code for ${DISTNAME}"
	@(cd ${WRKDIR}; \
	for i in *.c *.h *.doc *.cnf birthday.tbl event*.tbl flower.tbl \
		 gengo.tbl hist??.tbl history.tbl holiday.tbl magazin.tbl \
		 monthly.tbl week.tbl; \
	do \
		${SED} 's/.$$//' $$i | nkf -e > $$i.tmp ;\
		${MV} -f $$i.tmp $$i ; \
	done)

pre-patch:
	@${ECHO_MSG} "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
