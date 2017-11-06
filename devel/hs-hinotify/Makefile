# $FreeBSD$

PORTNAME=	hinotify
PORTVERSION=	0.3.9
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell binding to inotify

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libinotify.so:devel/libinotify

USE_CABAL=	async

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
