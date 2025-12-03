PORTNAME=	commons-daemon
DISTVERSION=	1.5.0
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/commons/daemon/source/:src \
		https://archive.apache.org/dist/commons/daemon/binaries/:bin
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${DISTVERSION}-native-src${EXTRACT_SUFX}:src \
		${PORTNAME}-${DISTVERSION}-bin${EXTRACT_SUFX}:bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Wrapper code to start/stop a Java application as a daemon
WWW=		https://commons.apache.org/proper/commons-daemon/

LICENSE=	APACHE20

USES=		java
JAVA_OS=	native

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-java=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${DISTNAME}-native-src/unix
WRKBIN=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/jsvc ${JAVAJARDIR}/${PORTNAME}.jar

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jsvc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKBIN}/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKBIN}/${PORTNAME}-${DISTVERSION}-javadoc.jar \
			${STAGEDIR}${DOCSDIR}/${PORTNAME}-javadoc.jar

.include <bsd.port.mk>
