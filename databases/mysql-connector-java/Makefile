# Created by: Matthew Seaman

PORTNAME=	mysql-connector-java
PORTVERSION=	8.0.25
CATEGORIES=	databases java
MASTER_SITES=	MYSQL/Connector-J

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	MySQL Connector/J: JDBC interface for MySQL

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${JAVALIBDIR}/slf4j-api.jar:devel/slf4j \
		${JAVALIBDIR}/c3p0.jar:databases/c3p0 \
		${JAVALIBDIR}/protobuf-java.jar:devel/protobuf-java

USES=		cpe
USE_JAVA=	yes

CPE_VENDOR=	oracle
CPE_PRODUCT=	mysql_connector_j

NO_ARCH=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	mysql-connector-java51-*

JAVA_VERSION=	1.8+
EXTRADOCS=	CHANGES

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@for extradoc in ${EXTRADOCS} ; do \
	  ${INSTALL_DATA} ${INSTALL_WRKSRC}/$$extradoc ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.mk>
