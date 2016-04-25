# Created by: Wes Peters <wes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poco
PORTVERSION=	1.7.2
DISTVERSIONSUFFIX=	-all
CATEGORIES=	devel net
MASTER_SITES=	http://pocoproject.org/releases/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ libraries with a network/internet focus

LICENSE=	BSL

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2

CONFLICTS=	poco-ssl-[0-9]*

USES=		cmake pkgconfig
CMAKE_ARGS=	-DPOCO_UNBUNDLED:BOOL=ON
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		MYSQL SQLITE SSL TEST
OPTIONS_RADIO=		ODBC
OPTIONS_RADIO_ODBC=	IODBC UNIXODBC
OPTIONS_DEFAULT=	MYSQL SQLITE SSL
OPTIONS_SUB=		yes

MYSQL_USE=		mysql=yes
MYSQL_CMAKE_OFF=	-DENABLE_DATA_MYSQL:BOOL=OFF
IODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc
IODBC_CMAKE_ON=		-DODBC_INCLUDE_DIRECTORIES:PATH=${LOCALBASE}/include/libiodbc \
			-DODBC_LIBRARIES:FILEPATH=${LOCALBASE}/lib/libiodbc.so
SQLITE_USES=		sqlite
SQLITE_CMAKE_OFF=	-DENABLE_DATA_SQLITE:BOOL=OFF
SSL_USE=		openssl=yes
SSL_CMAKE_OFF=		-DENABLE_CRYPTO:BOOL=OFF \
			-DENABLE_NETSSL:BOOL=OFF
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_CMAKE_ON=	-DODBC_INCLUDE_DIRECTORIES:PATH=${LOCALBASE}/include \
			-DODBC_LIBRARIES:FILEPATH=${LOCALBASE}/lib/libodbc.so
TEST_CMAKE_ON=		-DENABLE_TESTS:BOOL=ON
TEST_IMPLIES=		SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIODBC} || ${PORT_OPTIONS:MUNIXODBC}
PLIST_SUB+=	ODBC=""
.else
CMAKE_ARGS+=	-DENABLE_DATA_ODBC:BOOL=OFF
PLIST_SUB+=	ODBC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-D_XOPEN_SOURCE=500 || ; \
		 s|_EPOLL|_POLL| ; \
		 s|dl rt|rt|' ${WRKSRC}/cmake/DefinePlatformSpecifc.cmake

.include <bsd.port.mk>
