# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	hoogle
PORTVERSION=	4.2.41
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell API Search

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.6.1 blaze-builder>=0.2 case-insensitive>=0.2 \
		cmdargs>=0.7 conduit>=0.2 haskell-src-exts>=1.16 \
		http-types>=0.7 parsec>=2.1 QuickCheck random resourcet \
		safe shake>=0.14 tagsoup>=0.11 text>=0.11 uniplate>=1.6 \
		vector>=0.9 vector-algorithms>=0.6 wai>=1.1 warp>=2.1

EXECUTABLE=	hoogle

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
