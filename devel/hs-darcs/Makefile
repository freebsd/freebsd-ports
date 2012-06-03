# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	2.8.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A distributed, interactive, smart revision control system

LICENSE=	GPLv2
FILE_LICENSE=	COPYING

USE_CABAL=	hashed-storage>=0.5.6 haskeline>=0.6.3 html>=1.0 \
		mtl>=1.0 parsec>=2.0 random>=1.0 regex-compat>=0.95.1 \
		regex-posix>=0.95.1 tar>=0.4 text>=0.11.0.6 unix-compat>=0.1.2 \
		vector>=0.7 zlib>=0.5.1.0

EXECUTABLE=	darcs

MAN1=		darcs.1

OPTIONS=	CURL            "Use libcurl for HTTP support" on \
		HTTP            "Use the pure HTTP package" off \
		STATIC          "Build static binary" off \
		TERMINFO        "Use the terminfo package" off \
		THREADED        "Use threading and SMP support" on \
		COLOR           "Use ANSI color escapes" off \
		MMAP            "Compile with mmap support" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--flags="library executable"

.if defined(WITH_CURL)
CONFIGURE_ARGS+=	--flags="curl"
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--flags="-curl"
.endif

.if defined(WITH_HTTP)
CONFIGURE_ARGS+=	--flags="http"
USE_CABAL+=		HTTP>=4000.0.8 network>=2.2
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

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
