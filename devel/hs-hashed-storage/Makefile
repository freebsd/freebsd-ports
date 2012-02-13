# New ports collection makefile for: hs-hashed-storage
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hashed-storage
PORTVERSION=	0.5.9
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Hashed file storage support code

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	binary dataenc mmap>=0.5 mtl zlib

OPTIONS=	TEST "Build tests" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="test"
USE_CABAL+=		test-framework test-framework-hunit \
			test-framework-quickcheck2 HUnit \
			QuickCheck>=2.3 zip-archive
EXECUTABLE+=		hashed-storage-test
.else
CONFIGURE_ARGS+=	--flags="-test"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
