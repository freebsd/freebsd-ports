# New ports collection makefile for: hs-hashed-storage
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hashed-storage
PORTVERSION=	0.5
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Hashed file storage support code

CABAL_SETUP=	Setup.hs

USE_HACKAGE=	binary dataenc mmap>=0.5 zlib

OPTIONS=	TEST "Build tests" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="test"
USE_HACKAGE+=		test-framework test-framework-hunit test-framework-quickcheck2 QuickCheck>=2.0.0.0 zip-archive
EXECUTABLE+=		hashed-storage-test
PLIST_SUB+=		MAYBE_TEST=""
.else
CONFIGURE_ARGS+=	--flags="-test"
PLIST_SUB+=		MAYBE_TEST="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
