# $FreeBSD$

PORTNAME=	pool-conduit
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Resource pool allocations via ResourceT

LICENSE=	MIT

USE_CABAL=	monad-control resource-pool>=0.2.1 resourcet>=0.3 \
		transformers>=0.2.1

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
