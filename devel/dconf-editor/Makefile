PORTNAME=	dconf-editor
PORTVERSION=	3.38.3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	56474378568e.patch:-p1 # https://gitlab.gnome.org/GNOME/dconf-editor/-/merge_requests/21

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database editor for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dconf>=0.23.2:devel/dconf \
		vala>=0.18.1:lang/vala
LIB_DEPENDS=	libdconf.so:devel/dconf

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson \
		pkgconfig python:3.6+,build tar:xz
USE_GNOME=	gtk30
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	ca.desrt.dconf-editor.gschema.xml

.include <bsd.port.mk>
