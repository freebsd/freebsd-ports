# New ports collection makefile for:	tgif-j
# Version required:	3.0.13
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.7 1997/09/14 21:36:07 max Exp $
#

DISTNAME=	tgif-3.0-p13
PKGNAME=	ja-tgif-3.0.13
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		http://www.jp.freebsd.org/~mita/LOCAL_PORTS/
MASTER_SITE_SUBDIR=	applications/tgif
DISTFILES=	tgif-3.0-p13.tar.gz tgif-3.0J0.12-p13-JIS-patch.gz

PATCH_SITES=	ftp://ftp.mei.co.jp/free/X11/X/applications/drawing/tgif/
PATCHFILES=	tgif-3.0J0.12-p13-patch.gz
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
MANCOMPRESSED=		yes
EXTRACT_ONLY=	tgif-3.0-p13.tar.gz

post-patch:
	 ${SETENV} DISTDIR="${DISTDIR}" GZCAT="${GZCAT}" \
	 PATCH="${PATCH}" PATCH_DIST_ARGS="${PATCH_DIST_ARGS}" ${SH} ${FILESDIR}/setup.sh

.include <bsd.port.mk>
