PORTNAME=	mysql-connector-odbc
PORTVERSION=	8.0.32
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-ODBC/8.0
PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ODBC driver for MySQL${MYSQL_VER} / ${DRIVER_MANAGER}
WWW=		https://www.mysql.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libodbc.so:databases/unixODBC \
	libunwind.so:devel/libunwind \
	libzstd.so:archivers/zstd

USES=		cmake compiler:c++11-lang localbase:ldflags mysql:80 ssl
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DWITH_UNIXODBC=1 -DDISABLE_GUI=1

DRIVER_MANAGER=	unixodbc

PLIST_FILES=	bin/myodbc-installer \
		lib/libmyodbc8a.so \
		lib/libmyodbc8w.so \
		test/dltest
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/INFO_BIN
	@${RM} ${STAGEDIR}${PREFIX}/INFO_SRC

.include <bsd.port.mk>
