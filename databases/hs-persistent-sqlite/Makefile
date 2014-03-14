# $FreeBSD$

PORTNAME=	persistent-sqlite
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Backend for the persistent library using sqlite3

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 conduit>=0.5.3 monad-control>=0.2 \
		monad-logger>=0.2.4 persistent>=1.2 text>=0.7 \
		transformers>=0.2.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
