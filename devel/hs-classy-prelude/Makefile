# $FreeBSD$

PORTNAME=	classy-prelude
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Typeclass-based Prelude

LICENSE=	MIT

USE_CABAL=	basic-prelude>=0.3.8 chunked-data enclosed-exceptions \
		exceptions>=0.5 hashable lifted-base>=0.2 mono-traversable>=0.6.1 \
		semigroups stm system-filepath>=0.4 text unordered-containers \
		vector vector-instances

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
