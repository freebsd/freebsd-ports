# New ports collection makefile for:	wine-mono-devel
# Date created:				2012-08-08
# Whom:					David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$

PORTNAME=	wine-mono
DISTVERSION=	0.0.4
CATEGORIES=	emulators
MASTER_SITES=	SF/wine/Wine%20Mono/${DISTVERSION}
EXTRACT_SUFX=	.msi
EXTRACT_ONLY=

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Mono .NET implementation for Wine development branch (HTML support)

LICENSE=	MIT GPLv2 LGPL20
LICENSE_COMB=	multi

NO_BUILD=	yes
PLIST_SUB+=	MONO_VERSION="${DISTVERSION}"
DATADIR=	${PREFIX}/share/wine
PLIST_FILES=	%%DATADIR%%/mono/wine-mono-%%MONO_VERSION%%.msi
PLIST_DIRSTRY=	%%DATADIR%%/mono %%DATADIR%%

do-install:
	@${MKDIR} ${DATADIR}/mono
	${INSTALL_DATA} ${DISTDIR}/wine-mono-${DISTVERSION}.msi \
		${DATADIR}/mono

.include <bsd.port.mk>
