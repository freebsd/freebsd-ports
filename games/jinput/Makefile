# Created by: loader <loader@freebsdmall.com>
# $FreeBSD$

PORTNAME=	jinput
DISTVERSION=	20110801.r247
CATEGORIES=	games java
MASTER_SITES=	LOCAL/loader

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Game Controller API

BUILD_DEPENDS=	${JAVALIBDIR}/jutils/jutils.jar:games/jutils
RUN_DEPENDS=	${JAVALIBDIR}/jutils/jutils.jar:games/jutils

BROKEN_armv6=		fails to compile: build.xml: compilation failed
BROKEN_armv7=		fails to compile: build.xml: compilation failed

USES=		tar:bzip2
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_VENDOR=	openjdk
USE_ANT=	yes
ALL_TARGET=	simple_linux
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}.jar

post-patch:
	@${LN} -sf ${JAVALIBDIR}/jutils/jutils.jar ${WRKSRC}/lib/

do-build:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${ALL_TARGET})

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/

.include <bsd.port.mk>
