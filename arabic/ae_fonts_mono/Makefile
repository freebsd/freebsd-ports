# Created by: Samy Al Bahra <samy@kerneled.com>
# $FreeBSD$

PORTNAME=	ae_fonts_mono
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	arabic x11-fonts
MASTER_SITES=	SF/arabeyes/Fonts/ae_fonts
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of PCF fonts that include Arabic glyphs

USES=		fonts tar:bzip2
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_FILES=	${FONTSDIR}/10x21.pcf

do-install:
	@${MKDIR} ${STAGEDIR}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf ${STAGEDIR}/${FONTSDIR}

.include <bsd.port.mk>
