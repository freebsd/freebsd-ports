PORTNAME=	mysql-connector-odbc
PORTVERSION=	5.3.14
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-ODBC/5.3
PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ODBC driver for MySQL${MYSQL_VER} / ${DRIVER_MANAGER}
WWW=		https://www.mysql.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Requires EOLd mysql version
EXPIRATION_DATE=	2023-12-31

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		cmake compiler:c++11-lang localbase:ldflags mysql ssl
IGNORE_WITH_MYSQL=	101m 102m 103m 57p 57w 80
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DDISABLE_GUI=1 \
		-DWITH_UNIXODBC=1

MAKE_JOBS_UNSAFE=	yes

DRIVER_MANAGER=	unixodbc

PLIST_FILES=	bin/myodbc-installer \
		lib/libmyodbc5a.so \
		lib/libmyodbc5w.so
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
