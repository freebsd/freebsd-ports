# New ports collection makefile for:   commons-daemon
# Date created:        9 July 2007
# Whom:                Ronald Klop <ronald@echteman.nl>
#
# $FreeBSD$
#

PORTNAME=	commons-daemon
PORTVERSION=	1.0.3
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ronald@echteman.nl
COMMENT=	Wrapper code to start/stop a Java application as a daemon

USE_JAVA=	yes
JAVA_VERSION=	1.3+
JAVA_OS=	native
JAVA_BUILD=	jdk
NEED_JAVAC=	yes
USE_JIKES=	no
USE_ANT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-java=${JAVA_HOME}

ALL_TARGET=dist

CONFIGURE_WRKSRC=	${WRKSRC}/src/native/unix/
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar bin/jsvc

.include <bsd.port.pre.mk>

post-build:
	cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all
	${MV} ${WRKSRC}/dist/${PORTNAME}-${PORTVERSION}.jar ${WRKSRC}/dist/${PORTNAME}.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/jsvc ${PREFIX}/bin

.include <bsd.port.post.mk>
