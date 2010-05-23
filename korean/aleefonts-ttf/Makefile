# New ports collection makefile for:	aleefonts-ttf
# Date created:		23 July 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	aleefonts
PORTVERSION=	11.5
CATEGORIES=	korean x11-fonts
MASTER_SITES=	DEBIAN
MASTER_SITE_SUBDIR=	pool/main/t/ttf-alee
PKGNAMESUFFIX=	-ttf
DISTNAME=	ttf-alee_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A-Lee's Hangul truetype fonts #'

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
FONTLIST=	Bandal EunjinNakseo Bangwool Eunjin Guseul

do-install:
	${MKDIR} ${FONTDIR}
.for FONTNAME in ${FONTLIST}
	${INSTALL_DATA} '${WRKSRC}/${FONTNAME}.ttf' ${FONTDIR}
.endfor

.include <bsd.port.mk>
