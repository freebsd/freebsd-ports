# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	resynthesizer
PORTVERSION=	2.0.1
PORTREVISION=	4
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gimp plug-in for texture synthesis

LICENSE=	GPLv2+ # though COPYING has GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/libexec/gimp/2.2/python/gimpfu.py:graphics/py-gimp
BUILD_DEPENDS=	intltool-extract:textproc/intltool
LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app

USE_GITHUB=	yes
GH_ACCOUNT=	bootchk

USES=		autoreconf compiler:nestedfct gettext gmake localbase pkgconfig python:run shebangfix
SHEBANG_FILES=	PluginScripts/*.py
GNU_CONFIGURE=	yes

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

OPTIONS_DEFINE=	THREADS
THREADS_DESC=	Threading support (produces nondeterministic results)
THREADS_LIBS=	`pkg-config --libs gthread-2.0`

post-patch:
	@${REINPLACE_CMD} -e 's|^\(GIMP_LIBDIR=\).*|\1"$${prefix}/${PLUGIN_DIR:H}"|; \
		s|^\(gimpplugindir=\).*|\1"$$GIMP_LIBDIR"|' ${WRKSRC}/configure.ac

post-patch-THREADS-off:
	@${REINPLACE_CMD} -e '/^#define SYNTH_THREADED/ d' \
		${WRKSRC}/lib/buildSwitches.h

.include <bsd.port.mk>
