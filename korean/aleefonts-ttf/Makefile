# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	aleefonts
PORTVERSION=	12
PORTREVISION=	1
CATEGORIES=	korean x11-fonts
MASTER_SITES=	DEBIAN/pool/main/t/ttf-alee
PKGNAMESUFFIX=	-ttf
DISTNAME=	ttf-alee_${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	A-Lee's Hangul truetype fonts #'

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fonts

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTLIST=	Bandal Bangwool Eunjin EunjinNakseo Guseul
FONTFILES=	${FONTLIST:S/$/.ttf/}
NO_BUILD=	yes

PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FONTFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
