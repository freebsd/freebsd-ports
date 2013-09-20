# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et al.
# $FreeBSD$

PORTNAME=	shotwell
PORTVERSION=	0.14.1
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.yorba.org/download/shotwell/${PORTVERSION:R}/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Open source photo manager for GNOME

LICENSE=	LGPL21

BUILD_DEPENDS=	vala>=0.18.0:${PORTSDIR}/lang/vala \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gee:${PORTSDIR}/devel/libgee06 \
		json-glib-1.0:${PORTSDIR}/devel/json-glib \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gexiv2:${PORTSDIR}/graphics/gexiv2 \
		exif:${PORTSDIR}/graphics/libexif \
		gphoto2:${PORTSDIR}/graphics/libgphoto2 \
		webkitgtk-3.0:${PORTSDIR}/www/webkit-gtk3 \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		raw:${PORTSDIR}/graphics/libraw \
		rest:${PORTSDIR}/devel/librest

USE_XZ=		yes
USES=		shebangfix gettext desktop-file-utils gmake pkgconfig
USE_GNOME=	gnomehier gconf2 gtk20 librsvg2
USE_SQLITE=	3
USE_GSTREAMER1=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-icon-update
CONFIGURE_ENV+=	--define=NO_CAMERA
INSTALLS_ICONS=	yes

SHEBANG_FILES=	${WRKSRC}/${CONFIGURE_SCRIPT} ${WRKSRC}/chkver

GLIB_SCHEMAS=	org.yorba.shotwell.gschema.xml org.yorba.shotwell-extras.gschema.xml

NO_STAGE=	yes
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
	@-update-desktop-database

.include <bsd.port.pre.mk>

# attempt at a DATADIR safe port
.for dir in ${DATADIR:S,^${PREFIX}/,,:S,/, ,g}
SHOTWELL_DATADIR+=.get_child("${dir}")
.endfor

.include <bsd.port.post.mk>
