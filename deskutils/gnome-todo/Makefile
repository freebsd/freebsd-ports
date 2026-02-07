PORTNAME=	gnome-todo
PORTVERSION=	41.0
PORTREVISION=	6
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small application to manage your personal tasks
WWW=		https://wiki.gnome.org/Apps/Todo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		itstool>0:textproc/itstool
LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
		libgraphene-1.0.so:graphics/graphene \
		libical.so:devel/libical \
		libpeas-1.0.so:devel/libpeas1 \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python:build shebangfix tar:xz
USE_GNOME=	cairo evolutiondataserver3 gnomedesktop3 gtk40 introspection \
		libadwaita
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.todo.gschema.xml

.include <bsd.port.mk>
