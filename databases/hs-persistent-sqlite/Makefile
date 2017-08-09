# $FreeBSD$

PORTNAME=	persistent-sqlite
PORTVERSION=	2.6.2
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Backend for the persistent library using sqlite3

LICENSE=	MIT

USE_CABAL=	aeson conduit microlens-th monad-control monad-logger \
		old-locale persistent resource-pool resourcet text \
		unordered-containers

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
