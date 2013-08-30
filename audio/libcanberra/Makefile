# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/libcanberra/Makefile,v 1.28 2011/06/11 18:55:56 mezz Exp $

PORTNAME=	libcanberra
PORTVERSION=	0.28
PORTREVISION=	3
CATEGORIES=	audio devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

LIB_DEPENDS=	vorbisfile:${PORTSDIR}/audio/libvorbis

USES=		gmake
USE_GNOME=	gnomeprefix gnomehack gtk20 ltverhack gconf2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool libltdl
CONFIGURE_ARGS=	--disable-lynx --disable-tdb --disable-alsa
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(SLAVEPORT)
GCONF_SCHEMAS=	libcanberra.schemas
.else
OPTIONS_DEFINE=	PULSEAUDIO GSTREAMER
.endif

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
USE_GNOME+=	gtk30
LIB_DEPENDS+=	canberra:${PORTSDIR}/audio/libcanberra
CONFIGURE_ARGS+=--enable-gtk3
.else
CONFIGURE_ARGS+=--disable-gtk3

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.endif # end slaveport

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
