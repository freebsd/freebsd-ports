# New ports collection makefile for:	libosmesa
# Date created:				9 April 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	libosmesa
PORTVERSION=	7.10.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${PORTVERSION}/
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Off-Screen Mesa implementation of the OpenGL API

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
    		talloc.2:${PORTSDIR}/devel/talloc
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2 \
    		makedepend:${PORTSDIR}/devel/makedepend
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	mesagl-mangled-*

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_LDCONFIG=	yes
USE_XORG=	xxf86vm xext xfixes xdamage xt
USE_GMAKE=	yes
USE_PYTHON_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-driver=osmesa --with-osmesa-bits=32 \
		--includedir=${PREFIX}/include/Mesa
CFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}

GLINC=		gl.h glext.h osmesa.h
GLLIB=		OSMesa32
SHLIB_VERS=	${PORTVERSION:R:R}

do-install:
	${MKDIR} ${PREFIX}/include/Mesa/GL
	${MKDIR} ${PREFIX}/lib
	${MKDIR} ${PREFIX}/libdata/pkgconfig
# header files
.for i in ${GLINC}
	${INSTALL_DATA} ${WRKSRC}/include/GL/${i} ${PREFIX}/include/Mesa/GL/
.endfor
# shlib
	${INSTALL_DATA} ${WRKSRC}/lib/libOSMesa32.so.${SHLIB_VERS} ${PREFIX}/lib
	${LN} -sf libOSMesa32.so.${SHLIB_VERS} ${PREFIX}/lib/libOSMesa32.so
	${LN} -sf libOSMesa32.so.${SHLIB_VERS} ${PREFIX}/lib/libOSMesa.so.${SHLIB_VERS}
	${LN} -sf libOSMesa32.so.${SHLIB_VERS} ${PREFIX}/lib/libOSMesa.so
# pkg-config
	cd ${WRKSRC}/src/mesa && ${GMAKE} osmesa.pc
	${INSTALL_DATA} ${WRKSRC}/src/mesa/osmesa.pc ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
