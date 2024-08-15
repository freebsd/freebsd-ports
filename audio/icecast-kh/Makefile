PORTNAME=	icecast
DISTVERSIONPREFIX=	icecast-
DISTVERSION=	2.4.0-kh15
PORTREVISION=	3
CATEGORIES=	audio net
PKGNAMESUFFIX=	-kh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Streaming mp3/ogg-vorbis audio server, KH branch
WWW=		https://github.com/karlheyes/icecast-kh

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Fails to build with libxml2 2.13.2 (PR 280159)
EXPIRATION_DATE=2024-08-21

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		gmake gnome localbase pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	karlheyes
GH_PROJECT=	icecast-kh
USE_GNOME=	libxml2 libxslt
USE_RC_SUBR=	icecast

CONFLICTS_INSTALL=	icecast

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE}
# /usr/bin/ld: error: undefined symbol: ERR_get_error
LIBS+=		-L${OPENSSLLIB} -lcrypto

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		CURL DOCS SPEEX
OPTIONS_DEFAULT=	CURL SPEEX

CURL_DESC=		Support Directory server interaction (YP) via curl
SPEEX_DESC=		Support Speex codec within Ogg streams

CURL_CONFIGURE_WITH=	curl=${LOCALBASE}
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

SPEEX_CONFIGURE_WITH=	speex=${LOCALBASE}
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex

.include <bsd.port.mk>
