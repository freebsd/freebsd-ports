# New ports collection makefile for:	tijmp
# Date created:				8 October 2007
# Whom:					Ronald Klop <ronald@echteman.nl>
#
# $FreeBSD$
#

PORTNAME=	tijmp
PORTVERSION=	0.4
CATEGORIES=	devel java
MASTER_SITES=	http://www.khelekore.org/jmp/tijmp/ \
		http://www.klop.ws/~ronald/software-mirrors/

MAINTAINER=	ronald@echteman.nl
COMMENT=	Tools Interface Java Memory Profiler

OPTIONS=	OPTIMIZED_CFLAGS "Compile with -O3" off

USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_BUILD=	jdk
NEED_JAVAC=	yes
USE_JIKES=	no

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
USE_LDCONFIG=	yes

PLIST_FILES=	lib/lib${PORTNAME}.la \
		lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 \
		%%JAVAJARDIR%%/${PORTNAME}.jar

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS?=	-O3
.endif

post-extract::
	@${SED} -i "" -e 's|share/java|${JAVAJARDIR:S,^${PREFIX}/,,}|' ${WRKSRC}/src/tijmp.c

do-install::
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_DATA} ${WRKSRC}/src/.libs/lib${PORTNAME}.la ${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/lib${PORTNAME}.so.0 ${PREFIX}/lib/
	cd ${PREFIX}/lib && ${LN} -sf lib${PORTNAME}.so.0 lib${PORTNAME}.so

.include <bsd.port.post.mk>
