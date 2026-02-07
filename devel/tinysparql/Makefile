PORTNAME=	tinysparql
PORTVERSION=	3.10.1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER= 	gnome@FreeBSD.org
COMMENT=	RDF triple store library with SPARQL 1.1 interface
WWW=		https://gitlab.gnome.org/GNOME/tinysparql

LICENSE= 	LGPL21+ GPLv2+ BSD3CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libsoup-3.0.so:devel/libsoup3 \
		libstemmer.so:textproc/snowballstemmer \
		libicutu.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \

USES=		gettext gnome localbase:ldflags meson pkgconfig python:build sqlite tar:xz
USE_GNOME=	glib20 introspection:build libxml2 pygobject3

BINARY_ALIAS=	python3=${PYTHON_VERSION}
MESON_ARGS=	-Dsystemd_user_services=false \
		-Dintrospection=enabled

OPTIONS_DEFINE=	AVAHI BASH DOCS MANPAGES TEST VAPI
OPTIONS_DEFAULT=	AVAHI BASH MANPAGES VAPI
OPTIONS_SUB=	yes

AVAHI_LIB_DEPENDS=	libavahi-glib.so:net/avahi-app
AVAHI_MESON_ENABLED=	avahi

BASH_MESON_TRUE=	bash_completion
BASH_MESON_ON=		-Dbash_completion_dir=${PREFIX}/etc/bash_completion.d

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

MANPAGES_MESON_TRUE=	man

TEST_MESON_TRUE=	tests

VAPI_USES=		vala:build
VAPI_MESON_ENABLED=	vapi

post-install:
	@(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libtracker-sparql-3.0.so.0.1001.0 \
		libtracker-sparql-3.0.so)

.include <bsd.port.mk>
