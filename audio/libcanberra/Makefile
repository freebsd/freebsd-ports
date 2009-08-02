# New ports collection makefile for:	libcanberra
# Date created:				05 August 2008
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcanberra
PORTVERSION=	0.10
PORTREVISION=	5
CATEGORIES=	audio devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

LIB_DEPENDS=	vorbisfile.6:${PORTSDIR}/audio/libvorbis

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20 ltverhack gconf2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22 libltdl:22
CONFIGURE_ARGS=	--disable-lynx
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	libcanberra.schemas

OPTIONS=	PULSE "Enable Pulse Audio support" off \
		GSTREAMER "Enable GStreamer audio support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PULSE)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.endif

.if !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.post.mk>
