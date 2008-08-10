# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.6.8
CATEGORIES=	graphics
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec/0.6/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	oil-0.3.0:${PORTSDIR}/devel/liboil \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_GNOME=	gnomehack gtk20
USE_AUTOTOOLS=	libtool:15:env automake:19:env autoconf:261
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ffmpeg" \
		LDFLAGS="-Wl,-Bsymbolic -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-audio=oss
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS=	GSTREAMER "Support for decoding some codecs with GStreamer" off

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER)
USE_GSTREAMER=	yes
.else
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=	--disable-gstreamer --enable-ffmpeg --enable-mad
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SWFDEC_LIBVERSION="0:0:0"|SWFDEC_LIBVERSION="1:0:0"|' ${WRKSRC}/configure.ac

.include <bsd.port.post.mk>
