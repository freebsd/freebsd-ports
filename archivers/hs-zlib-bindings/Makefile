# $FreeBSD$

PORTNAME=	zlib-bindings
PORTVERSION=	0.1.1.5
PORTREVISION=	5
CATEGORIES=	archivers haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Low-level bindings to the zlib package

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	zlib>=0.5.2.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
