# New ports collection makefile for:   green-card
# Date created:        01 June 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	green-card
PORTVERSION=	3.0.1
CATEGORIES=	devel haskell
MASTER_SITES=	http://haskell.org/greencard/downloads/
PKGNAMEPREFIX=	hs-
DISTNAME=	greencard-${GC_VERSION}-src

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A foreign function interface preprocessor for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/greencard-${GC_VERSION}
GC_VERSION=	3.01
GCLIBDIR=	${PREFIX}/lib/greencard-${GC_VERSION}
PLIST_SUB+=	GC_VERSION=${GC_VERSION}

USE_GMAKE=	yes
MAKE_ARGS=	FOR_SYSTEM=GHC

pre-install:
	${MKDIR} ${GCLIBDIR}/Foreign ${GCLIBDIR}/imports/Foreign

.include <bsd.port.mk>
