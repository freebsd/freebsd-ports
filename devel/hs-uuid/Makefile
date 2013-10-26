# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.2.13
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creating, comparing, parsing and printing Universally Unique Identifiers

LICENSE=	BSD

USE_CABAL=	cryptohash>=0.7 maccatcher>=1.0 random>=1.0.1

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
