# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	poco
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSIONSUFFIX=	-release
CATEGORIES=	devel net
PKGNAMESUFFIX=	-devel

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	C++ Portable Components library

LICENSE=	BSL

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2

CONFLICTS=	poco-ssl-[0-9]* poco-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	pocoproject

OPTIONS_DEFAULT=	MYSQL IODBC SQLITE

OPTIONS_DEFINE=	MYSQL SQLITE
SAMPLES_DESC=	Build sample programs
UODBC_DESC=	Build with ODBC driver
IODBC_DESC=	Build with iODBC driver

OPTIONS_RADIO=	ODBC
OPTIONS_RADIO_ODBC=	UODBC IODBC
ODBC_DESC=	ODBC Driver

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--config=FreeBSD --unbundled --no-tests --no-samples
USES=		gmake
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
MAKE_JOBS_UNSAFE=true

MAKE_ARGS=	CXX=c++ CC=cc POCO_ODBC_LIB=${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MUODBC} && ! ${PORT_OPTIONS:MIODBC}
CONFIGURE_ARGS+=	--omit=Data/ODBC
.endif

.if ${PORT_OPTIONS:MUODBC} && ! ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	libodbcinst.so:databases/unixODBC
.endif

.if ${PORT_OPTIONS:MIODBC} && ! ${PORT_OPTIONS:MUODBC}
LIB_DEPENDS+=	libiodbc.so:databases/libiodbc
CFLAGS+=	-I${LOCALBASE}/include/libiodbc
LDFLAGS+=	-L${LOCALBASE}/lib/libiodbc
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--omit=Data/MySQL
.endif

.if ${PORT_OPTIONS:MSQLITE}
USES+=		sqlite
.else
CONFIGURE_ARGS+=	--omit=Data/SQLite
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/ =/ ?=/g" ${WRKSRC}/build/config/FreeBSD

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cpspcd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/f2cpspd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/f2cpspd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*d.so.*

.include <bsd.port.mk>
