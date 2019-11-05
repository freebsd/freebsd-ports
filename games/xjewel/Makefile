# Created by: jmz
# $FreeBSD$

PORTNAME=	xjewel
PORTVERSION=	1.6
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib
EXTRACT_SUFX=	.tar.z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 dropping jewels game

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontscale>=0:x11-fonts/mkfontscale

USES=		fonts imake xorg
USE_XORG=	x11 xext

DESKTOP_ENTRIES="XJewel" "" "" "${PORTNAME}" "" ""

post-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC}/bitmaps && ${INSTALL_DATA} seven_seg.pcf.gz \
		${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>
