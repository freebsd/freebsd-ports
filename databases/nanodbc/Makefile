PORTNAME=	nanodbc
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
CATEGORIES=	databases devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small C++ wrapper for the native C ODBC API
WWW=		https://nanodbc.github.io/nanodbc/ \
		https://github.com/nanodbc/nanodbc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libodbc.so:databases/unixODBC
TEST_DEPENDS=	${LOCALBASE}/lib/libsqlite3odbc.so:databases/sqliteodbc

USES=		cmake:testing compiler:c++17-lang localbase:ldflags
USE_CXXSTD=	c++17

USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	NANODBC_BUILD_EXAMPLES \
		NANODBC_BUILD_TESTS
CMAKE_TESTING_ON=	NANODBC_BUILD_TESTS

CONFIGURE_ENV+=	CI=1 DB=sqlite
TEST_ENV+=	ODBCSYSINI=${WRKDIR}/.odbc

LDFLAGS+=	-pthread

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=deprecated-declarations -Wno-error=unused-command-line-argument
.endif

pre-test:
	@${MKDIR} ${WRKDIR}/.odbc
	@${ECHO_CMD} '[SQLite3]' > ${WRKDIR}/.odbc/odbcinst.ini
	@${ECHO_CMD} 'Description=SQLite3 ODBC Driver' >> ${WRKDIR}/.odbc/odbcinst.ini
	@${ECHO_CMD} 'Driver=${LOCALBASE}/lib/libsqlite3odbc.so' >> ${WRKDIR}/.odbc/odbcinst.ini
	@${ECHO_CMD} 'Setup=${LOCALBASE}/lib/libsqlite3odbc.so' >> ${WRKDIR}/.odbc/odbcinst.ini

# tests as of 3.0.1: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
