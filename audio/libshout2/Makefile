# Created by: Zach Zurflu <zach@pabst.bendnet.com>
# $FreeBSD$

PORTNAME=	libshout2
PORTVERSION=	2.3.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/ \
		LOCAL/sunpoet
DISTNAME=	libshout-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Connect and transmit data to an Icecast media streaming server

LIB_DEPENDS=	speex:${PORTSDIR}/audio/speex \
		theora:${PORTSDIR}/multimedia/libtheora \
		vorbis:${PORTSDIR}/audio/libvorbis

CONFLICTS=	libshout-[0-9]*

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
USES=		gmake

DOCSDIR=	${PREFIX}/share/doc/libshout

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^Requires: |Requires.private: |' ${WRKSRC}/shout.pc.in
	@${REINPLACE_CMD} -e '/^AM_CPPFLAGS = / s|^\(.*\) \(@XIPH_CPPFLAGS@\) \(.*\)$$|\1 \3 \2|' ${WRKSRC}/examples/Makefile.in
	@${REINPLACE_CMD} -e 's|#ifdef IPV6_V6ONLY|#if defined(__BSD_VISIBLE) \&\& defined(IPV6_V6ONLY)|' ${WRKSRC}/src/net/sock.c

.include <bsd.port.mk>
