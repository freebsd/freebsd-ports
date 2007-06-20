# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.4.5
CATEGORIES=	graphics
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec/0.4/

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		oil-0.3.1:${PORTSDIR}/devel/liboil

USE_XLIB=	yes
USE_SDL=	sdl
USE_GNOME=	gnomehack gtk20 gnomevfs2
USE_GSTREAMER=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-Wl,-Bsymbolic -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-mozilla-plugin \
		--with-audio=none
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e "s,int16_t,__int16_t," ${WRKSRC}/libswfdec/swfdec_shape.c
	@${REINPLACE_CMD} -e 's|plugin||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG:T}|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
