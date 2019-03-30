# $FreeBSD$

PORTNAME=	zip-archive
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	archivers haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for creating and modifying zip archives

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	digest>=0.0.0.1 mtl old-time zlib

FLAGS_DEFINE=		EXECUTABLE

EXECUTABLE_DESC=		Build the Zip executable
EXECUTABLE_FLAG_ENABLE=		executable
EXECUTABLE_FLAG_EXECUTABLE=	Zip

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
