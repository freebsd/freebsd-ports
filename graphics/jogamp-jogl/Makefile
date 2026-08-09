PORTNAME=	jogamp-jogl
PORTVERSION=	2.6.0
CATEGORIES=	graphics devel java
MASTER_SITES=	https://jogamp.org/deployment/jogamp-current/archive/Sources/ \
		https://jogamp.org/deployment/v${PORTVERSION}/archive/Sources/
DISTFILES=	jogl-v${PORTVERSION}.tar.xz \
		gluegen-v${PORTVERSION}.tar.xz \
		jcpp-v${PORTVERSION}.tar.xz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java bindings for OpenGL
WWW=		https://jogamp.org/jogl

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKDIR}/jogl/LICENSE.txt

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:x11-toolkits/swt

USES=		compiler java:ant,run tar:xz xorg
#JAVA_VERSION=	25
USE_XORG=	x11 xcursor xi xrandr xrender xxf86vm
NO_SHLIB_REQUIRES_GLOB=	libjawt.so libjvm.so

ONLY_FOR_ARCHS=	amd64 i386 powerpc64 powerpc64le

PATCH_WRKSRC=	${WRKDIR}
BUILD_WRKSRC=	${WRKDIR}/jogl/make

# compiler must be literally "gcc" or "clang"
BINARY_ALIAS=	${CHOSEN_COMPILER_TYPE}=${CC}
JAVA_MAJOR_VER=	${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/}
MAKE_ARGS=	-Dgcc.compat.compiler=${CHOSEN_COMPILER_TYPE}
MAKE_ENV=	CLASSPATH=		\
		SOURCE_LEVEL=${JAVA_MAJOR_VER}	\
		TARGET_LEVEL=${JAVA_MAJOR_VER}	\
		TARGET_RT_JAR=""
#		TARGET_RT_JAR=${JAVA_HOME}/jre/lib/rt.jar

post-extract:
	${MV} ${WRKDIR}/gluegen-v${PORTVERSION} ${WRKDIR}/gluegen
	${MV} ${WRKDIR}/jcpp-v${PORTVERSION}/src ${WRKDIR}/gluegen/jcpp/src
	${MV} ${WRKDIR}/jogl-v${PORTVERSION} ${WRKDIR}/jogl

pre-configure:
	${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|g' \
		${BUILD_WRKSRC}/build-common.xml
	${REINPLACE_CMD} -e '/name="all"/s|,test.compile||g' \
		${BUILD_WRKSRC}/build.xml

pre-build:
	(cd ${WRKDIR}/gluegen/make; \
		${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} all.no_junit)

do-install:
	${INSTALL_LIB} \
		${WRKDIR}/gluegen/build/obj/libgluegen2_rt.so \
		${WRKDIR}/jogl/build/lib/*.so \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} \
		${WRKDIR}/gluegen/build/gluegen2-rt.jar \
		${WRKDIR}/gluegen/build/gluegen2.jar \
		${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/jogl/build/jar/jogl-all.jar \
		${STAGEDIR}${JAVAJARDIR}/jogl2.jar

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libgluegen2_rt.so	\
		${STAGEDIR}${PREFIX}/lib/libgluegen_rt.so

.include <bsd.port.mk>
