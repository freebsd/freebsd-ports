# New ports collection makefile for:	buddha
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buddha
PORTVERSION=	0.4
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cs.mu.oz.au/~bjpop/buddha/download/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

PLIST_SUB+=	BUDDHA_VERSION=${PORTVERSION}

pre-build:
	@(cd ${WRKSRC} && ${GMAKE} depend)

.include <bsd.port.mk>
