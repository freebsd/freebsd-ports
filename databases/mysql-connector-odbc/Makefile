PORTNAME=	mysql-connector-odbc
PORTVERSION=	5.3.13
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-ODBC/5.3
PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ODBC driver for MySQL${MYSQL_VER} / ${DRIVER_MANAGER}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libodbc.so:databases/unixODBC

USES=		cmake compiler:c++11-lang mysql

CMAKE_ARGS=	-DWITH_UNIXODBC=1 -DDISABLE_GUI=1
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=yes

LDFLAGS+=	-L${LOCALBASE}/lib

DRIVER_MANAGER=	unixodbc

PORTDOCS=	*

PLIST_FILES=	bin/myodbc-installer \
		lib/libmyodbc5a.so \
		lib/libmyodbc5w.so

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
