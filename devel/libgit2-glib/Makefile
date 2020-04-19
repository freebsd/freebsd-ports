# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

# Also update devel/libgit2, devel/rubygem-rugged, devel/py-pygit2

PORTNAME=	libgit2-glib
PORTVERSION=	0.99.0.1
PORTREVISION=	1
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
MESON_ARGS=	-Dpython=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}

# XXX: meson_vapi_link.py does not respect STAGEDIR for some reason and silently
# fails when building as user and touches the external fs when building as root.
# Neutralize it.  We replicate what it does in post-install.
post-patch:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/meson_vapi_link.py

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/vala/vapi/libgit2-glib-1.0.deps \
		${STAGEDIR}${PREFIX}/share/vala/vapi/ggit-1.0.deps
	${RLN} ${STAGEDIR}${PREFIX}/share/vala/vapi/libgit2-glib-1.0.vapi \
		${STAGEDIR}${PREFIX}/share/vala/vapi/ggit-1.0.vapi

.include <bsd.port.mk>
