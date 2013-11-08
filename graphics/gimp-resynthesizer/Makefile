# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	resynthesizer
PORTVERSION=	2.0
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gimp plug-in for texture synthesis

RUN_DEPENDS=	${LOCALBASE}/libexec/gimp/2.2/python/gimpfu.py:${PORTSDIR}/graphics/py-gimp
BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app

USE_GITHUB=	yes
GH_ACCOUNT=	bootchk
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	28cade5

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl"
USES=		gettext gmake pkgconfig
USE_AUTOTOOLS=	aclocal automake
AUTOMAKE_ARGS=	--add-missing
USE_GCC=	any # uses nested functions (gcc ext.)

OPTIONS_DEFINE=	THREADS
THREADS_DESC=	Threading support (produces nondeterministic results)

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^\(gimpplugindir=\).*|\1"$$GIMP_LIBDIR"|' \
		${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MTHREADS}
	@${REINPLACE_CMD} -e '/^#define SYNTH_THREADED/ d' \
		${WRKSRC}/src/buildSwitches.h
.endif

.include <bsd.port.mk>
