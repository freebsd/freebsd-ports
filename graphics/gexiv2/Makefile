PORTNAME=	gexiv2
PORTVERSION=	0.14.5
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	GObject-based wrapper around Exiv2 library
WWW=		https://wiki.gnome.org/Projects/gexiv2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		compiler:c++17-lang gnome libtool:build meson pathfix pkgconfig \
		python:build tar:xz vala:build
USE_GNOME=	glib20 introspection:build pygobject3
USE_LDCONFIG=	yes
BINARY_WRAPPERS=	gm4
BINARY_ALIAS=	python3=${PYTHON_CMD}

USE_CXXSTD=	c++17

PLIST_SUB=	SOVERSION=${PORTVERSION:C/^0./2./}

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_CONFIGURE_ON=	-Dgtk_doc=true

PORTSCOUT=	limitw:1,even

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vala/vapi

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgexiv2.so
	${RM} -r ${STAGEDIR}${PREFIX}/lib/python*

.include <bsd.port.mk>
