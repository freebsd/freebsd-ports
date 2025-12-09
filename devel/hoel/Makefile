PORTNAME=	hoel
PORTVERSION=	1.4.29
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database abstraction library written in C
WWW=		https://babelouest.github.io/hoel/ \
		https://github.com/babelouest/hoel

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

BUILD_DEPENDS=	jansson>=2.4:devel/jansson \
		orcania>=2.3.2:devel/orcania \
		yder>=1.4.19:devel/yder
LIB_DEPENDS=	libjansson.so:devel/jansson \
		liborcania.so:devel/orcania \
		libyder.so:devel/yder

CMAKE_OFF=	BUILD_DEB \
		BUILD_HOEL_DOCUMENTATION \
		BUILD_HOEL_TESTING \
		BUILD_RPM \
		BUILD_TGZ
CMAKE_ON=	BUILD_STATIC \
		INSTALL_HEADER \
		SEARCH_ORCANIA_H \
		SEARCH_YDER

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MARIADB PGSQL SQLITE3
OPTIONS_DEFAULT=PGSQL
PGSQL_DESC=	Use PostgreSQL as backend
SQLITE3_DESC=	Use SQLite 3 as backend
MARIADB_DESC=	Use MariaDB as backend

MARIADB_CMAKE_BOOL=	WITH_MARIADB
MARIADB_USES=		mysql
PGSQL_CMAKE_BOOL=	WITH_PGSQL
PGSQL_USES=		pgsql
SQLITE3_CMAKE_BOOL=	WITH_SQLITE3
SQLITE3_USES=		sqlite

.include <bsd.port.mk>
