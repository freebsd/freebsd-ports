# New ports collection makefile for:	tgif-j
# Version required:	3.0.18
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.10 1998/11/20 18:29:20 itojun Exp $
#

DISTNAME=	tgif-3.0.18
PKGNAME=	ja-tgif-3.0.18
CATEGORIES=	japanese
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/tgif

PATCH_SITES=	http://www.venus.dtinet.or.jp/~iisaka/
PATCHFILES=	tgif-3.0J0.12-p18-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
MAN1=			tgif.1 prtgif.1

.include <bsd.port.mk>
