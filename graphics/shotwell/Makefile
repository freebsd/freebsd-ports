# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et al.
# $FreeBSD$

PORTNAME=	shotwell
PORTVERSION=	0.23.0
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME/sources/shotwell/${PORTVERSION:R}

MAINTAINER=	cmt@burggraben.net
COMMENT=	Open source photo manager for GNOME

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.20.1:lang/vala \
		bash:shells/bash
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libgee-0.8.so:devel/libgee \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libgexiv2.so:graphics/gexiv2 \
		libexif.so:graphics/libexif \
		libgphoto2.so:graphics/libgphoto2 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libunique-1.0.so:x11-toolkits/unique \
		libraw.so:graphics/libraw \
		librest-0.7.so:devel/librest

USES=		shebangfix gettext desktop-file-utils gmake pkgconfig sqlite tar:xz
USE_GNOME=	dconf gtk30 gnomedocutils
USE_GSTREAMER1=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-icon-update
CONFIGURE_ENV+=	--define=NO_CAMERA
INSTALLS_ICONS=	yes
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	OPENMP
OPTIONS_DEFAULT=
OPENMP_DESC=	libraw uses OpenMP (implies GCC 4.6+)

OPENMP_USES=		compiler:gcc-c++11-lib
OPENMP_USES_OFF=	compiler:c++11-lib

SHEBANG_FILES=	${WRKSRC}/${CONFIGURE_SCRIPT} ${WRKSRC}/chkver

GLIB_SCHEMAS=	org.yorba.shotwell.gschema.xml org.yorba.shotwell-extras.gschema.xml

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|share/shotwell|${DATADIR_REL}|g' \
			${WRKSRC}/${MAKEFILE}

	@${REINPLACE_CMD} -E \
		-e 's|\-n ||g' \
			${WRKSRC}/configure.mk

	@${REINPLACE_CMD} -E \
		-e 's|--fatal-warnings||g' \
			${WRKSRC}/plugins/Makefile.plugin.mk
# attempt at a DATADIR safe port
	@${REINPLACE_CMD} -E \
		-e 's|\.get_child\("share")\.get_child\("shotwell")|${SHOTWELL_DATADIR}|' \
		${WRKSRC}/src/AppDirs.vala

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/shotwell \
		${STAGEDIR}${LOCALBASE}/lib/shotwell/plugins/builtin/shotwell-transitions.so \
		${STAGEDIR}${LOCALBASE}/lib/shotwell/plugins/builtin/shotwell-publishing.so \
		${STAGEDIR}${LOCALBASE}/lib/shotwell/plugins/builtin/shotwell-data-imports.so \
		${STAGEDIR}${LOCALBASE}/lib/shotwell/plugins/builtin/shotwell-publishing-extras.so \
		${STAGEDIR}${LOCALBASE}/libexec/shotwell/shotwell-video-thumbnailer

.include <bsd.port.pre.mk>

# attempt at a DATADIR safe port
.for dir in ${DATADIR:S,^${PREFIX}/,,:S,/, ,g}
SHOTWELL_DATADIR+=.get_child("${dir}")
.endfor

.include <bsd.port.post.mk>
