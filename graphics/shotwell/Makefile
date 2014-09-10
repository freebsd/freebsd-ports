# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et al.
# $FreeBSD$

PORTNAME=	shotwell
PORTVERSION=	0.18.1
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME/sources/shotwell/${PORTVERSION:R}

MAINTAINER=	cmt@burggraben.net
COMMENT=	Open source photo manager for GNOME

LICENSE=	LGPL21

BUILD_DEPENDS=	vala>=0.18.0:${PORTSDIR}/lang/vala \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgexiv2.so:${PORTSDIR}/graphics/gexiv2 \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libgphoto2.so:${PORTSDIR}/graphics/libgphoto2 \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libraw.so:${PORTSDIR}/graphics/libraw \
		librest-0.7.so:${PORTSDIR}/devel/librest

USES=		shebangfix gettext desktop-file-utils gmake pkgconfig tar:xz
USE_GNOME=	dconf gnomehier gtk30 gnomedocutils
USE_SQLITE=	3
USE_GSTREAMER1=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-icon-update
CONFIGURE_ENV+=	--define=NO_CAMERA
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	OPENMP
OPTIONS_DEFAULT=
OPENMP_DESC=	libraw uses OpenMP (implies GCC 4.6+)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMP}
USE_GCC=	yes
LDFLAGS+=	-lc++
.endif

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
