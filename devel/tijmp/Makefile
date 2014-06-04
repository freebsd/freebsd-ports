# Created by: Ronald Klop <ronald@echteman.nl>
# $FreeBSD$

PORTNAME=	tijmp
PORTVERSION=	0.7
CATEGORIES=	devel java
MASTER_SITES=	http://www.khelekore.org/jmp/tijmp/ \
		http://www.klop.ws/~ronald/software-mirrors/

MAINTAINER=	ronald-lists@klop.ws
COMMENT=	Tools Interface Java Memory Profiler

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

USES=		gmake
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_BUILD=	jdk
NEED_JAVAC=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
USE_LDCONFIG=	yes

PLIST_FILES=	lib/lib${PORTNAME}.la \
		lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 \
		%%JAVAJARDIR%%/${PORTNAME}.jar

OPTIMIZED_CFLAGS_CFLAGS=	-O3

post-extract::
	@${SED} -i "" -e 's|/../share/java|${JAVAJARDIR}|' ${WRKSRC}/src/tijmp.c

do-install::
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_DATA} ${WRKSRC}/src/.libs/lib${PORTNAME}.la ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/lib${PORTNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/
	${LN} -sf lib${PORTNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
