# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	icecast
DISTVERSIONPREFIX=	icecast-
DISTVERSION=	2.4.0-kh10
CATEGORIES=	audio net ipv6
PKGNAMESUFFIX=	-kh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Streaming mp3/ogg-vorbis audio server, KH branch

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		gmake gnome localbase pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	karlheyes
GH_PROJECT=	icecast-kh
USE_GNOME=	libxml2 libxslt
USE_RC_SUBR=	icecast

CONFLICTS_INSTALL=	icecast icecast2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE}
# /usr/bin/ld: error: undefined symbol: ERR_get_error
LIBS+=		-L${OPENSSLLIB} -lcrypto

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		CURL DOCS KATE SPEEX
OPTIONS_DEFAULT=	CURL KATE SPEEX

CURL_DESC=		Support Directory server interaction (YP) via curl
KATE_DESC=		Support Kate/Skeleton codec within Ogg streams
SPEEX_DESC=		Support Speex codec within Ogg streams

CURL_CONFIGURE_WITH=	curl=${LOCALBASE}
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

KATE_CONFIGURE_WITH=	kate
KATE_LIB_DEPENDS=	libkate.so:multimedia/libkate

SPEEX_CONFIGURE_WITH=	speex=${LOCALBASE}
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex

.include <bsd.port.mk>
