# New ports collection makefile for: lipsf
# Version required:	1.13c
# Date created:		6 Dec 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id$
#

DISTNAME=	lipsf113
PKGNAME=	jp-lipsf-1.13c
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.eos.hokudai.ac.jp/pub/tools/

PATCHFILES=	lipsf113c.patch.gz
PATCH_SITES=	ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=	mita@jp.FreeBSD.org

MANLANG=	ja_JP.EUC
MAN1=		lipsf.1 pols.1

DOCDIR=		${PREFIX}/share/doc/lipsf

post-install:
	${MKDIR} ${DOCDIR}
	(cd ${WRKSRC} ; \
	 ${INSTALL_DATA} HISTORY Install README TECHKNOW ${DOCDIR})

.include <bsd.port.mk>
