# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jzlib
PORTVERSION=	1.1.1
CATEGORIES=	archivers java
MASTER_SITES=	http://www.jcraft.com/jzlib/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Reimplementation of zlib in pure Java

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_ARCH=	yes

JAR_FILE=	${WRKSRC}/src/main/java/${PORTNAME}.jar

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	@cd ${WRKSRC}/src/main/java && ${FIND} com -name "*.java" | \
		${XARGS} -n 10 -x \
		${JAVAC} -classpath ${WRKSRC}/src/main/java
	@cd ${WRKSRC}/src/main/java && ${FIND} com -name "*class" | \
		${XARGS} \
		${JAR} -cf ${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${JAR_FILE} ${STAGEDIR}/${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for file in ChangeLog LICENSE.txt README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}/${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
