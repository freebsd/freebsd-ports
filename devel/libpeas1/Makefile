PORTNAME=	libpeas
PORTVERSION=	1.36.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	1
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Gobject-based plugins engine (Peas 1.0 API)
WWW=		https://gitlab.gnome.org/GNOME/libpeas

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext gnome meson pathfix pkgconfig tar:xz \
		vala:build
USE_GNOME=	introspection libxml2
CPE_VENDOR=	gnome

MESON_ARGS=	-Dglade_catalog=false \
		-Dlua51=false

LIBPEAS_SLAVE?=	no

.if ${LIBPEAS_SLAVE} == no
USE_GNOME+=	gtk30
USE_LDCONFIG=	yes

MESON_ARGS+=	-Dvapi=true \
		-Dpython3=false
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=	DEMOS DOCS
OPTIONS_SUB=	yes

DOCS_USES=		python
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	gtk_doc

DEMOS_DESC=		Build demo programs
DEMOS_MESON_TRUE=	demos
.endif

pre-build:
# XXX DISABLE_MAKE_JOBS build fails on 12.2/13.0 i386
	${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} \
		tests/libpeas/plugins/embedded/embedded-resources.h

.if ${LIBPEAS_SLAVE} == python
LIB_DEPENDS+=	libpeas-1.0.so:devel/libpeas1

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
