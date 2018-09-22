# $FreeBSD$

PORTNAME=	zlib-enum
PORTVERSION=	0.2.3.1
PORTREVISION=	6
CATEGORIES=	archivers haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Enumerator interface for zlib compression

LICENSE=	MIT

USE_CABAL=	enumerator>=0.4 zlib-bindings>=0.1

DEPRECATED=	Doesn't build with recent GHC version
EXPIRATION_DATE=	2018-10-22

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
