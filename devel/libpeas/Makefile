PORTNAME=	libpeas
PORTVERSION=	1.34.0
PORTREVISION?=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Next evolution of the Gedit plugins engine
WWW=		https://wiki.gnome.org/Projects/Libpeas

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

USES=		cpe gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo introspection libxml2
CPE_VENDOR=	gnome

MESON_ARGS=	-Dglade_catalog=false \
		-Dlua51=false

LIBPEAS_SLAVE?=	no

.if ${LIBPEAS_SLAVE} == no
PORTSCOUT=	limitw:1,even

USE_GNOME+=	gtk30
USE_LDCONFIG=	yes

MESON_ARGS+=	-Dvapi=true \
		-Dpython3=false
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=	DEMOS DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

DEMOS_DESC=		Build demo programs
DEMOS_MESON_TRUE=	demos
.endif

pre-build:
# XXX DISABLE_MAKE_JOBS build fails on 12.2/13.0 i386
	${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} \
		tests/libpeas/plugins/embedded/embedded-resources.h

.if ${LIBPEAS_SLAVE} == python
LIB_DEPENDS+=	libpeas-1.0.so:devel/libpeas
PORTSCOUT=	limitw:1,even

USES+=		python
USE_PYTHON=	flavors
USE_GNOME+=	pygobject3
MESON_ARGS+=	-Dpython3=true \
		-Dgtk_doc=false \
		-Ddemos=false \
		-Dvapi=false
ALL_TARGET=	loaders/python3/libpython3loader.so

post-patch:
	${REINPLACE_CMD} -e "s|dependency('python3'|dependency('python-${PYTHON_VER}'|" \
		-e "s|dependency('python3-embed'|dependency('python-${PYTHON_VER}-embed'|" \
		${WRKSRC}/meson.build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libpeas-1.0/loaders/
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/loaders/python3/libpython3loader.so \
		${STAGEDIR}${PREFIX}/lib/libpeas-1.0/loaders/
.endif

.include <bsd.port.mk>
