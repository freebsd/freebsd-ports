# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	hoogle
PORTVERSION=	5.0.17.4
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell API Search

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson cmdargs conduit conduit-extra connection extra \
		haskell-src-exts http-conduit http-types js-flot js-jquery \
		mmap network network-uri old-locale process-extras QuickCheck \
		resourcet storable-tuple tar uniplate utf8-string vector wai \
		wai-logger warp warp-tls zlib

EXECUTABLE=	hoogle

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
