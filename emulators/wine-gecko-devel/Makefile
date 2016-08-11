# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	wine-gecko
DISTVERSION=	2.47
CATEGORIES=	emulators
MASTER_SITES=	http://dl.winehq.org/wine/wine-gecko/${DISTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	wine_gecko-${DISTVERSION}-x86
EXTRACT_SUFX=	.msi
EXTRACT_ONLY=

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Gecko Layout Engine for Wine development branch (HTML support)

LICENSE=	MPL GPLv2 GPLv3 LGPL21 LGPL3
LICENSE_COMB=	multi

NO_BUILD=	yes
PLIST_SUB+=	GECKO_VERSION="${DISTVERSION}"
DATADIR=	${PREFIX}/share/wine
PLIST_FILES=	%%DATADIR%%/gecko/wine_gecko-%%GECKO_VERSION%%-x86.msi

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/gecko
	${INSTALL_DATA} ${DISTDIR}/wine_gecko-${DISTVERSION}-x86.msi \
		${STAGEDIR}${DATADIR}/gecko

.include <bsd.port.mk>
