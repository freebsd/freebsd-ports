# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	libpeas
PORTVERSION=	1.26.0
PORTREVISION?=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Next evolution of the Gedit plugins engine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

LIBPEAS_SLAVE?=	no

.if ${LIBPEAS_SLAVE} == no
PORTSCOUT=	limitw:1,even
.else
LIB_DEPENDS+=	libpeas-1.0.so:devel/libpeas
PORTSCOUT=	ignore:1
.endif

USES=		cpe gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack introspection
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome
MESON_ARGS+=	-Dglade_catalog=false
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

pre-build:
# XXX DISABLE_MAKE_JOBS build fails on 12.2/13.0 i386
	${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} \
		tests/libpeas/plugins/embedded/embedded-resources.h

.if ${LIBPEAS_SLAVE} == python
USES+=		python:3.6+
USE_PYTHON=	flavors
USE_GNOME+=	pygobject3
MESON_ARGS+=	-Dpython3=true
ALL_TARGET=	loaders/python3/libpython3loader.so

post-patch:
	${REINPLACE_CMD} -e "s|dependency('python3'|dependency('python-${PYTHON_VER}'|" \
		-e "s|dependency('python3-embed'|dependency('python-${PYTHON_VER}-embed'|" \
		${WRKSRC}/meson.build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libpeas-1.0/loaders/
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/loaders/python3/libpython3loader.so \
		${STAGEDIR}${PREFIX}/lib/libpeas-1.0/loaders/

.else
MESON_ARGS+=	-Dpython3=false
.endif

# lua needs lua 5.1 and devel/lua-lgi. The latter is build for lua 5.2 however..
MESON_ARGS+=	-Dpython2=false -Dlua51=false

.include <bsd.port.mk>
