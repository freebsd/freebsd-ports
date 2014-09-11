# $FreeBSD$

PORTNAME=	shake
PORTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Build system library, like Make, but more accurate dependencies

LICENSE=	BSD3CLAUSE

USE_CABAL=	hashable>=1.1.2.3 random unordered-containers>=0.2.1 \
		utf8-string>=0.3

EXECUTABLE=	shake

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
