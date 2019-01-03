# $FreeBSD$

PORTNAME=	lookbook
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Browse and find system icons

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgranite.so:x11-toolkits/granite

USES=		gettext-tools gnome meson pkgconfig python:3.5+,build
USE_GITHUB=	yes
GH_ACCOUNT=	danrabbit
USE_GNOME=	glib20 gtk30 gtksourceview3
GLIB_SCHEMAS=	com.github.danrabbit.lookbook.gschema.xml
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} # for meson/post_install.py

.include <bsd.port.mk>
