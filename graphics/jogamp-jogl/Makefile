# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=	jogamp-jogl
PORTVERSION=	2.3.2
CATEGORIES=	graphics devel java
MASTER_SITES=	http://jogamp.org/deployment/jogamp-current/archive/Sources/ \
		http://jogamp.org/deployment/v${PORTVERSION}/archive/Sources/
DISTFILES=	jogl-v${PORTVERSION}.tar.xz \
		gluegen-v${PORTVERSION}.tar.xz \
		jcpp-v${PORTVERSION}.tar.xz

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Java bindings for OpenGL

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt

ONLY_FOR_ARCHS=	i386 amd64

USES=		tar:xz xorg

USE_ANT=	yes
USE_GCC=	yes
USE_JAVA=	yes
USE_XORG=	x11 xcursor xrandr xrender xxf86vm

PATCH_WRKSRC=	${WRKDIR}
BUILD_WRKSRC=	${WRKDIR}/jogl/make
BUILD_BINPATH=	${WRKSRC}/bin
MAKE_ENV+=	PATH="${BUILD_BINPATH}:${PATH}"

post-extract:
	${MV} ${WRKDIR}/gluegen-v${PORTVERSION} ${WRKDIR}/gluegen
	${MV} ${WRKDIR}/jcpp-v${PORTVERSION}/src ${WRKDIR}/gluegen/jcpp/src
	${MV} ${WRKDIR}/jogl-v${PORTVERSION} ${WRKDIR}/jogl
	${MKDIR} ${BUILD_BINPATH}
	${LN} -sf ${LOCALBASE}/bin/${CC} ${BUILD_BINPATH}/gcc

post-patch:
	${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|g' \
		${BUILD_WRKSRC}/build-common.xml
	${REINPLACE_CMD} -e '/name="all"/s|,test.compile||g' \
		${BUILD_WRKSRC}/build.xml

pre-build:
	@(cd ${WRKDIR}/gluegen/make; \
		${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} all.no_junit)

do-install:
	${INSTALL_LIB} \
		${WRKDIR}/gluegen/build/obj/libgluegen2-rt.so \
		${WRKDIR}/jogl/build/lib/*.so \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} \
		${WRKDIR}/gluegen/build/gluegen2-rt.jar \
		${WRKDIR}/gluegen/build/gluegen2.jar \
		${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/jogl/build/jar/jogl-all.jar \
		${STAGEDIR}${JAVAJARDIR}/jogl2.jar

.include <bsd.port.mk>
