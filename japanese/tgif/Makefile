# New ports collection makefile for:	tgif-j
# Version required:	3.0.13
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.6 1997/08/30 15:44:34 max Exp $
#

DISTNAME=	tgif-3.0-p13
PKGNAME=	ja-tgif-3.0.13
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/tgif

PATCH_SITES=	ftp://ftp.mei.co.jp/free/X11/X/applications/drawing/tgif/
PATCHFILES=	tgif-3.0J0.12-p13-patch.gz

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
PATCH_DIST_STRIP=	-p1
MAN1=			tgif.1 prtgif.1
MANCOMPRESSED=		yes

.include <bsd.port.mk>
