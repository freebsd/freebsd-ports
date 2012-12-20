# $FreeBSD$

PORTNAME=	persistent-sqlite
PORTVERSION=	1.0.1
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Backend for the persistent library using sqlite3

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 conduit>=0.5 monad-control>=0.2 persistent>=1.0 \
		text>=0.7 transformers>=0.2.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
