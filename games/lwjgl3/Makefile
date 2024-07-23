PORTNAME=	lwjgl
DISTVERSION=	3.3.4.20240717
CATEGORIES=	games java
MASTER_SITES=	https://repo1.maven.org/:source1
PKGNAMESUFFIX=	3
DISTFILES=	maven2/com/beust/jcommander/1.78/jcommander-1.78.jar:source1 \
		maven2/com/google/code/findbugs/jsr305/3.0.2/jsr305-3.0.2-sources.jar:source1 \
		maven2/com/google/code/findbugs/jsr305/3.0.2/jsr305-3.0.2.jar:source1 \
		maven2/net/sf/jopt-simple/jopt-simple/5.0.4/jopt-simple-5.0.4.jar:source1 \
		maven2/org/apache/commons/commons-math3/3.6.1/commons-math3-3.6.1.jar:source1 \
		maven2/org/joml/joml/1.10.7/joml-1.10.7-sources.jar:source1 \
		maven2/org/joml/joml/1.10.7/joml-1.10.7.jar:source1 \
		maven2/org/openjdk/jmh/jmh-core/1.37/jmh-core-1.37-sources.jar:source1 \
		maven2/org/openjdk/jmh/jmh-core/1.37/jmh-core-1.37.jar:source1 \
		maven2/org/openjdk/jmh/jmh-generator-annprocess/1.37/jmh-generator-annprocess-1.37.jar:source1 \
		maven2/org/slf4j/slf4j-api/1.7.36/slf4j-api-1.7.36.jar:source1 \
		maven2/org/slf4j/slf4j-jdk14/1.7.36/slf4j-jdk14-1.7.36.jar:source1 \
		maven2/org/testng/testng/7.5/testng-7.5-sources.jar:source1 \
		maven2/org/testng/testng/7.5/testng-7.5.jar:source1 \
		maven2/org/webjars/jquery/3.5.1/jquery-3.5.1.jar:source1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Lightweight Java Game Library
WWW=		https://www.lwjgl.org

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Upstream support FreeBSD on amd64 only: https://github.com/LWJGL/lwjgl3/issues/421

BUILD_DEPENDS=		${LOCALBASE}/openjdk8/bin/java:java/openjdk8 \
			kotlinc-jvm:lang/kotlin
LIB_DEPENDS=		libdraco.so:archivers/draco \
			libopenal.so:audio/openal-soft \
			libopus.so:audio/opus \
			libdbus-1.so:devel/dbus \
			libhwloc.so:devel/hwloc2 \
			libffi.so:devel/libffi \
			libbgfx.so:graphics/bgfx \
			libglfw.so:graphics/glfw \
			libktx.so:graphics/khronos-texture \
			libopenxr_loader.so:graphics/openxr \
			libshaderc_shared.so:graphics/shaderc \
			libspirv-cross-c-shared.so:graphics/spirv-cross \
			libassimp.so:multimedia/assimp \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz

USES=		gl gnome
USE_ANT=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tu}
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}
GH_TAGNAME=	${DISTVERSION:R}
USE_GL=		gl
USE_GNOME=	glib20 gtk30
USE_JAVA=	17+

MAKE_ARGS=	-Dbuild.offline=true \
		-Djavadoc.skip=true \
		-Duse.libffi.so=true \
		-Dlibffi.path=${LOCALBASE}/lib \
		-Dlocal.kotlin=${LOCALBASE}/share/kotlin
MAKE_ENV+=	JAVA8_HOME=${LOCALBASE}/openjdk8

PLIST_SUB+=	MAJORVERSION=${PKGNAMESUFFIX}

LIBSDIR=	${WRKSRC}/bin/libs/native/freebsd/*/org/lwjgl

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
MAKE_ENV+=	ANT_OPTS=-Xmx2G
.endif

post-extract:
	${MKDIR} ${WRKSRC}/bin/libs/java
	${LN} -s ${DISTDIR}/maven2/com/beust/jcommander/1.78/jcommander-1.78.jar \
		${WRKSRC}/bin/libs/java/jcommander.jar
	${LN} -s ${DISTDIR}/maven2/com/google/code/findbugs/jsr305/3.0.2/jsr305-3.0.2-sources.jar \
		${WRKSRC}/bin/libs/java/jsr305-sources.jar
	${LN} -s ${DISTDIR}/maven2/com/google/code/findbugs/jsr305/3.0.2/jsr305-3.0.2.jar \
		${WRKSRC}/bin/libs/java/jsr305.jar
	${LN} -s ${DISTDIR}/maven2/net/sf/jopt-simple/jopt-simple/5.0.4/jopt-simple-5.0.4.jar \
		${WRKSRC}/bin/libs/java/jopt-simple.jar
	${LN} -s ${DISTDIR}/maven2/org/apache/commons/commons-math3/3.6.1/commons-math3-3.6.1.jar \
		${WRKSRC}/bin/libs/java/commons-math3.jar
	${LN} -s ${DISTDIR}/maven2/org/joml/joml/1.10.7/joml-1.10.7-sources.jar \
		${WRKSRC}/bin/libs/java/joml-sources.jar
	${LN} -s ${DISTDIR}/maven2/org/joml/joml/1.10.7/joml-1.10.7.jar \
		${WRKSRC}/bin/libs/java/joml.jar
	${LN} -s ${DISTDIR}/maven2/org/openjdk/jmh/jmh-core/1.37/jmh-core-1.37-sources.jar \
		${WRKSRC}/bin/libs/java/jmh-core-sources.jar
	${LN} -s ${DISTDIR}/maven2/org/openjdk/jmh/jmh-core/1.37/jmh-core-1.37.jar \
		${WRKSRC}/bin/libs/java/jmh-core.jar
	${LN} -s ${DISTDIR}/maven2/org/openjdk/jmh/jmh-generator-annprocess/1.37/jmh-generator-annprocess-1.37.jar \
		${WRKSRC}/bin/libs/java/jmh-generator-annprocess.jar
	${LN} -s ${DISTDIR}/maven2/org/slf4j/slf4j-api/1.7.36/slf4j-api-1.7.36.jar \
		${WRKSRC}/bin/libs/java/slf4j-api.jar
	${LN} -s ${DISTDIR}/maven2/org/slf4j/slf4j-jdk14/1.7.36/slf4j-jdk14-1.7.36.jar \
		${WRKSRC}/bin/libs/java/slf4j-jdk14.jar
	${LN} -s ${DISTDIR}/maven2/org/testng/testng/7.5/testng-7.5-sources.jar \
		${WRKSRC}/bin/libs/java/testng-sources.jar
	${LN} -s ${DISTDIR}/maven2/org/testng/testng/7.5/testng-7.5.jar \
		${WRKSRC}/bin/libs/java/testng.jar
	${LN} -s ${DISTDIR}/maven2/org/webjars/jquery/3.5.1/jquery-3.5.1.jar \
		${WRKSRC}/bin/libs/java/jquery.jar

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/config/freebsd/build.xml \
		${WRKSRC}/modules/lwjgl/cuda/src/main/java/org/lwjgl/cuda/CUDA.java

do-install:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} release ${MAKE_ARGS}
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}${PKGNAMESUFFIX}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}
.for x in ${WRKSRC}/bin/RELEASE/lwjgl*/*.jar
	${INSTALL_DATA} ${WRKSRC}${x} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}${PKGNAMESUFFIX}/
.endfor
.for x in ${LIBSDIR}/liblwjgl.so ${LIBSDIR}/*/liblwjgl*.so
	${INSTALL_LIB} ${WRKSRC}${x} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}/
.endfor

.include <bsd.port.post.mk>
