# New ports collection makefile for:	tgif-j
# Version required:	3.0.18
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	tgif-3.0.18
PKGNAME=	ja-tgif-3.0.18
CATEGORIES=	japanese graphics
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		${MASTER_SITE_XCONTRIB} \
		${MASTER_SITE_PORTS_JP} \
		http://www.sunbit.or.jp/users/shin/software/
MASTER_SITE_SUBDIR=	applications/tgif
DISTFILES=	tgif-3.0.18.tar.gz tgif-3.0J0.12-p18-PSJISr1.gz

PATCH_SITES=	http://www.venus.dti.ne.jp/~iisaka/
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
EXTRACT_ONLY=	tgif-3.0.18.tar.gz
FETCH_CMD=	/usr/bin/fetch -Ab

post-patch:
	 ${SETENV} DISTDIR="${DISTDIR}" GZCAT="${GZCAT}" \
	 PATCH="${PATCH}" PATCH_DIST_ARGS="${PATCH_DIST_ARGS}" ${SH} ${FILESDIR}/setup.sh

.include <bsd.port.mk>
