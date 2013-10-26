# $FreeBSD$

PORTNAME=	resource-pool
PORTVERSION=	0.2.1.1
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	High-performance striped resource pooling implementation

LICENSE=	BSD

USE_CABAL=	hashable monad-control>=0.2.0.1 stm transformers \
		transformers-base>=0.4 vector>=0.7

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
