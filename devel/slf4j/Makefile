PORTNAME=	slf4j
DISTVERSION=	1.7.36
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/org/:source1
JARFILES=	integration jcl-over-slf4j jul-to-slf4j log4j-over-slf4j \
		osgi-over-slf4j slf4j-android slf4j-api slf4j-ext slf4j-jcl \
		slf4j-jdk14 slf4j-migrator slf4j-nop slf4j-reload4j slf4j-simple
DISTFILES=	${JARFILES:C|(.+)|slf4j/\1/${DISTVERSION}/\1-${DISTVERSION}.jar:source1|}
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple facade or abstraction for various logging frameworks
WWW=		https://www.slf4j.org/

LICENSE=	MIT

USES=		cpe java
CPE_VENDOR=	qos

NO_ARCH=	yes
NO_BUILD=	yes

JAVAJARDIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_FILES=	${JAVALIBDIR}/slf4j-api.jar \
		${JARFILES:C|(.+)|${JAVAJARDIR}/\1.jar|}

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
.for jarfile in ${JARFILES}
	${INSTALL_DATA} \
		${DISTDIR}/${jarfile:C|(.+)|slf4j/\1/${DISTVERSION}/\1-${DISTVERSION}.jar|} \
		${STAGEDIR}${JAVAJARDIR}/${jarfile}.jar
.endfor
	${RLN} ${STAGEDIR}${JAVAJARDIR}/slf4j-api.jar \
		${STAGEDIR}${JAVALIBDIR}/slf4j-api.jar

.include <bsd.port.mk>
