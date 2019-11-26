# Created by: Stefan Schmidt <stefan.schmidt@stadtbuch.de>
# $FreeBSD$

PORTNAME=	isql-viewer
PORTVERSION=	2.1.8
PORTREVISION=	5
CATEGORIES=	databases java
MASTER_SITES=	SF/isql/Stand%20Alone%20Jars/Version%20${PORTVERSION}:isql \
		APACHE/ws/soap/version-2.2:bsf
DISTFILES=	${ISQL_JAR}:isql \
		${BSF_JAR}:bsf
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JDBC 2.x compliant database front end

RUN_DEPENDS=	${JYTHON_PREFIX}/${JYTHON_JAR}:lang/jython \
		${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc \
		${JAVALIBDIR}/mysql-connector-java.jar:databases/mysql-connector-java

USE_JAVA=	yes
NO_BUILD=	yes

ISQL=		iSQL-Viewer
ISQL_JAR=	${ISQL}-${PORTVERSION}.jar
DEST_ISQL_JAR=	${ISQL}.jar

BSF_JAR=	bsf.jar
DEST_BSF_JAR=	ibm-${BSF_JAR}

JYTHON_PREFIX=	${LOCALBASE}/lib/jython
JYTHON_JAR=	jython.jar

JARFILES=	${DEST_ISQL_JAR} \
		${DEST_BSF_JAR}

PLIST_FILES=	bin/iSQL-Viewer \
		${JARFILES:S,^,%%JAVAJARDIR%%/,}

JAR_DEPENDS=	mysql-connector-java.jar \
		postgresql.jar

CLASSPATH=	"${JARFILES:S,^,${JAVAJARDIR}/,}:${JYTHON_PREFIX}/${JYTHON_JAR}:${JAR_DEPENDS:S,^,${JAVALIBDIR}/,:S| |:|g}"

do-configure:
	@${SED} -e 's|%%CLASSPATH%%|${CLASSPATH:C,[[:space:]],:,g}|g'	\
		${FILESDIR}/iSQL-Viewer.sh > ${WRKDIR}/iSQL-Viewer.sh

do-install:
	${INSTALL_DATA} ${_DISTDIR}${ISQL_JAR} ${STAGEDIR}${JAVAJARDIR}/${DEST_ISQL_JAR}
	${INSTALL_DATA} ${_DISTDIR}${BSF_JAR} ${STAGEDIR}${JAVAJARDIR}/${DEST_BSF_JAR}
	${INSTALL_SCRIPT} ${WRKDIR}/iSQL-Viewer.sh ${STAGEDIR}${PREFIX}/bin/iSQL-Viewer

.include <bsd.port.mk>
