# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.3.13
PORTREVISION=	5
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creating, comparing, parsing and printing Universally Unique Identifiers

LICENSE=	BSD3CLAUSE

USE_CABAL=	cryptohash-md5 cryptohash-sha1 entropy network-info random \
		uuid-types

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
