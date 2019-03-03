# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	wine-mono
DISTVERSION=	4.8.0
CATEGORIES=	emulators
MASTER_SITES=	http://dl.winehq.org/wine/wine-mono/${DISTVERSION}/
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.msi
EXTRACT_ONLY=

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Mono .NET implementation for Wine development branch (HTML support)

LICENSE=	MIT GPLv2 LGPL20
LICENSE_COMB=	multi

CONFLICTS_INSTALL=	wine-mono-[0-9]*

NO_BUILD=	yes
PLIST_SUB+=	MONO_VERSION="${DISTVERSION}"
DATADIR=	${PREFIX}/share/wine
PLIST_FILES=	${DATADIR}/mono/wine-mono-${DISTVERSION}.msi

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/mono
	${INSTALL_DATA} ${DISTDIR}/wine-mono-${DISTVERSION}.msi \
		${STAGEDIR}${DATADIR}/mono

.include <bsd.port.mk>
