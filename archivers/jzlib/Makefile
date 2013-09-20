# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jzlib
PORTVERSION=	1.1.1
CATEGORIES=	archivers java
MASTER_SITES=	http://www.jcraft.com/jzlib/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Reimplementation of zlib in pure Java

NO_STAGE=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

JAR_FILE=	${WRKSRC}/src/main/java/${PORTNAME}.jar

DOC_FILES=	\
		ChangeLog \
		LICENSE.txt \
		README
PORTDOCS=	${DOC_FILES}

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLE_FILES=	\
		README \
		test_deflate_inflate.java \
		test_dict_deflate_inflate.java \
		test_flush_sync.java \
		test_gzip_deflate_inflate.java \
		test_gzip_inflate.java \
		test_large_deflate_inflate.java \
		test_stream_deflate_inflate.java

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
. for file in ${EXAMPLE_FILES}
PLIST_FILES+=	%%EXAMPLESDIR%%/${file}
. endfor
PLIST_DIRS+=	%%EXAMPLESDIR%%
.endif

do-build:
	@cd ${WRKSRC}/src/main/java && ${FIND} com -name "*.java" | \
		${XARGS} -n 10 -x \
		${JAVAC} -classpath ${WRKSRC}/src/main/java
	@cd ${WRKSRC}/src/main/java && ${FIND} com -name "*class" | \
		${XARGS} \
		${JAR} -cf ${PORTNAME}.jar

do-install:
# docs
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif
# examples
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${EXAMPLESDIR}
.endif
# jar
	${INSTALL_DATA} ${JAR_FILE} ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
