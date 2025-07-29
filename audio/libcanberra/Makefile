PORTNAME=	libcanberra
PORTVERSION=	0.30
PORTREVISION?=	12
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

USES=		gmake gnome libtool localbase pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
# common
CONFIGURE_ARGS=	--disable-alsa \
		--disable-lynx \
		--disable-tdb \
		--disable-udev
# base port
CONFIGURE_ARGS+=--disable-gtk \
		--disable-gtk3 \
		--disable-gstreamer \
		--disable-pulse
INSTALL_TARGET=	install-strip

CANBERRA?=	base
CANBERRA_ALL=	base gtk2 gtk3 gstreamer pulse

.if ${CANBERRA} == gtk3
USE_GNOME+=	gtk30
.elif ${CANBERRA} == gtk2
USE_GNOME+=	gnomeprefix gtk20
module_SWITCH=	gtk
.elif ${CANBERRA} == pulse
LIB_DEPENDS+=	libpulse.so:audio/pulseaudio
.elif ${CANBERRA} == gstreamer
USES+=		gstreamer
.endif

.if ${CANBERRA} != "base"
PKGNAMESUFFIX=	-${CANBERRA}
LIB_DEPENDS+=	libcanberra.so:audio/libcanberra
module_SWITCH?=	${CANBERRA}
CONFIGURE_ARGS:=--enable-${module_SWITCH} \
		${CONFIGURE_ARGS:N--disable-${module_SWITCH}}
.endif

PLIST_SUB=	VERSION=${PORTVERSION} \
		${CANBERRA:tu}=""
.for module in ${CANBERRA_ALL:N${CANBERRA}}
PLIST_SUB+=	${module:tu}="@comment "
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| gtkdoc | |g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
