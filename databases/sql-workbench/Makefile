PORTNAME=	sql-workbench
DISTVERSION=	133
PORTEPOCH=	2
CATEGORIES=	databases java
MASTER_SITES=	https://www.sql-workbench.eu/ \
		https://www.sql-workbench.eu/archive/
DISTNAME=	Workbench-Build${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DBMS-independent, cross-platform SQL query tool
WWW=		https://www.sql-workbench.eu/

LICENSE=	APACHE20

USES=		java zip
JAVA_VERSION=	21+

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS MYSQL PGSQL
MYSQL_DESC=		Install MySQL JDBC driver
PGSQL_DESC=		Install PostgreSQL JDBC driver
MYSQL_RUN_DEPENDS=	${JAVALIBDIR}/mysql-connector-j.jar:databases/mysql-connector-j
PGSQL_RUN_DEPENDS=	${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKSRC}/new_sqlworkbench.sh
	@${ECHO} "${LOCALBASE}/bin/java -Dvisualvm.display.name=SQLWorkbench -Xmx512m -jar ${JAVAJARDIR}/sqlworkbench.jar" \
		>> ${WRKSRC}/new_sqlworkbench.sh

do-install:
	(cd ${WRKSRC}/xslt && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/xslt)
	${INSTALL_DATA} ${WRKSRC}/sqlworkbench.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/workbench32.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_SCRIPT} ${WRKSRC}/new_sqlworkbench.sh ${STAGEDIR}${PREFIX}/bin/sqlworkbench

do-install-DOCS-on:
	(cd ${WRKSRC}/manual && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
