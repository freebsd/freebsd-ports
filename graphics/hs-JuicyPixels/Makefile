# $FreeBSD$

PORTNAME=	JuicyPixels
PORTVERSION=	3.2.9.5
CATEGORIES=	graphics haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Picture loading/serialization

LICENSE=	BSD3CLAUSE

USE_CABAL=	mtl>=1.1 primitive>=0.4 vector>=0.9 zlib>=0.5.3.1

FLAGS_DEFINE=		MMAP

MMAP_DESC=		Enable file loading via mmap()
MMAP_FLAG_ENABLE=	Mmap
MMAP_FLAG_CABAL=	mmap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
