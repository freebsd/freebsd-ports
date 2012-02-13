# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	2.5.2
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A distributed, interactive, smart revision control system

LICENSE=	GPLv2
FILE_LICENSE=	COPYING

USE_CABAL=	hashed-storage>=0.5.2 haskeline>=0.6.2.2 html>=1.0 HUnit>=1 \
		mtl>=1 parsec>=2 QuickCheck>=2.1 regex-compat>=0.71 tar>=0.3 \
		test-framework>=0.2.2 test-framework-hunit>=0.2.2 \
		test-framework-quickcheck2>=0.2.2 text>=0.11 zlib>=0.5.1

EXECUTABLE=	darcs

MAN1=		darcs.1

OPTIONS=	CURL            "Use libcurl for HTTP support" on \
		HTTP            "Use the pure HTTP package" off \
		STATIC          "Build static binary" off \
		TERMINFO        "Use the terminfo package" off \
		THREADED        "Use threading and SMP support" on \
		TYPE_WITNESSES  "Use GADT type witnesses" off \
		COLOR           "Use ANSI color escapes" off \
		MMAP            "Compile with mmap support" off \
		TEST            "Compile unit tests" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--flags="library"

.if defined(WITH_CURL)
CONFIGURE_ARGS+=	--flags="curl"
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--flags="-curl"
.endif

.if defined(WITH_HTTP)
CONFIGURE_ARGS+=	--flags="http"
USE_CABAL+=		HTTP>=3000.0 network>=2.2
.else
CONFIGURE_ARGS+=	--flags="-http"
.endif

.if !defined(WITH_CURL) && !defined(WITH_HTTP)
IGNORE=	cannot be compiled without HTTP support.  Please (re)run 'make config' and choose either CURL or HTTP
.endif

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=	--flags="static"
.else
CONFIGURE_ARGS+=	--flags="-static"
.endif

.if defined(WITH_TERMINFO)
CONFIGURE_ARGS+=	--flags="terminfo"
USE_CABAL+=		terminfo>=0.3
.else
CONFIGURE_ARGS+=	--flags="-terminfo"
.endif

.if defined(WITH_THREADED)
CONFIGURE_ARGS+=	--flags="threaded"
.else
CONFIGURE_ARGS+=	--flags="-threaded"
.endif

.if defined(WITH_TYPE_WITNESSES)
CONFIGURE_ARGS+=	--flags="type-witnesses"
EXECUTABLE+=		witnesses
.else
CONFIGURE_ARGS+=	--flags="-type-witnesses"
.endif

.if defined(WITH_COLOR)
CONFIGURE_ARGS+=	--flags="color"
.else
CONFIGURE_ARGS+=	--flags="-color"
.endif

.if defined(WITH_MMAP)
CONFIGURE_ARGS+=	--flags="mmap"
USE_CABAL+=		mmap>=0.5
.else
CONFIGURE_ARGS+=	--flags="-mmap"
.endif

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="test"
EXECUTABLE+=		unit
.else
CONFIGURE_ARGS+=	--flags="-test"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
