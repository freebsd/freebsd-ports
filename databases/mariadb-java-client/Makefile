PORTNAME=	mariadb-java-client
DISTVERSION=	3.5.5
CATEGORIES=	databases java
MASTER_SITES=	https://dlm.mariadb.com/4441309/Connectors/java/connector-java-${DISTVERSION}/ \
		https://repo1.maven.org/maven2/org/mariadb/jdbc/mariadb-java-client/${DISTVERSION}/
EXTRACT_SUFX=	.jar

MAINTAINER=	dmayoss@gmail.com
COMMENT=	MariaDB JDBC driver for Java applications
WWW=		https://mariadb.com

LICENSE=	LGPL21

USES=		cpe java
CPE_VENDOR=	mariadb
CPE_PRODUCT=	mariadb_connector/j

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar \
		${JAVAJARDIR}/${DISTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${RLN} ${STAGEDIR}${JAVAJARDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
