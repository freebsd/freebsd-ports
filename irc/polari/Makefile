# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	polari
PORTVERSION=	3.38.0
PORTREVISION=	1
CATEGORIES=	irc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

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
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.Polari.gschema.xml

.include <bsd.port.mk>
