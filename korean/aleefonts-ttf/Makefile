# New ports collection makefile for:	aleefonts-ttf
# Date created:		23 July 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	aleefonts
PORTVERSION=	0.3
CATEGORIES=	korean x11-fonts
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/t/ttf-alee
PKGNAMESUFFIX=	-ttf
DISTNAME=	ttf-alee_${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	A-Lee's Hangul truetype fonts

USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
FONTLIST=	Eunjin Hmfs Ongdalsam

do-install:
	${MKDIR} ${FONTDIR}
.for FONTNAME in ${FONTLIST}
	${INSTALL_DATA} ${WRKSRC}/${FONTNAME}.ttf ${FONTDIR}
.endfor

.include <bsd.port.mk>
