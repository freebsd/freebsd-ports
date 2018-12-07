# Created by: loader <loader@freebsdmall.com>
# $FreeBSD$

PORTNAME=	lwjgl
DISTVERSION=	2.9.3
CATEGORIES=	games java
MASTER_SITES=	SF/java-game-lib/Official%20Releases/${PORTNAME:tu}%20${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-source-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	freebsd@skinc.ru
COMMENT=	Lightweight Java Game Library

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64

BUILD_DEPENDS=	${JAVALIBDIR}/jutils/jutils.jar:games/jutils \
		${JAVALIBDIR}/jinput/jinput.jar:games/jinput
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		dos2unix zip
DOS2UNIX_REGEX= .*.[^jp][^an][^rg]$
USE_JAVA=	yes
USE_LDCONFIG=	yes
JAVA_VERSION=	1.7+
JAVA_OS=	native
JAVA_VENDOR=	openjdk
USE_ANT=	yes
USE_XORG=	xcursor xrandr xxf86vm
MAKE_ENV+=	CLASSPATH=${JAVALIBDIR}/jutils/jutils.jar:${JAVALIBDIR}/jinput/jinput.jar:${WRKSRC}/${DISTNAME}/jar/
ALL_TARGET=	jars compile_native

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}.jar \
		%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}_test.jar \
		%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}_util.jar \
		%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}_util_applet.jar
PLIST_DIRS=	%%JAVAJARDIR%%/${PORTNAME} \
		lib/${PORTNAME}${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLIST_FILES+=	lib/${PORTNAME}${PORTVERSION}/lib${PORTNAME}.so
.endif

.if ${ARCH} == amd64 || ${ARCH} == powerpc64
PLIST_FILES+=	lib/${PORTNAME}${PORTVERSION}/lib${PORTNAME}64.so
.endif

.if ${ARCH} == powerpc64
MAKE_ARGS+=	-Dbuild.64bit.only=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|g' \
		-e '/executable/s/cc/${CC}/g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml
.if ${ARCH} == powerpc64
	@${REINPLACE_CMD} -e 's|amd64|ppc64|g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
.for _jar in ${PLIST_FILES:M*.jar}
	${INSTALL_DATA} ${WRKSRC}/libs/${_jar:T} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.if ${ARCH} == i386
	${INSTALL_DATA} ${WRKSRC}/libs/freebsd/lib${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.endif
.if ${ARCH} == amd64 || ${ARCH} == powerpc64
	${INSTALL_DATA} ${WRKSRC}/libs/freebsd/lib${PORTNAME}64.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.endif

.include <bsd.port.post.mk>
