# $FreeBSD$

PORTNAME=	either
PORTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Either monad transformer

LICENSE=	BSD

USE_CABAL=	MonadRandom mtl>=2.0 semigroupoids>=3 semigroups>=0.8.3.1 \
		transformers>=0.2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
