# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unfonts
PORTVERSION=	1.0.2.080608
PORTREVISION?=	4
CATEGORIES=	korean x11-fonts
MASTER_SITES=	https://kldp.net/unfonts/release/
PKGNAMESUFFIX=	-${FONTCAT}
DISTNAME=	${FILEID}-un-fonts${PKGNAMESUFFIX}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	GPL'd Korean TrueType Fonts by UN Koaunghi (${FONTCAT})

LICENSE=	GPLv2
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		fonts
NO_BUILD=	yes

DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTCAT}-ttf
FILEID?=	2607

WRKSRC=		${WRKDIR}/un-fonts
FONTNAME=	${PORTNAME}-${FONTCAT}
FONTCAT?=	core
FONTLIST?=	UnBatang \
		UnBatangBold \
		UnDinaru \
		UnDinaruBold \
		UnDinaruLight \
		UnDotum \
		UnDotumBold \
		UnGraphic \
		UnGraphicBold \
		UnGungseo \
		UnPilgi \
		UnPilgiBold
FONTFILES=	${FONTLIST:S/$/.ttf/}

PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FONTFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
