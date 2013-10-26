# $FreeBSD$

PORTNAME=	monad-par
PORTVERSION=	0.3.4.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for parallel programming based on a monad

LICENSE=	BSD

USE_CABAL=	abstract-deque>=0.1.4 abstract-par monad-par-extras \
		mtl>=2.0.1.0 mwc-random>=0.11 parallel>=3.1

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
