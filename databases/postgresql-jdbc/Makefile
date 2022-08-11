PORTNAME=	postgresql
PORTVERSION=	42.4.0
CATEGORIES=	databases java
MASTER_SITES=	http://jdbc.postgresql.org/download/
PKGNAMESUFFIX=	-jdbc
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	Java JDBC implementation for PostgreSQL

LICENSE=	BSD3CLAUSE

USE_JAVA=	yes
JAVA_VERSION=	8+
NO_ARCH=	yes
PLIST_FILES=	%%JAVAJARDIR%%/postgresql.jar

do-extract:

do-build:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}/postgresql.jar

.include <bsd.port.mk>
