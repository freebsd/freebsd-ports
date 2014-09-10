# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darcs
PORTVERSION=	2.8.4
PORTREVISION=	8
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Distributed, interactive, smart revision control system

LICENSE=	GPLv2

USE_CABAL=	hashed-storage>=0.5.6 html mtl>=1.0 parsec>=2.2 random \
		regex-compat>=0.95.1 regex-posix>=0.95.1 tar>=0.4 \
		text>=0.11.0.6 unix-compat>=0.1.2 utf8-string>=0.3.6 \
		vector>=0.7 zlib>=0.5.1.0

EXECUTABLE=	darcs

MAN1PAGES=	darcs.1

FLAGS_DEFINE=		STATIC TERMINFO THREADED COLOR MMAP
FLAGS_MULTI=		WEB
FLAGS_MULTI_WEB=	CURL HTTP
WEB_DESC=		HTTP backend

FLAGS_DEFAULT=		CURL THREADED
FLAGS_ENABLE=		library executable

CURL_DESC=		Use libcurl for HTTP support
CURL_FLAG_ENABLE=	curl
CURL_FLAG_LIB=		libcurl.so:${PORTSDIR}/ftp/curl

HTTP_DESC=		Use the pure HTTP package
HTTP_FLAG_ENABLE=	http
HTTP_FLAG_CABAL=	HTTP>=4000.0.8 network>=2.2

STATIC_DESC=		Build static binary
STATIC_FLAG_ENABLE=	static

TERMINFO_DESC=		Use terminfo
TERMINFO_FLAG_ENABLE=	terminfo

THREADED_DESC=		Use threading and SMP support
THREADED_FLAG_ENABLE=	threaded

COLOR_DESC=		Use ANSI color escapes
COLOR_FLAG_ENABLE=	color

MMAP_DESC=		Compile with mmap support
MMAP_FLAG_ENABLE=	mmap
MMAP_FLAG_CABAL=	mmap>=0.5

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
