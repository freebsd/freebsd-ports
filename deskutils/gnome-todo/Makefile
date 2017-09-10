# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-todo
PORTVERSION=	3.18.1
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small application to manage your personal tasks

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 gnomedesktop3 gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.todo.gschema.xml

.include <bsd.port.mk>
