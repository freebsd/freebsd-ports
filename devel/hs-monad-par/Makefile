# $FreeBSD$

PORTNAME=	monad-par
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A library for parallel programming based on a monad

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	abstract-deque>=0.1.4 abstract-par monad-par-extras \
		mtl>=2.0.1.0 mwc-random>=0.11 parallel>=3.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
