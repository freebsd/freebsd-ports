PORTNAME=	baobab
PORTVERSION=	47.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME graphical directory tree analyzer
WWW=		https://apps.gnome.org/Baobab/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		desktop-file-utils gettext gnome meson pkgconfig \
		python:build tar:xz vala:build
USE_GNOME=	cairo glib20 gtk40 libadwaita

BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.baobab.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|MimeType=inode/directory;|MimeType=|g' \
		${WRKSRC}/data/org.gnome.baobab.desktop.in

.include <bsd.port.mk>
