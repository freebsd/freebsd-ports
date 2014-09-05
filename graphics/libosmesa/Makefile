# Created by: gahr
# $FreeBSD$

PORTNAME=	libosmesa
PORTVERSION=	10.2.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${PORTVERSION}/
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Off-Screen Mesa implementation of the OpenGL API

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

USES=		gmake pkgconfig tar:bzip2 libtool python:2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-osmesa \
		--disable-driglx-direct \
		--disable-gallium-llvm \
		--disable-glx \
		--disable-dri \
		--disable-egl \
		--with-gallium-drivers=swrast
CFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
MAKE_JOBS_UNSAFE=yes

INCLUDES=	gl.h gl_mangle.h glext.h glx.h glx_mangle.h \
		glxext.h osmesa.h wglext.h wmesa.h

post-patch:
	${REINPLACE_CMD} \
	    -e '/^OSMESA_VERSION=/s|8|9|' \
	    -e 's|-fno-builtin-memcmp||g' \
	    ${WRKSRC}/configure

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/Mesa/GL
.for inc in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/include/GL/${inc} ${STAGEDIR}${PREFIX}/include/Mesa/GL/
.endfor
	${INSTALL_LIB} ${WRKSRC}/src/mesa/drivers/osmesa/.libs/libOSMesa.so.9.0.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -s libOSMesa.so.9.0.0 ${STAGEDIR}${PREFIX}/lib/libOSMesa.so.9
	${LN} -s libOSMesa.so.9.0.0 ${STAGEDIR}${PREFIX}/lib/libOSMesa.so
	${INSTALL_DATA} ${WRKSRC}/src/mesa/drivers/osmesa/osmesa.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/osmesa.pc

.include <bsd.port.mk>
