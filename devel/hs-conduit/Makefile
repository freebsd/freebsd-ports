# $FreeBSD$

PORTNAME=	conduit
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Streaming data processing library

LICENSE=	BSD

USE_CABAL=	lifted-base>=0.1 mmorph monad-control>=0.3.1 resourcet>=0.4.3 \
		text>=0.11 transformers>=0.2.2 transformers-base>=0.4.1 \
		void>=0.5.5

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
