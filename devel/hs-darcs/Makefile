# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	2.8.1
PORTREVISION=	1
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

OPTIONS_DEFINE=		STATIC TERMINFO THREADED COLOR MMAP
OPTIONS_MULTI=		HTTP
OPTIONS_MULTI_HTTP=	CURL HTTP
OPTIONS_DEFAULT=	CURL THREADED

CURL_DESC=		Use libcurl for HTTP support
HTTP_DESC=		Use the pure HTTP package
STATIC_DESC=		Build static binary
TERMINFO_DESC=		Use the terminfo package
THREADED_DESC=		Use threading and SMP support
COLOR_DESC=		Use ANSI color escapes
MMAP_DESC=		Compile with mmap support

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--flags="library executable"

.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=	--flags="curl"
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--flags="-curl"
.endif

.if ${PORT_OPTIONS:MHTTP}
CONFIGURE_ARGS+=	--flags="http"
USE_CABAL+=		HTTP>=4000.0.8 network>=2.2
.else
CONFIGURE_ARGS+=	--flags="-http"
.endif

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=	--flags="static"
.else
CONFIGURE_ARGS+=	--flags="-static"
.endif

.if ${PORT_OPTIONS:MTERMINFO}
CONFIGURE_ARGS+=	--flags="terminfo"
USE_CABAL+=		terminfo>=0.3
.else
CONFIGURE_ARGS+=	--flags="-terminfo"
.endif

.if ${PORT_OPTIONS:MTHREADED}
CONFIGURE_ARGS+=	--flags="threaded"
.else
CONFIGURE_ARGS+=	--flags="-threaded"
.endif

.if ${PORT_OPTIONS:MCOLOR}
CONFIGURE_ARGS+=	--flags="color"
.else
CONFIGURE_ARGS+=	--flags="-color"
.endif

.if ${PORT_OPTIONS:MMMAP}
CONFIGURE_ARGS+=	--flags="mmap"
USE_CABAL+=		mmap>=0.5
.else
CONFIGURE_ARGS+=	--flags="-mmap"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
