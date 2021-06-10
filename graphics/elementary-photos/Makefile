PORTNAME=	elementary-photos
DISTVERSION=	2.7.0
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Photo viewer and organizer designed for elementary OS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libexif.so:graphics/libexif \
		libgee-0.8.so:devel/libgee \
		libgeocode-glib.so:net/geocode-glib \
		libgexiv2.so:graphics/gexiv2 \
		libglib-2.0.so:devel/glib20 \
		libgphoto2.so:graphics/libgphoto2 \
		libgphoto2_port.so:graphics/libgphoto2 \
		libgranite.so:x11-toolkits/granite \
		libgstbase-1.0.so:multimedia/gstreamer1 \
		libgudev-1.0.so:devel/libgudev \
		libjson-glib-1.0.so:devel/json-glib \
		libraw.so:graphics/libraw \
		librest-0.7.so:devel/librest \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libwebp.so:graphics/webp \
		libxml2.so:textproc/libxml2

USES=			compiler:c11 desktop-file-utils gettext gnome meson \
			ninja pkgconfig sqlite xorg
USE_GITHUB=		yes
GH_ACCOUNT=		elementary
GH_PROJECT=		photos
USE_GNOME=		cairo gdkpixbuf2 gtk30 intltool
GLIB_SCHEMAS=		io.elementary.photos-extras.gschema.xml \
			io.elementary.photos.gschema.xml
INSTALLS_ICONS=		yes
USE_GSTREAMER1=		yes
USE_LDCONFIG=		yes
USE_XORG=		x11
MESON_BUILD_DIR=	build

_ICONSDIR=	${STAGEDIR}${PREFIX}/share/icons/elementary-photos

post-configure:
	@${MKDIR} ${_ICONSDIR}
	${INSTALL_DATA} ${WRKSRC}/data/icons/*.svg ${_ICONSDIR}/

.include <bsd.port.mk>
