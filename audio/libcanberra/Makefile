# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/audio/libcanberra/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	libcanberra
PORTVERSION=	0.30
PORTREVISION=	4
CATEGORIES=	audio devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/ \
		http://pkgs.fedoraproject.org/repo/pkgs/libcanberra/libcanberra-0.30.tar.xz/34cb7e4430afaf6f447c4ebdb9b42072/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libltdl.so:devel/libltdl

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lynx --disable-tdb --disable-alsa
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.if defined(SLAVEPORT)
OPTIONS_DEFINE=	PULSEAUDIO GSTREAMER
.endif

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
USE_GNOME+=	gtk30
LIB_DEPENDS+=	libcanberra.so:audio/libcanberra
CONFIGURE_ARGS+=--enable-gtk3
.else
CONFIGURE_ARGS+=--disable-gtk3

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:audio/pulseaudio
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER1=	yes
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
