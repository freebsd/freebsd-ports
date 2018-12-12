# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-todo
PORTVERSION=	3.28.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small application to manage your personal tasks

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libgoa-1.0.so:net/gnome-online-accounts \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libical.so:devel/libical

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python:3.4+,build shebangfix tar:xz
USE_GNOME=	cairo evolutiondataserver3 gnomedesktop3 gtk30 introspection
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
SHEBANG_FILES=	meson_post_install.py

GLIB_SCHEMAS=	org.gnome.todo.background.gschema.xml \
		org.gnome.todo.enums.xml \
		org.gnome.todo.gschema.xml \
		org.gnome.todo.txt.gschema.xml

.include <bsd.port.mk>
