# New ports collection makefile for: ae_fonts_mono
# Date created:        August 22, 2003
# Whom:                Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=		ae_fonts_mono
PORTVERSION=		1.0
CATEGORIES=		arabic
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	arabeyes
DISTNAME=		ae_fonts_mono

MAINTAINER=	samy@kerneled.com
COMMENT=	A collection of PCF fonts that include Arabic glyphs

BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes
USE_BZIP2=	yes

do-build:
	@mkfontdir ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/ae_fonts_mono
	@${INSTALL_DATA} ${WRKSRC}/*.pcf ${PREFIX}/lib/X11/fonts/ae_fonts_mono
	@${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/ae_fonts_mono

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} "s|X11BASE|${X11BASE}|g" \
		| ${SED} "s|PORTNAME|${PORTNAME}|g"

.include <bsd.port.mk>
