PORTNAME=	libcanberra
PORTVERSION=	0.30
PORTREVISION=	11
CATEGORIES=	audio devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/ \
		http://pkgs.fedoraproject.org/repo/pkgs/libcanberra/libcanberra-0.30.tar.xz/34cb7e4430afaf6f447c4ebdb9b42072/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec
WWW=		https://0pointer.de/lennart/projects/libcanberra/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libltdl.so:devel/libltdl

USES=		gmake gnome localbase libtool pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lynx --disable-tdb --disable-alsa --disable-udev
INSTALL_TARGET=	install-strip

SLAVEPORT?=

PLIST_SUB=	VERSION=${PORTVERSION}

.if ${SLAVEPORT} != ""
PKGNAMESUFFIX=	-${SLAVEPORT}
.endif
.if ${SLAVEPORT:U} == gtk3
USE_GNOME+=	gtk30
LIB_DEPENDS+=	libcanberra.so:audio/libcanberra
CONFIGURE_ARGS+=	--enable-gtk3 \
			--disable-gtk \
			--disable-gstreamer \
			--disable-pulse
PLIST_SUB+=	BASE="@comment " GTK3="" GTK2="@comment "
.elif ${SLAVEPORT:U} == gtk2
USE_GNOME+=	gnomeprefix gtk20
LIB_DEPENDS+=	libcanberra.so:audio/libcanberra
CONFIGURE_ARGS+=	--enable-gtk \
			--disable-gtk3 \
			--disable-gstreamer \
			--disable-pulse
PLIST_SUB+=	BASE="@comment " GTK3="@comment " GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gtk \
			--disable-gtk3
PLIST_SUB+=	BASE="" GTK3="@comment " GTK2="@comment "
OPTIONS_DEFINE=	PULSEAUDIO GSTREAMER
OPTIONS_SUB=	yes
.endif

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

GSTREAMER_USES=	gstreamer
GSTREAMER_CONFIGURE_ENABLE=	gstreamer

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| gtkdoc | |g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
