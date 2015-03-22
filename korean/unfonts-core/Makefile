# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unfonts
PORTVERSION?=	1.0.2.080608
PORTREVISION?=	2
CATEGORIES=	korean x11-fonts
MASTER_SITES?=	http://kldp.net/frs/download.php/4695/
PKGNAMESUFFIX=	-${FONTCAT}
DISTNAME=	un-fonts${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	GPL'd Korean TrueType Fonts by UN Koaunghi (${FONTCAT})

LICENSE=	GPLv2
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		fonts
NO_BUILD=	yes

DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTCAT}-ttf

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
