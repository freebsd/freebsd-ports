# Created by: Samy Al Bahra <samy@kerneled.com>
# $FreeBSD$

PORTNAME=	ae_fonts_mono
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	arabic x11-fonts
MASTER_SITES=	SF/arabeyes/Fonts/ae_fonts
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of PCF fonts that include Arabic glyphs

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11
USE_BZIP2=	yes
SUB_FILES=	pkg-message

do-build:
	@mkfontdir ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/X11/fonts/ae_fonts_mono
	${INSTALL_DATA} ${WRKSRC}/*.pcf ${WRKSRC}/fonts.dir \
		${STAGEDIR}/${PREFIX}/lib/X11/fonts/ae_fonts_mono

.include <bsd.port.mk>
