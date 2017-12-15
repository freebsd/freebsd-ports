# $FreeBSD$

PORTNAME=	graphene
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Optimizations for speeding up vector operations

LICENSE=	MIT

USES=		gnome meson pkgconfig python:3.4+ shebangfix tar:xz
USE_GNOME=	glib20 py3gobject3

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	GTKDOC #INTROSPECTION
#OPTIONS_DEFAULT=INTROSPECTION

SHEBANG_FILES=	src/identfilter.py

USE_GNOME+=		introspection:build
#INTROSPECTION_DESC=	Build Gobject Introspection
#INTROSPECTION_USE=	gnome=introspection:build
#INTROSPECTION_MESON_OFF=	-Denable-introspection=false

GTKDOC_MESON_TRUE=	enable-gtk-doc
GTKDOC_DESC=		Build documentation

post-patch:
	@${REINPLACE_CMD} -e 's|=python |=${PYTHON_VERSION} |g' \
		${WRKSRC}/src/meson.build

# We don't want install tests
post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/libexec/installed-tests

.include <bsd.port.mk>
