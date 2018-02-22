# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darcs
PORTVERSION=	2.12.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Distributed, interactive, smart revision control system

LICENSE=	GPLv2

USE_CABAL=	async attoparsec base16-bytestring cryptohash \
		data-ordlist dataenc fgl graphviz hashable html HTTP \
		mmap mtl parsec random \
		regex-applicative regex-compat-tdfa sandi tar \
		text transformers-compat unix-compat \
		utf8-string vector zip-archive zlib

EXECUTABLE=	darcs

MAN1PAGES=	darcs.1

FLAGS_DEFINE=		STATIC TERMINFO THREADED
FLAGS_MULTI=		WEB
FLAGS_MULTI_WEB=	CURL HTTP
WEB_DESC=		HTTP backend

FLAGS_DEFAULT=		CURL THREADED
FLAGS_ENABLE=		library executable

CURL_DESC=		Use libcurl for HTTP support
CURL_FLAG_ENABLE=	curl
CURL_FLAG_LIB=		libcurl.so:ftp/curl

HTTP_DESC=		Use the pure HTTP package
HTTP_FLAG_ENABLE=	http
HTTP_FLAG_CABAL=	HTTP>=4000.2.3 network>=2.6 network-uri>=2.6

STATIC_DESC=		Build static binary
STATIC_FLAG_ENABLE=	static

TERMINFO_DESC=		Use terminfo
TERMINFO_FLAG_ENABLE=	terminfo

THREADED_DESC=		Use threading and SMP support
THREADED_FLAG_ENABLE=	threaded

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.if ${PORT_OPTIONS:MSTATIC} && ${PORT_OPTIONS:MCURL}
BROKEN=			enabling STATIC and CURL together will produce linker errors
.endif

.include <bsd.port.mk>
