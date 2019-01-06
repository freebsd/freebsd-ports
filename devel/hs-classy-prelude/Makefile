# $FreeBSD$

PORTNAME=	classy-prelude
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Typeclass-based Prelude

LICENSE=	MIT

USE_CABAL=	async basic-prelude bifunctors chunked-data dlist \
		exceptions hashable lifted-async lifted-base monad-unlift \
		mono-traversable mono-traversable-instances mtl \
		mutable-containers primitive safe-exceptions say semigroups \
		stm-chans time-locale-compat transformers-base unliftio \
		unordered-containers vector vector-instances

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
