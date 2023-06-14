PORTNAME=	graphene
DISTVERSION=	1.10.8
CATEGORIES=	graphics devel

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Optimizations for speeding up vector operations
WWW=		https://ebassi.github.io/graphene/

LICENSE=	MIT

USES=		compiler:c11 gnome meson pkgconfig python shebangfix
USE_GNOME=	glib20 pygobject3
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ebassi

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
