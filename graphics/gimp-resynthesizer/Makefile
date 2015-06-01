# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	resynthesizer
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gimp plug-in for texture synthesis

LICENSE=	GPLv2 # or later (COPYING has GPLv3)

RUN_DEPENDS=	${LOCALBASE}/libexec/gimp/2.2/python/gimpfu.py:${PORTSDIR}/graphics/py-gimp
BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app

USE_GITHUB=	yes
GH_ACCOUNT=	bootchk

USES=		autoreconf compiler:nestedfct gettext gmake pkgconfig
GNU_CONFIGURE=	yes

LIBS+=		-L${LOCALBASE}/lib -lintl

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

OPTIONS_DEFINE=	THREADS
THREADS_DESC=	Threading support (produces nondeterministic results)

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^\(GIMP_LIBDIR=\).*|\1"$${prefix}/${PLUGIN_DIR:H}"|; \
		s|^\(gimpplugindir=\).*|\1"$$GIMP_LIBDIR"|' ${WRKSRC}/configure.in
.if ! ${PORT_OPTIONS:MTHREADS}
	@${REINPLACE_CMD} -e '/^#define SYNTH_THREADED/ d' \
		${WRKSRC}/src/buildSwitches.h
.endif

.include <bsd.port.mk>
