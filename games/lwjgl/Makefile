# New ports collection makefile for:   jinput
# Date created:                        Mar 25 2012
# Whom:                                loader <loader@freebsdmall.com>
#
# $FreeBSD$
#

PORTNAME=	lwjgl
DISTVERSION=	2.7.1
CATEGORIES=	games java
MASTER_SITES=	SF/java-game-lib/Official%20Releases/${PORTNAME:U}%20${PORTVERSION}/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	loader@freebsdmall.com
COMMENT=	The Lightweight Java Game Library

BUILD_DEPENDS=	${JAVALIBDIR}/jutils/jutils.jar:${PORTSDIR}/games/jutils \
		${JAVALIBDIR}/jinput/jinput.jar:${PORTSDIR}/games/jinput \
		${LOCALBASE}/include/X11/extensions/xf86vmode.h:${PORTSDIR}/x11/libXxf86vm \
		${LOCALBASE}/include/X11/extensions/Xrandr.h:${PORTSDIR}/x11/libXrandr \
		${LOCALBASE}/include/X11/Xcursor/Xcursor.h:${PORTSDIR}/x11/libXcursor
RUN_DEPENDS=	${JAVALIBDIR}/jutils/jutils.jar:${PORTSDIR}/games/jutils \
		${JAVALIBDIR}/jinput/jinput.jar:${PORTSDIR}/games/jinput \
		${LOCALBASE}/include/X11/extensions/xf86vmode.h:${PORTSDIR}/x11/libXxf86vm \
		${LOCALBASE}/include/X11/extensions/Xrandr.h:${PORTSDIR}/x11/libXrandr \
		${LOCALBASE}/include/X11/Xcursor/Xcursor.h:${PORTSDIR}/x11/libXcursor

ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USE_ZIP=	yes
USE_JAVA=	yes
USE_LDCONFIG=	yes
USE_DOS2UNIX=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_VENDOR=	openjdk
USE_ANT=	yes
MAKE_ENV+=	CLASSPATH=${JAVALIBDIR}/jutils/jutils.jar:${JAVALIBDIR}/jinput/jinput.jar
ALL_TARGET=	jars compile_native

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}.jar \
		%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}_test.jar \
		%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}_util.jar \
		%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}_util_applet.jar
PLIST_DIRS=	%%JAVAJARDIR%%/${PORTNAME} \
		lib/${PORTNAME}${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_FILES+=	lib/${PORTNAME}${PORTVERSION}/lib${PORTNAME}.so
.endif

.if ${ARCH} == "amd64"
PLIST_FILES+=	lib/${PORTNAME}${PORTVERSION}/lib${PORTNAME}64.so
.endif

do-install:
	@${ECHO_MSG} -n ">> Install JAR files in ${JAVAJARDIR}/${PORTNAME}/ ..."
	@${MKDIR} ${JAVAJARDIR}/${PORTNAME}
.for _jar in ${PLIST_FILES:M*.jar}
	@${INSTALL_DATA} ${WRKSRC}/libs/${_jar:T} ${JAVAJARDIR}/${PORTNAME}
.endfor
	@${ECHO_MSG} " [ DONE ]"
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.if ${ARCH} == "i386"
	@${INSTALL_DATA} ${WRKSRC}/libs/linux/lib${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.endif
.if ${ARCH} == "amd64"
	@${INSTALL_DATA} ${WRKSRC}/libs/linux/lib${PORTNAME}64.so ${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.endif

.include <bsd.port.post.mk>
