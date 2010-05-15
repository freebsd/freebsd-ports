# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	2.4.3
CATEGORIES=	devel haskell
PKGNAMEPREFIX=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A distributed, interactive, smart revision control system

USE_HACKAGE=	hashed-storage haskeline>=0.6.1 utf8-string>=0.3 zlib>=0.5.1.0

EXECUTABLE=	darcs

MAN1=		darcs.1
MAN1SRC=	dist/build/darcs

OPTIONS=	CURL            "Use libcurl for HTTP support" on \
		CURL_PIPELINING "Use libcurl's HTTP pipelining" off \
		HTTP            "Use the pure HTTP package" off \
		STATIC          "Build static binary" off \
		TERMINFO        "Use the terminfo package" off \
		THREADED        "Use threading and SMP support" on \
		TYPE_WITNESSES  "Use GADT type witnesses" off \
		COLOR           "Use ANSI color escapes" off \
		MMAP            "Compile with mmap support" off \
		TEST            "Compile unit tests" off

.include <bsd.port.options.mk>

.if defined(WITH_CURL)
CONFIGURE_ARGS+=	--flags="curl"
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--flags="-curl"
.endif

.if defined(WITH_CURL_PIPELINING)
CONFIGURE_ARGS+=	--flags="curl-pipelining"
.if !defined(WITH_CURL)
IGNORE=	cannot be compiled without CURL in this configuration.  Please (re)run 'make config' and choose CURL too
.endif
.else
CONFIGURE_ARGS+=	--flags="-curl-pipelining"
.endif

.if defined(WITH_HTTP)
CONFIGURE_ARGS+=	--flags="http"
USE_HACKAGE+=		HTTP>=3000.0
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
USE_HACKAGE+=		terminfo>=0.3
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
PLIST_SUB+=		MAYBE_TYPE_WITNESSES=""
.else
CONFIGURE_ARGS+=	--flags="-type-witnesses"
PLIST_SUB+=		MAYBE_TYPE_WITNESSES="@comment "
.endif

.if defined(WITH_COLOR)
CONFIGURE_ARGS+=	--flags="color"
.else
CONFIGURE_ARGS+=	--flags="-color"
.endif

.if defined(WITH_MMAP)
CONFIGURE_ARGS+=	--flags="mmap"
USE_HACKAGE+=		mmap>=0.2
.else
CONFIGURE_ARGS+=	--flags="-mmap"
.endif

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="test"
EXECUTABLE+=		unit
PLIST_SUB+=		MAYBE_TEST=""
.else
CONFIGURE_ARGS+=	--flags="-test"
PLIST_SUB+=		MAYBE_TEST="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
