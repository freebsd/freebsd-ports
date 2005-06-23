# New ports collection makefile for:	iSQL-Viewer
# Date created:		June 19, 2005
# Whom:			Stefan Schmidt <stefan.schmidt@stadtbuch.de>
#
# $FreeBSD$
#

PORTNAME=	isql-viewer
PORTVERSION=	2.1.8
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:isql/} \
		${MASTER_SITE_APACHE:S/$/:bsf/}
MASTER_SITE_SUBDIR=	isql/:isql \
			ws/soap/version-2.2/:bsf
DISTFILES=	${ISQL_JAR}:isql \
		${BSF_JAR}:bsf
EXTRACT_ONLY=	# none

MAINTAINER=	stefan.schmidt@stadtbuch.de
COMMENT=	JDBC 2.x compliant database front end

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper \
		${JYTHON_PREFIX}/${JYTHON_JAR}:${PORTSDIR}/lang/jython \
		${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc \
		${JAVALIBDIR}/mysql-connector-java.jar:${PORTSDIR}/databases/mysql-connector-java

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

ISQL=		iSQL-Viewer
ISQL_JAR=	${ISQL}-${PORTVERSION}.jar
DEST_ISQL_JAR=	${ISQL}.jar

BSF_JAR=	bsf.jar
DEST_BSF_JAR=	ibm-${BSF_JAR}

JYTHON_PORT=	${PORTSDIR}/lang/jython
JYTHON_PREFIX=	${LOCALBASE}/jython21
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
		-e 's|%%JAVA_VERSION%%|${JAVA_VERSION}|g'	\
		${FILESDIR}/iSQL-Viewer.sh > ${WRKDIR}/iSQL-Viewer.sh

do-install:
	@${INSTALL_DATA} ${_DISTDIR}${ISQL_JAR} ${JAVAJARDIR}/${DEST_ISQL_JAR}
	@${INSTALL_DATA} ${_DISTDIR}${BSF_JAR} ${JAVAJARDIR}/${DEST_BSF_JAR}
	@${INSTALL_SCRIPT} ${WRKDIR}/iSQL-Viewer.sh ${PREFIX}/bin/iSQL-Viewer

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
