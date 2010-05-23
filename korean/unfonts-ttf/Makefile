# New ports collection makefile for:	unfonts-ttf
# Date created:		27 September 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	unfonts
PORTVERSION=	1.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	korean x11-fonts
MASTER_SITES=	http://kldp.net/frs/download.php/1425/:core \
		http://kldp.net/frs/download.php/1435/:extra
PKGNAMESUFFIX=	-ttf
DISTFILES=	un-fonts-core-${PORTVERSION}.tar.gz:core \
		un-fonts-extra-${PORTVERSION}.tar.gz:extra

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPL'd Korean TrueType Fonts by UN Koaunghi

WRKSRC=		${WRKDIR}/un-fonts
NO_BUILD=	yes
FONTDIR=	${PREFIX}/lib/X11/fonts/TrueType
FONTLIST=	UnBatang UnBatangBold UnBom UnDotum UnDotumBold \
		UnGraphic UnGraphicBold UnGungseo UnJamoBatang \
		UnJamoDotum UnJamoNovel UnJamoSora UnPen UnPenheulim \
		UnPilgi UnPilgiBold UnShinmun UnTaza UnYetgul

do-install:
	${MKDIR} ${FONTDIR}
.for FONTNAME in ${FONTLIST}
	${INSTALL_DATA} ${WRKSRC}/${FONTNAME}.ttf ${FONTDIR}
.endfor

.include <bsd.port.mk>
