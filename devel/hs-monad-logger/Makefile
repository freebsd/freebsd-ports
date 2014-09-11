# $FreeBSD$

PORTNAME=	monad-logger
PORTVERSION=	0.3.7.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Class of monads which can log messages

LICENSE=	MIT

USE_CABAL=	blaze-builder conduit>=1.0 conduit-extra>=1.0 exceptions \
		fast-logger>=2.0 lifted-base monad-control monad-loops \
		mtl resourcet>=0.4 stm stm-chans text transformers-base

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
