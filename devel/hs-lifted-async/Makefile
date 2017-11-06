# $FreeBSD$

PORTNAME=	lifted-async
PORTVERSION=	0.9.3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Run lifted IO operations asynchronously and wait for their results

LICENSE=	BSD3CLAUSE

USE_CABAL=	async>=2.0.1 constraints>=0.2 lifted-base>=0.2 \
		monad-control>=0.3.1 transformers-base>=0.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
