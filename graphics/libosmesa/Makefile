# Created by: gahr
# $FreeBSD$

PORTNAME=	libosmesa
PORTVERSION=	9.1.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${PORTVERSION}/
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Off-Screen Mesa implementation of the OpenGL API

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
    		talloc:${PORTSDIR}/devel/talloc
BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

CONFLICTS=	mesagl-mangled-*

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_SCONS=	yes
SCONS_TARGET=	osmesa
SCONS_ARGS+=	build=release \
		verbose=yes
SCONS_BUILDENV=	CC="${CC}" \
		CXX="${CXX}" \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAKE_JOBS_UNSAFE=

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}

.include <bsd.port.pre.mk>

.if (empty(CC:T:Mgcc4*) && empty(CC:T:Mclang*)) || (empty(CXX:T:Mg??4*) && empty(CXX:T:Mclang++*))
.if (${OSVERSION} >= 900014) && (exists(/usr/bin/clang++) && exists(/usr/bin/clang))
CC=	/usr/bin/clang
CXX=	/usr/bin/clang++
CPP=	/usr/bin/clang-cpp
.else
USE_GCC=yes
.endif
.endif

.if ${ARCH} == "i386"
SCONS_ARGS+=	machine=x86
SCONS_BUILD_DIR=${WRKSRC}/build/freebsd-x86
.elif ${ARCH} == "amd64"
SCONS_ARGS+=	machine=x86_64
SCONS_BUILD_DIR=${WRKSRC}/build/freebsd-x86_64
.else
SCONS_ARGS+=	machine=generic
SCONS_BUILD_DIR=${WRKSRC}/build/freebsd
.endif

INCLUDES=	gl.h gl_mangle.h glext.h glx.h glx_mangle.h \
		glxext.h osmesa.h wglext.h wmesa.h

post-patch:
	${REINPLACE_CMD}  -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/scons/custom.py
	${REINPLACE_CMD}  -e \
	    's|@prefix@|${PREFIX}|; \
	    s|@libdir@|${PREFIX}/lib|; \
	    s|@includedir@|${PREFIX}/include/Mesa|; \
	    s|@OSMESA_VERSION@|${PORTVERSION}|; \
	    s|@OSMESA_LIB@|OSMesa|; \
	    s|@OSMESA_PC_REQ@||; \
	    s|@OSMESA_PC_LIB_PRIV@|-lm -pthread|' \
	    ${WRKSRC}/src/mesa/drivers/osmesa/osmesa.pc.in

do-install:
	${MKDIR} ${PREFIX}/include/Mesa/GL
.for inc in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/include/GL/${inc} ${PREFIX}/include/Mesa/GL/
.endfor
	${INSTALL_DATA} ${SCONS_BUILD_DIR}/mesa/drivers/osmesa/libosmesa.so ${PREFIX}/lib/libOSMesa.so.9
	${LN} -sf libOSMesa.so.9 ${PREFIX}/lib/libOSMesa.so
	${INSTALL_DATA} ${WRKSRC}/src/mesa/drivers/osmesa/osmesa.pc.in ${PREFIX}/libdata/pkgconfig/osmesa.pc

.include <bsd.port.post.mk>
