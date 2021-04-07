PORTNAME=	graphene
DISTVERSION=	1.10.4
CATEGORIES=	graphics devel
MASTER_SITES=	https://github.com/ebassi/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Optimizations for speeding up vector operations

LICENSE=	MIT

USES=		compiler:c11 gnome meson pkgconfig python:3.6+ shebangfix tar:xz
USE_GNOME=	glib20 pygobject3
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS #INTROSPECTION
#OPTIONS_DEFAULT=INTROSPECTION

SHEBANG_FILES=	src/identfilter.py

USE_GNOME+=		introspection:build
#INTROSPECTION_DESC=	Build Gobject Introspection
#INTROSPECTION_USE=	gnome=introspection:build
#INTROSPECTION_MESON_OFF=	-Denable-introspection=false

DOCS_MESON_TRUE=	gtk_doc
DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc

BINARY_ALIAS=	python3=${PYTHON_CMD}

# We don't want install tests
post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/libexec/installed-tests
	@${RM} -rf ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
