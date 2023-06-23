PORTNAME=	commons-daemon
PORTVERSION=	1.3.2
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/commons/daemon/source/:src \
		https://archive.apache.org/dist/commons/daemon/binaries/:bin
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${PORTVERSION}-native-src${EXTRACT_SUFX}:src \
		${PORTNAME}-${PORTVERSION}-bin${EXTRACT_SUFX}:bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Wrapper code to start/stop a Java application as a daemon
WWW=		https://commons.apache.org/proper/commons-daemon/

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
JAVA_OS=	native
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-java=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${DISTNAME}-native-src/unix
WRKBIN=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/jsvc %%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jsvc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKBIN}/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKBIN} && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
