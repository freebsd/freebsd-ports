# New ports collection makefile for:	tgif-j
# Version required:	2.16.12
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.4 1996/11/11 10:12:57 max Exp $
#

DISTNAME=	tgif-2.16-p12
PKGNAME=	jp-tgif-216-p12
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/tgif

PATCH_SITES=	ftp://ftp.eos.hokudai.ac.jp/pub/X/contrib/misc/tgif/
PATCHFILES=	tgif-2.16-p12.jp.gz \
		tgif-2.16-p12.jp.kinput2over-the-spotpatch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes

.include <bsd.port.mk>
