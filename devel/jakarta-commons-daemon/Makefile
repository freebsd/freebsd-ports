# Created by: Ronald Klop <ronald@echteman.nl>
# $FreeBSD$

PORTNAME=	commons-daemon
PORTVERSION=	1.1.0
CATEGORIES=	devel java
MASTER_SITES=	APACHE_COMMONS_SOURCE:src \
		APACHE_COMMONS_BINARIES:bin
PKGNAMEPREFIX=	jakarta-
DISTFILES=	${PORTNAME}-${PORTVERSION}-native-src${EXTRACT_SUFX}:src \
		${PORTNAME}-${PORTVERSION}-bin${EXTRACT_SUFX}:bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Wrapper code to start/stop a Java application as a daemon

LICENSE=	APACHE20

BROKEN_aarch64=		fails to compile: 'jni_md.h' file not found
BROKEN_armv6=		fails to compile: 'jni_md.h' file not found
BROKEN_armv7=		fails to compile: 'jni_md.h' file not found

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-java=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${DISTNAME}-native-src/unix
WRKBIN=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/jsvc %%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jsvc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKBIN}/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKBIN} && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
