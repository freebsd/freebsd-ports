# New ports collection makefile for:	today
# Version required:	2.10b
# Date created:		24 June 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
# $Id: Makefile,v 1.2 1996/11/18 11:30:48 asami Exp $
#

DISTNAME=	td210bs
PKGNAME=	jp-today-2.10b
CATEGORIES=	japanese games
MASTER_SITES=	ftp://ftp.waseda.ac.jp/pub/archive/fj.binaries.msdos/

DISTFILES=	td210bs.lzh td210bm.lzh

MAINTAINER=	pcs51674@asciinet.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha
BUILD_DEPENDS+=	nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_SUFX=	.lzh
EXTRACT_BEFORE_ARGS=	xfw=${WRKDIR}
NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p1

post-extract:
	@echo "===>  Extracting tbl file for ${DISTNAME}"
	@(cd ${WRKDIR}; lha xf tbl.lzh )
	@echo "===>  Renaming file for ${DISTNAME}"
	@(cd ${WRKDIR}; \
	mv rdcalend.c rdcalendar.c ; \
	mv rdcalend.h rdcalendar.h )
	@echo "===>  Converting Kanji code for ${DISTNAME}"
	@(cd ${WRKDIR}; \
	for i in *.c *.h *.doc *.cnf birthday.tbl event*.tbl flower.tbl \
		 gengo.tbl hist??.tbl history.tbl holiday.tbl magazin.tbl \
		 monthly.tbl week.tbl; \
	do \
		echo $$i ; \
		sed 's/.$$//' $$i | nkf -e > $$i.tmp ;\
		mv -f $$i.tmp $$i ; \
	done)

pre-patch:
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
