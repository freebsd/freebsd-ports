PORTNAME=	lwjgl
DISTVERSION=	2.9.4.20161208
PORTREVISION=	3
CATEGORIES=	games java

MAINTAINER=	freebsd@skinc.ru
COMMENT=	Lightweight Java Game Library
WWW=		https://legacy.lwjgl.org

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	${JAVAJARDIR}/jutils/jutils.jar:games/jutils \
		${JAVAJARDIR}/jinput/jinput.jar:games/jinput
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		dos2unix java:ant,run xorg
DOS2UNIX_REGEX=	.*.[^jp][^an][^rg]$
JAVA_VERSION=	8
USE_GITHUB=	yes
GH_ACCOUNT=	LWJGL
GH_TAGNAME=	2df01dd

USE_LDCONFIG=	yes
USE_XORG=	x11 xcursor xext xrandr xxf86vm
MAKE_ENV+=	CLASSPATH=${JAVAJARDIR}/jutils/jutils.jar:${JAVAJARDIR}/jinput/jinput.jar:${WRKSRC}/${DISTNAME}/jar/
ALL_TARGET=	jars compile_native

NO_SHLIB_REQUIRES_GLOB=	libjawt.so

PLIST_DIRS=	${JAVAJARDIR}/${PORTNAME} \
		lib/${PORTNAME}
PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}/${PORTNAME}.jar \
		${JAVAJARDIR}/${PORTNAME}/${PORTNAME}_test.jar \
		${JAVAJARDIR}/${PORTNAME}/${PORTNAME}_util.jar \
		${JAVAJARDIR}/${PORTNAME}/${PORTNAME}_util_applet.jar

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc
PLIST_FILES+=	lib/${PORTNAME}/lib${PORTNAME}.so
.endif

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
PLIST_FILES+=	lib/${PORTNAME}/lib${PORTNAME}64.so
.endif

.if ${ARCH} == aarch64 || ${ARCH:Mpowerpc64*}
MAKE_ARGS+=	-Dbuild.64bit.only=1
.endif

.if ${ARCH} == powerpc
LLD_UNSAFE=	yes
MAKE_ARGS+=	-Dbuild.32bit.only=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|g' \
		-e '/executable/s/cc/${CC}/g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml
.if ${ARCH} == powerpc64
	@${REINPLACE_CMD} -e 's|amd64|ppc64|g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml
.elif ${ARCH} == powerpc64le
	@${REINPLACE_CMD} -e 's|amd64|ppc64le|g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml
.elif ${ARCH} == aarch64
	@${REINPLACE_CMD} -e 's|amd64|aarch64|g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml
.elif ${ARCH} == powerpc
	@${REINPLACE_CMD} -e 's|i386|ppc|g' \
		-e '/linker_flags32/s/-shared/-shared -fuse-ld=bfd/g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
.for _jar in ${PLIST_FILES:M*.jar}
	${INSTALL_DATA} ${WRKSRC}/libs/${_jar:T} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.if ${ARCH} == i386 || ${ARCH} == powerpc
	${INSTALL_DATA} ${WRKSRC}/libs/freebsd/lib${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.endif
.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
	${INSTALL_DATA} ${WRKSRC}/libs/freebsd/lib${PORTNAME}64.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.endif

.include <bsd.port.post.mk>
