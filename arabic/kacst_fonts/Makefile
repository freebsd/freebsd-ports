# New ports collection makefile for: kacst_fonts
# Date created:        August 22 2003
# Whom:                Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	kacst_fonts
PORTVERSION=	2.01
CATEGORIES=	arabic
MASTER_SITES=	SF/arabeyes/${PORTNAME} \
		http://www.c-s.li/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	c-s@c-s.li
COMMENT=	Truetype Arabic fonts created by KACST

LICENSE=	GPLv2

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/KacstArabicFonts-${PORTVERSION}

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME="${PORTNAME}"

do-build:
	cd ${WRKDIR} && ttmkfdir -c -d ${WRKSRC} > ${WRKSRC}/fonts.dir

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/kacst_fonts/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/lib/X11/fonts/kacst_fonts/
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/kacst_fonts/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
