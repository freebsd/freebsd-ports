# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	wine-mono
DISTVERSION=	4.9.4
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://dl.winehq.org/wine/wine-mono/${DISTVERSION}/
EXTRACT_SUFX=	.msi
EXTRACT_ONLY=

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Mono .NET implementation for Wine

LICENSE=	MIT GPLv2 LGPL20
LICENSE_COMB=	multi

PORTSCOUT=	ignore:1	# for newer versions see emulators/wine-mono-devel

CONFLICTS_INSTALL=	wine-mono-devel-[0-9]*

NO_BUILD=	yes
PLIST_SUB+=	MONO_VERSION="${DISTVERSION}"
DATADIR=	${PREFIX}/share/wine
PLIST_FILES=	${DATADIR}/mono/${DISTNAME}.msi

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/mono
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.msi \
		${STAGEDIR}${DATADIR}/mono

.include <bsd.port.mk>
