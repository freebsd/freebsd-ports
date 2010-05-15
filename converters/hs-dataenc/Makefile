# New ports collection makefile for: hs-dataenc
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dataenc
PORTVERSION=	0.13.0.2
CATEGORIES=	converters haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Data encoding library

CABAL_SETUP=	Setup.hs

OPTIONS=	BUILDTESTS "Build unit and quickcheck tests" off

.include <bsd.port.options.mk>

.if defined(WITH_BUILDTESTS)
CONFIGURE_ARGS+=	--flags="BuildTests"
EXECUTABLE+=		tests
PLIST_SUB+=		MAYBE_BUILDTESTS=""
.else
CONFIGURE_ARGS+=	--flags="-BuildTests"
PLIST_SUB+=		MAYBE_BUILDTESTS="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
