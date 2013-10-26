# $FreeBSD$

PORTNAME=	monad-logger
PORTVERSION=	0.3.1.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Class of monads which can log messages

LICENSE=	MIT

USE_CABAL=	conduit>=1.0 fast-logger>=0.2 monad-control mtl \
		resourcet>=0.4 text transformers transformers-base

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
