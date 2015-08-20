# $FreeBSD$

PORTNAME=	classy-prelude
PORTVERSION=	0.12.1.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Typeclass-based Prelude

LICENSE=	MIT

USE_CABAL=	basic-prelude>=0.4 bifunctors chunked-data dlist>=0.7 \
		enclosed-exceptions exceptions>=0.5 hashable lifted-base>=0.2 \
		mono-traversable>=0.9.1 mtl mutable-containers>=0.3 primitive \
		semigroups stm text time-locale-compat unordered-containers \
		vector vector-instances

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
