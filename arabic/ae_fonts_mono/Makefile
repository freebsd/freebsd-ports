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

USE_X_PREFIX=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.elif ${XFREE86_VERSION} == 3
BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86
.endif

do-build:
	@mkfontdir ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/ae_fonts_mono
	@${INSTALL_DATA} ${WRKSRC}/*.pcf ${PREFIX}/lib/X11/fonts/ae_fonts_mono
	@${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/ae_fonts_mono

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} "s|X11BASE|${X11BASE}|g" \
		| ${SED} "s|PORTNAME|${PORTNAME}|g"

.include <bsd.port.post.mk>
