PORTNAME=	libshout
PORTVERSION=	2.4.6
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	https://downloads.xiph.org/releases/libshout/ \
		https://ftp.osuosl.org/pub/xiph/releases/libshout/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Connect and transmit data to an Icecast media streaming server
WWW=		https://icecast.org/ \
		https://gitlab.xiph.org/xiph/icecast-libshout

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		cpe gmake libtool pkgconfig ssl

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lcrypto
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS SPEEX THEORA VORBIS
OPTIONS_DEFAULT=SPEEX THEORA VORBIS

SPEEX_CONFIGURE_ENABLE=	speex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
THEORA_CONFIGURE_ENABLE=theora
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
vorbis_CONFIGURE_ENABLE=vorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

.include <bsd.port.mk>
