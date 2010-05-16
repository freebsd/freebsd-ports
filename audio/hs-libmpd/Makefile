# New ports collection makefile for: hs-libmpd
# Date created:        May 16, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpd
PORTVERSION=	0.4.1
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An MPD client library

USE_HACKAGE=	utf8-string>=0.3.1 QuickCheck>=2.1.0.0

OPTIONS=	TEST     "Build test driver" off \
		COVERAGE "Build with hpc instrumentation" off

.include <bsd.port.options.mk>

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="test"
EXECUTABLE=		test
PLIST_SUB+=		MAYBE_TEST=""
.else
CONFIGURE_ARGS+=	--flags="-test"
PLIST_SUB+=		MAYBE_TEST="@comment "
.endif

.if defined(WITH_COVERAGE)
CONFIGURE_ARGS+=	--flags="coverage"
.else
CONFIGURE_ARGS+=	--flags="-coverage"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
