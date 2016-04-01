# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	icecast
DISTVERSIONPREFIX=	icecast-
DISTVERSION=	${ICVERSION}-kh${KH}
PORTREVISION=	2
CATEGORIES=	audio net ipv6
PKGNAMESUFFIX=	-kh

MAINTAINER=	anes@anes.su
COMMENT=	Streaming mp3/ogg-vorbis audio server, KH branch

LICENSE=	GPLv2

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt

USE_GITHUB=	yes
GH_ACCOUNT=	karlheyes
GH_PROJECT=	icecast-kh

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ICVERSION=	2.3.3
KH=		10

OPTIONS_DEFINE=		CURL DOCS KATE SPEEX SSL_PORT
OPTIONS_DEFAULT=	CURL KATE SPEEX
CURL_DESC=		Support Directory server interaction (YP) via curl
KATE_DESC=		Support Kate/Skeleton codec within Ogg streams
SPEEX_DESC=		Support Speex codec within Ogg streams
SSL_PORT_DESC=		Use OpenSSL from ports instead of one in the base

CONFLICTS_INSTALL=	icecast-[0-9]* icecast2-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
BUILD_DEPENDS+=	curl>=7.10:ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if ${PORT_OPTIONS:MKATE}
LIB_DEPENDS+=	libkate.so:multimedia/libkate
.else
CONFIGURE_ARGS+=	--without-kate
.endif

.if ${PORT_OPTIONS:MSPEEX}
BUILD_DEPENDS+=	speex>=1:audio/speex
CONFIGURE_ARGS+=	--with-speex=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-speex
.endif

.if ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=	yes
.else
WITH_OPENSSL_BASE=	yes
.endif

.include <bsd.port.mk>
