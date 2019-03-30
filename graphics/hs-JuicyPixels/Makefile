# $FreeBSD$

PORTNAME=	JuicyPixels
PORTVERSION=	3.3.3
PORTREVISION=	1
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Picture loading/serialization

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	mtl>=1.1 primitive>=0.4 vector>=0.9 zlib>=0.5.3.1

FLAGS_DEFINE=		MMAP

MMAP_DESC=		Enable file loading via mmap()
MMAP_FLAG_ENABLE=	Mmap
MMAP_FLAG_CABAL=	mmap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
