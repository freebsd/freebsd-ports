# Created by: Oliver Braun <obraun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darcs
PORTVERSION=	2.10.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Distributed, interactive, smart revision control system

LICENSE=	GPLv2

USE_CABAL=	attoparsec>=0.11 base16-bytestring>=0.1 cryptohash>=0.4 \
		data-ordlist>=0.4 dataenc>=0.11 hashable>=1.0 html \
		mmap>=0.5 mtl>=2.1 parsec>=3.1 random>=1.0 \
		regex-applicative>=0.2 regex-compat-tdfa>=0.95.1 tar>=0.4 \
		text>=0.11.2.0 transformers-compat>=0.4 unix-compat>=0.1.2 \
		utf8-string>=0.3.6 vector>=0.7 zip-archive>=0.2.3 zlib>=0.5.3.0

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
