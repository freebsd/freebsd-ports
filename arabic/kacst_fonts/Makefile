# New ports collection makefile for: kacst_fonts
# Date created:        August 22 2003
# Whom:                Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=		kacst_fonts
PORTVERSION=		1.4
CATEGORIES=		arabic
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	arabeyes
DISTNAME=		kacst_fonts_${PORTVERSION}

MAINTAINER=	samy@kerneled.com
COMMENT=	Truetype Arabic fonts created by KACST

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

USE_X_PREFIX=	yes
USE_BZIP2=	yes
WRKSRC=	${WRKDIR}/KacstArabicFonts-${PORTVERSION}

do-build:
	@ttmkfdir -c -d ${WRKSRC} > ${WRKSRC}/fonts.dir

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/kacst_fonts/
	@${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/lib/X11/fonts/kacst_fonts/
	@${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/kacst_fonts/

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} "s|X11BASE|${X11BASE}|g" \
		| ${SED} "s|PORTNAME|${PORTNAME}|g"

.include <bsd.port.mk>
