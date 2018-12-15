# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

# Also update devel/libgit2, devel/rubygem-rugged, devel/py-pygit2

PORTNAME=	libgit2-glib
PORTVERSION=	0.27.7
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib wrapper library around the libgit2 git access library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		compiler:c11 gnome localbase \
		meson pkgconfig python:3.4+,build tar:xz
USE_GNOME=	glib20 introspection
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dpython=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
