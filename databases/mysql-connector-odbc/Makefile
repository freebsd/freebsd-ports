# Created by: sergey@migsoft.com.ua
# $FreeBSD$

PORTNAME=	mysql-connector-odbc
PORTVERSION=	5.3.4
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-ODBC/5.3
PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ODBC driver for MySQL${MYSQL_VER} / ${DRIVER_MANAGER}

BUILD_DEPENDS=	unixODBC>=2.2.14_1:databases/unixODBC
LIB_DEPENDS=	libodbc.so:databases/unixODBC

USE_LDCONFIG=	yes
USE_MYSQL=	yes
USES=		cmake

IGNORE_WITH_MYSQL=	55 55m 55p 51 51m 51p

CMAKE_ARGS=	-DWITH_UNIXODBC=1
LDFLAGS+=	-L${LOCALBASE}/lib

DRIVER_MANAGER=	unixodbc

PORTDOCS=	ChangeLog INSTALL \
		README README.debug COPYING Licenses_for_Third-Party_Components.txt

PLIST_FILES=	bin/myodbc-installer \
		lib/libmyodbc5a.so \
		lib/libmyodbc5w.so

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
