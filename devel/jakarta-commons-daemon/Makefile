# Created by: Ronald Klop <ronald@echteman.nl>
# $FreeBSD$

PORTNAME=	commons-daemon
PORTVERSION=	1.0.15
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE:S,$,:src,} \
		${MASTER_SITE_APACHE_COMMONS_BINARIES:S,$,:bin,}
MASTER_SITE_SUBDIR=	daemon/:src daemon/:bin
PKGNAMEPREFIX=	jakarta-
DISTFILES=	${PORTNAME}-${PORTVERSION}-native-src${EXTRACT_SUFX}:src \
		${PORTNAME}-${PORTVERSION}-bin${EXTRACT_SUFX}:bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Wrapper code to start/stop a Java application as a daemon

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-java=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${DISTNAME}-native-src/unix
WRKBIN=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/jsvc %%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jsvc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKBIN}/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKBIN} && ${COPYTREE_SHARE} apidocs ${DOCSDIR}
.endif

.include <bsd.port.mk>
