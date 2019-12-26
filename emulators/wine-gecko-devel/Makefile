# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	wine-gecko
DISTVERSION=	2.47.1
CATEGORIES=	emulators
MASTER_SITES=	http://dl.winehq.org/wine/wine-gecko/${DISTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	wine-gecko-${DISTVERSION}-x86
EXTRACT_SUFX=	.msi
EXTRACT_ONLY=

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Gecko Layout Engine for Wine development branch (HTML support)

LICENSE=	MPL20 GPLv2 GPLv3 LGPL21 LGPL3
LICENSE_COMB=	multi

CONFLICTS_INSTALL=	wine-gecko-[0-9]*

NO_BUILD=	yes
PLIST_SUB+=	GECKO_VERSION="${DISTVERSION}"
DATADIR=	${PREFIX}/share/wine
PLIST_FILES=	${DATADIR}/gecko/${DISTNAME}.msi

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/gecko
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.msi \
		${STAGEDIR}${DATADIR}/gecko

.include <bsd.port.mk>
