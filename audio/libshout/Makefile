# Created by: Zach Zurflu <zach@pabst.bendnet.com>
# $FreeBSD$

PORTNAME=	libshout
PORTVERSION=	2.4.3
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	https://downloads.xiph.org/releases/libshout/ \
		https://svn.xiph.org/releases/libshout/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Connect and transmit data to an Icecast media streaming server

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

OPTIONS_DEFINE=	DOCS SPEEX THEORA
OPTIONS_DEFAULT=SPEEX THEORA

USES=		gmake libtool pathfix pkgconfig ssl

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lcrypto
USE_LDCONFIG=	yes

SPEEX_CONFIGURE_ENABLE=	speex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
THEORA_CONFIGURE_ENABLE=theora
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora

.include <bsd.port.mk>
