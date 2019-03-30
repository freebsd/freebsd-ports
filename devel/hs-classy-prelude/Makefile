# $FreeBSD$

PORTNAME=	classy-prelude
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Typeclass-based Prelude

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	async basic-prelude bifunctors chunked-data dlist \
		exceptions hashable lifted-async lifted-base monad-unlift \
		mono-traversable mono-traversable-instances mtl \
		mutable-containers primitive safe-exceptions say semigroups \
		stm-chans time-locale-compat transformers-base unliftio \
		unordered-containers vector vector-instances

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
