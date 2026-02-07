PORTNAME=	libpeas
PORTVERSION=	2.0.7
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Gobject-based plugins engine (Peas 2 API)
WWW=		https://gitlab.gnome.org/GNOME/libpeas

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext gnome meson pathfix pkgconfig python tar:xz \
		vala:build
USE_GNOME=	introspection libxml2 pygobject3
CPE_VENDOR=	gnome

MESON_ARGS=	-Dlua51=false

LIBPEAS_SLAVE?=	no

.if ${LIBPEAS_SLAVE} == no
LIB_DEPENDS=	libmozjs-128.so:lang/spidermonkey128 \
		libgjs.so:lang/gjs

USE_GNOME+=	gtk30
USE_LDCONFIG=	yes

MESON_ARGS+=	-Dvapi=true \
		-Dpython3=false
PLIST=		${.CURDIR}/pkg-plist
.endif

pre-build:
# XXX DISABLE_MAKE_JOBS build fails on 12.2/13.0 i386
	${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} \
		tests/libpeas/plugins/embedded/embedded-resources.h

.if ${LIBPEAS_SLAVE} == python
LIB_DEPENDS+=	libpeas-2.so:devel/libpeas

USE_PYTHON=	flavors
USE_GNOME+=	pygobject3
MESON_ARGS+=	-Dpython3=true \
		-Dgjs=false
ALL_TARGET=	loaders/python/libpythonloader.so

post-patch:
	${REINPLACE_CMD} -e "s|dependency('python3'|dependency('python-${PYTHON_VER}'|" \
		-e "s|dependency('python3-embed'|dependency('python-${PYTHON_VER}-embed'|" \
		${WRKSRC}/meson.build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libpeas-2/loaders/
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/loaders/python/libpythonloader.so \
		${STAGEDIR}${PREFIX}/lib/libpeas-2/loaders/
.endif

.include <bsd.port.mk>
