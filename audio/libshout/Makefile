# Created by: Zach Zurflu <zach@pabst.bendnet.com>
# $FreeBSD$

PORTNAME=	libshout
PORTVERSION=	2.4.1
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Connect and transmit data to an Icecast media streaming server

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

CONFLICTS=	libshout2-[0-9]*

OPTIONS_DEFINE=	DOCS SPEEX THEORA
OPTIONS_DEFAULT=SPEEX THEORA

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig ssl

PORTDOCS=	*

SPEEX_CONFIGURE_ENABLE=	speex
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
THEORA_CONFIGURE_ENABLE=theora
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora

post-patch:
	@${REINPLACE_CMD} -e '/^DATA = / s| $$(ckport_DATA)||; /^install-data-am:/ s| install-ckportDATA||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ffast-math||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^Requires: |Requires.private: |' ${WRKSRC}/shout.pc.in
	@${REINPLACE_CMD} -e '/^AM_CPPFLAGS = / s|^\(.*\) \(@XIPH_CPPFLAGS@\) \(.*\)$$|\1 \3 \2|' ${WRKSRC}/examples/Makefile.in
	@${REINPLACE_CMD} -e 's|#ifdef IPV6_V6ONLY|#if defined(__BSD_VISIBLE) \&\& defined(IPV6_V6ONLY)|' ${WRKSRC}/src/common/net/sock.c

.include <bsd.port.mk>
