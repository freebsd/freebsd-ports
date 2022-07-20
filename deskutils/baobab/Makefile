PORTNAME=	baobab
PORTVERSION=	42.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME graphical directory tree analyzer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

BUILD_DEPENDS=	valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libhandy-1.so:x11-toolkits/libhandy

USES=		desktop-file-utils gettext gnome meson pkgconfig \
		python:3.5+,build tar:xz
USE_GNOME=	cairo gtk40 libadwaita

BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.baobab.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|MimeType=inode/directory;|MimeType=|g' \
		${WRKSRC}/data/org.gnome.baobab.desktop.in

.include <bsd.port.mk>
