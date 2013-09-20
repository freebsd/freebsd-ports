# Created by: ijliao
# $FreeBSD$
#   $MCom: ports/graphics/swfdec/Makefile,v 1.28 2009/01/01 13:38:17 kwm Exp $

PORTNAME=	swfdec
PORTVERSION=	0.8.4
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec/0.8/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	oil-0.3.0:${PORTSDIR}/devel/liboil \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gtk20 ltverhack
USE_GSTREAMER=	core good mp3 ffmpeg
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-Bsymbolic -L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION:R}

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_DESC="Enable the PulseAudio sound module"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=		pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-audio=pulse
.else
CONFIGURE_ARGS+=	--with-audio=oss
.endif

post-extract:
	@${CP} ${FILESDIR}/swfdec_playback_oss.c \
	    	${WRKSRC}/swfdec-gtk

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.post.mk>
