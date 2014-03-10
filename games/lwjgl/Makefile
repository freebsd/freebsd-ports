# Created by: loader <loader@freebsdmall.com>
# $FreeBSD$

PORTNAME=	lwjgl
DISTVERSION=	2.9.0
CATEGORIES=	games java
MASTER_SITES=	SF/java-game-lib/Official%20Releases/${PORTNAME:U}%20${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-source-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight Java Game Library

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/${DISTNAME}/doc/LICENSE

BUILD_DEPENDS=	${JAVALIBDIR}/jutils/jutils.jar:${PORTSDIR}/games/jutils \
		${JAVALIBDIR}/jinput/jinput.jar:${PORTSDIR}/games/jinput
RUN_DEPENDS:=	${BUILD_DEPENDS}

ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		dos2unix zip:infozip
USE_JAVA=	yes
USE_LDCONFIG=	yes
DOS2UNIX_REGEX=	.*.[^j][^a][^r]$
JAVA_VERSION=	1.6+
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

.if ${ARCH} == amd64
PLIST_FILES+=	lib/${PORTNAME}${PORTVERSION}/lib${PORTNAME}64.so
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,PREFIX,${PREFIX},g' \
		-e '/executable/s/gcc/${CC}/g' \
		${WRKSRC}/platform_build/bsd_ant/build.xml

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
.for _jar in ${PLIST_FILES:M*.jar}
	${INSTALL_DATA} ${WRKSRC}/libs/${_jar:T} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.if ${ARCH} == i386
	${INSTALL_DATA} ${WRKSRC}/libs/freebsd/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.endif
.if ${ARCH} == amd64
	${INSTALL_DATA} ${WRKSRC}/libs/freebsd/lib${PORTNAME}64.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PORTVERSION}
.endif

.include <bsd.port.post.mk>
