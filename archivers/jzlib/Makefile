PORTNAME=	jzlib
PORTVERSION=	1.1.1
CATEGORIES=	archivers java
MASTER_SITES=	http://www.jcraft.com/jzlib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reimplementation of zlib in pure Java
WWW=		http://www.jcraft.com/jzlib/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Abandonware, untouched for over 10 years and Java Platform 8+ provides a Deflater class
EXPIRATION_DATE=2023-11-30

USES=		cpe zip
USE_JAVA=	yes
NO_ARCH=	yes
CPE_VENDOR=	jcraft

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
