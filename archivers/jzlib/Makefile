# New ports collection makefile for:	jzlib
# Date created:		Fri Dec 31 14:28:16 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jzlib
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	archivers java
MASTER_SITES=	http://www.jcraft.com/jzlib/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A re-implementation of zlib in pure Java

USE_JAVA=	yes
JAVA_VERSION=	1.4+

JAR_FILE=	${WRKSRC}/${PORTNAME}.jar

DOC_FILES=	\
		ChangeLog \
		LICENSE.txt \
		README
PORTDOCS=	${DOC_FILES}

EXAMPLE_FILES=	\
		README \
		test_deflate_inflate.java \
		test_dict_deflate_inflate.java \
		test_flush_sync.java \
		test_large_deflate_inflate.java \
		test_stream_deflate_inflate.java

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

.for file in ${EXAMPLE_FILES}
PLIST_FILES+=	%%EXAMPLESDIR%%/${file}
.endfor

PLIST_DIRS+=	\
		%%EXAMPLESDIR%%

do-build:
	@cd ${BUILD_WRKSRC} && ${FIND} com -name "*.java" | \
		${XARGS} -n 10 -x \
		${JAVAC} -classpath ${BUILD_WRKSRC}
	@cd ${BUILD_WRKSRC} && ${FIND} com -name "*class" | \
		${XARGS} \
		${JAR} -cf ${PORTNAME}.jar

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif
# examples
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example/* ${EXAMPLESDIR}
# jar
	@${INSTALL_DATA} ${JAR_FILE} ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
