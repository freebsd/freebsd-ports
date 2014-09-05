# Created by: jmz
# $FreeBSD$

PORTNAME=	xjewel
PORTVERSION=	1.6
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib
EXTRACT_SUFX=	.tar.z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 dropping jewels game

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USES=		imake
USE_XORG=	x11 xext

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	FONTSDIR="${FONTSDIR}"

PLIST_SUB=	FONTSDIR="${FONTSDIR}"

DESKTOP_ENTRIES="XJewel" "" "" "${PORTNAME}" "" ""

FONTSDIR=	lib/X11/fonts/local

post-install:
	(cd ${WRKSRC}/bitmaps && ${INSTALL_DATA} seven_seg.pcf.gz \
		${STAGEDIR}${PREFIX}/${FONTSDIR})

.include <bsd.port.mk>
