# New ports collection makefile for:	wine-gecko-devel
# Date created:				2012-05-27
# Whom:					David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$

PORTNAME=	wine-gecko
DISTVERSION=	1.7
CATEGORIES=	emulators
MASTER_SITES=	SF/wine/Wine%20Gecko/${DISTVERSION}
DISTNAME=	wine_gecko-${DISTVERSION}-x86
EXTRACT_SUFX=	.msi
EXTRACT_ONLY=

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Gecko Layout Engine for Wine development branch (HTML support)

LICENSE=	MPL GPLv2 GPLv3 LGPL21 LGPL3
LICENSE_COMB=	multi

LATEST_LINK=	wine-gecko-devel
NO_BUILD=	yes
PLIST_SUB+=	GECKO_VERSION="${DISTVERSION}"
DATADIR=	${PREFIX}/share/wine
PLIST_FILES=	%%DATADIR%%/gecko/wine_gecko-%%GECKO_VERSION%%-x86.msi
PLIST_DIRSTRY=	%%DATADIR%%/gecko %%DATADIR%%

do-install:
	@${MKDIR} ${DATADIR}/gecko
	${INSTALL_DATA} ${DISTDIR}/wine_gecko-${DISTVERSION}-x86.msi \
		${DATADIR}/gecko

.include <bsd.port.mk>
