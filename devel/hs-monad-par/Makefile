# $FreeBSD$

PORTNAME=	monad-par
PORTVERSION=	0.3.4.8
PORTREVISION=	4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for parallel programming based on a monad

LICENSE=	BSD3CLAUSE

USE_CABAL=	abstract-deque>=0.1.4 abstract-par monad-par-extras>=0.3 \
		mtl>=2.0.1.0 mwc-random>=0.11 parallel>=3.1

FLAGS_DISABLE=	chaselev newgeneric

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
