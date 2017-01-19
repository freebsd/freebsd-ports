# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et al.
# $FreeBSD$

PORTNAME=	shotwell
PORTVERSION=	0.24.3
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME/sources/shotwell/${PORTVERSION:R}

MAINTAINER=	cmt@burggraben.net
COMMENT=	Open source photo manager for GNOME

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.20.1:lang/vala \
		bash:shells/bash \
		itstool:textproc/itstool
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libexiv2.so:graphics/exiv2 \
		libgee-0.8.so:devel/libgee \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		liblcms2.so:graphics/lcms2 \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libgexiv2.so:graphics/gexiv2 \
		libexif.so:graphics/libexif \
		libgphoto2.so:graphics/libgphoto2 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libunique-1.0.so:x11-toolkits/unique \
		libraw.so:graphics/libraw \
		librest-0.7.so:devel/librest

USES=		gettext desktop-file-utils gmake libtool pkgconfig \
		sqlite tar:xz
USE_GNOME=	cairo dconf gtk30 gnomedocutils
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	--define=NO_CAMERA
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
PORTSCOUT=	limitw:1,even
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	OPENMP
OPTIONS_DEFAULT=
OPENMP_DESC=	libraw uses OpenMP (implies GCC 4.6+)

OPENMP_USES=		compiler:gcc-c++11-lib
OPENMP_USES_OFF=	compiler:c++11-lib

GLIB_SCHEMAS=	org.yorba.shotwell.gschema.xml org.yorba.shotwell-extras.gschema.xml

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|share/shotwell|${DATADIR_REL}|g' \
			${WRKSRC}/${MAKEFILE}

# attempt at a DATADIR safe port
	@${REINPLACE_CMD} -E \
		-e 's|\.get_child\("share")\.get_child\("shotwell")|${SHOTWELL_DATADIR}|' \
		${WRKSRC}/src/AppDirs.vala

.include <bsd.port.pre.mk>

# attempt at a DATADIR safe port
.for dir in ${DATADIR:S,^${PREFIX}/,,:S,/, ,g}
SHOTWELL_DATADIR+=.get_child("${dir}")
.endfor

.include <bsd.port.post.mk>
