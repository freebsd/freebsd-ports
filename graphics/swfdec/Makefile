# Created by: ijliao
# $FreeBSD$
#   $MCom: ports/graphics/swfdec/Makefile,v 1.28 2009/01/01 13:38:17 kwm Exp $

PORTNAME=	swfdec
PORTVERSION=	0.8.4
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec/0.8/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	liboil-0.3.so:devel/liboil \
		libsoup-2.4.so:devel/libsoup

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
USE_GSTREAMER=	core good mp3 ffmpeg
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-Bsymbolic -L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION:R}

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_DESC=Enable the PulseAudio sound module

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=		libpulse.so:audio/pulseaudio
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

.include <bsd.port.mk>
