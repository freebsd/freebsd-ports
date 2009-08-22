# New ports collection makefile for: ae_fonts_mono
# Date created:        August 22, 2003
# Whom:                Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=		ae_fonts_mono
PORTVERSION=		1.0
PORTREVISION=	2
CATEGORIES=		arabic
MASTER_SITES=		SF/arabeyes/Fonts/ae_fonts
DISTNAME=		ae_fonts_mono

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of PCF fonts that include Arabic glyphs

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11
USE_BZIP2=	yes

do-build:
	@mkfontdir ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/ae_fonts_mono
	@${INSTALL_DATA} ${WRKSRC}/*.pcf ${PREFIX}/lib/X11/fonts/ae_fonts_mono
	@${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/ae_fonts_mono

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} "s|LOCALBASE|${LOCALBASE}|g" \
		| ${SED} "s|PORTNAME|${PORTNAME}|g"

.include <bsd.port.mk>
