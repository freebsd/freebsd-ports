PORTNAME=	mysql-connector-odbc
DISTVERSION=	9.4.0
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-ODBC/9.0
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ODBC driver for MySQL
WWW=		https://www.mysql.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libunwind.so:devel/libunwind \
	libzstd.so:archivers/zstd
.if ${FLAVOR:U} == unixodbc
LIB_DEPENDS+=	libodbc.so:databases/unixODBC
.elif ${FLAVOR:U} == iodbc
LIB_DEPENDS+=	libiodbc.so:databases/libiodbc
.endif

FLAVORS=	unixodbc iodbc
FLAVOR?=	${FLAVORS:[1]}
iodbc_PKGNAMESUFFIX=		-iodbc
unixodbc_PKGNAMESUFFIX=		-unixodbc

USES=		cmake localbase:ldflags mysql ssl
USE_GCC=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=		-DINSTALL_DOCDIR=${DOCSDIR} \
				-DINSTALL_TESTDIR=${DATADIR}/test
CMAKE_ON=		DISABLE_GUI
.if ${FLAVOR:U} == unixodbc
CMAKE_ON+=		WITH_UNIXODBC
.elif ${FLAVOR:U} == iodbc
CMAKE_OFF+=		WITH_UNIXODBC
CMAKE_ARGS+=		-DODBC_INCLUDES=${PREFIX}/include/libiodbc
.endif

LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/INFO_BIN
	@${RM} ${STAGEDIR}${DOCSDIR}/INFO_SRC

.include <bsd.port.mk>
