# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	engine-opengl
PORTVERSION=	1.7.8
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	evas-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (OpenGL engine)

LICENSE=	BSD

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_EFL=	evas librt_hack libtool_hack
USE_XORG=	x11 xext xrender
USE_GL=		gl glu
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/modules/engines/gl_x11
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include "../evas-core/Makefile.inc"
CONFIGURE_ARGS+=	--enable-gl-xlib

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/\.libs,${LOCALBASE}/lib,' \
		-e 's,\$$\(top_builddir\)/src/lib/libevas\.la,-levas,' \
		${BUILD_WRKSRC}/Makefile.in \
		${WRKSRC}/src/modules/engines/gl_common/Makefile.in

pre-build:
	@(cd ${WRKSRC}/src/modules/engines/gl_common; ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-opengl-x11.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
