# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	polari
PORTVERSION=	41.0
CATEGORIES=	irc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	0f0a4b54142d.patch:-p1 # https://gitlab.gnome.org/GNOME/gtranslator/-/merge_requests/90

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Internet Relay Chat (IRC) client designed for GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		gjs-console:lang/gjs \
		itstool:textproc/itstool
LIB_DEPENDS=	libtelepathy-glib.so:net-im/telepathy-glib \
		libsecret-1.so:security/libsecret \
		libtelepathy-logger.so:net-im/telepathy-logger
RUN_DEPENDS=	gjs-console:lang/gjs \
		telepathy-idle>0:net-im/telepathy-idle \
		gspell>0:textproc/gspell

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gnome localbase \
		meson pkgconfig tar:xz
USE_GNOME=	cairo gtk30 introspection
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.Polari.gschema.xml

.include <bsd.port.mk>
