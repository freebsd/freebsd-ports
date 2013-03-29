# $FreeBSD$

PORTNAME=	classy-prelude
PORTVERSION=	0.5.3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A typeclass-based Prelude

LICENSE=	MIT

CABAL_SETUP=	Setup.hs

USE_CABAL=	basic-prelude>=0.3.4 hashable lifted-base>=0.2 \
		system-filepath>=0.4 text transformers unordered-containers \
		vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
