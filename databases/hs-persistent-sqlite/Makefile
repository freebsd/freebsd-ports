# $FreeBSD$

PORTNAME=	persistent-sqlite
PORTVERSION=	2.2
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Backend for the persistent library using sqlite3

LICENSE=	MIT

USE_CABAL=	aeson>=0.6.2 conduit>=0.5.3 monad-control>=0.2 \
		monad-logger>=0.2.4 persistent>=2.2 resourcet>=1.1 \
		text>=0.7

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
