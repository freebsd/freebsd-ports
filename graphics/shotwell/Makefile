# New ports collection makefile for:	shotwell
# Date created:		Tue Sep  7 02:00:03 UTC 2010
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et al.
#
# $FreeBSD$
#

PORTNAME=	shotwell
PORTVERSION=	0.6.1
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.yorba.org/download/shotwell/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open source photo manager for GNOME

BUILD_DEPENDS=	${LOCALBASE}/lib/libraw.a:${PORTSDIR}/graphics/libraw \
		vala>=0.8.0:${PORTSDIR}/lang/vala
LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gee.2:${PORTSDIR}/devel/libgee \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gexiv2.0:${PORTSDIR}/graphics/gexiv2 \
		exif.12:${PORTSDIR}/graphics/libexif \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		webkit:${PORTSDIR}/www/webkit-gtk2 \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

BROKEN=		Doesn't build with vala-0.10

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gconf2 gtk20 desktopfileutils
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-icon-update \
		--with-gconf-schema-file-dir=${PREFIX}/etc/gconf/schemas \
		--disable-schemas-install
INSTALLS_ICONS=	yes

GCONF_SCHEMAS=	shotwell.schemas
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|/bin/bash|${SH}|' \
		${WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/libraw-config \
		${WRKSRC}/minver

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|share/shotwell|${DATADIR_REL}|' \
		${WRKSRC}/${MAKEFILE}
# attempt at a DATADIR safe port
	@${REINPLACE_CMD} -E \
		-e 's|\.get_child\("share")\.get_child\("shotwell")|${SHOTWELL_DATADIR}|' \
		${WRKSRC}/src/AppDirs.vala

.include <bsd.port.pre.mk>

# graphics/libraw
.if exists(${LOCALBASE}/lib/libraw.so.0)
LIB_DEPENDS+=	libraw.0:${PORTSDIR}/graphics/libraw
.endif

# attempt at a DATADIR safe port
.for dir in ${DATADIR:S,^${PREFIX}/,,:S,/, ,g}
SHOTWELL_DATADIR+=.get_child("${dir}")
.endfor

.include <bsd.port.post.mk>
