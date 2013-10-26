# $FreeBSD$

PORTNAME=	lifted-base
PORTVERSION=	0.2.0.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Lifted IO operations from the base library

LICENSE=	BSD

USE_CABAL=	base-unicode-symbols>=0.1.1 monad-control>=0.3 \
		transformers-base>=0.4

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
