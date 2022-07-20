PORTNAME=	gexiv2
PORTVERSION=	0.14.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	GObject-based wrapper around Exiv2 library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR} \
		vala>=0:lang/vala
LIB_DEPENDS= 	libexiv2.so:graphics/exiv2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR}

USES=		compiler:c++11-lang gnome libtool:build meson pathfix pkgconfig \
		python:build tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
BINARY_WRAPPERS=	gm4
BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_CONFIGURE_ON=	-Dgtk_doc=true

.include <bsd.port.options.mk>

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vala/vapi

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgexiv2.so
	${RM} -r ${STAGEDIR}${PREFIX}/lib/python*

.include <bsd.port.mk>
