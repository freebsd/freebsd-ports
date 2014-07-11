# Created by: Joseph Benden <joe@thrallingpenguin.com>
# $FreeBSD$

PORTNAME=	poco
PORTVERSION=	1.5.3
CATEGORIES=	devel net
MASTER_SITES=	https://codeload.github.com/pocoproject/poco/legacy.tar.gz/poco-${PORTVERSION}-release?dummy=/
PKGNAMESUFFIX=	-devel

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	C++ Portable Components library

LICENSE=	BSL

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

CONFLICTS=	poco-ssl-[0-9]* poco-[0-9]*

OPTIONS_DEFAULT=	MYSQL IODBC SQLITE

OPTIONS_DEFINE=	MYSQL SQLITE
SAMPLES_DESC=	Build sample programs
UODBC_DESC=	Build with ODBC driver
IODBC_DESC=	Build with iODBC driver

OPTIONS_RADIO=	ODBC
OPTIONS_RADIO_ODBC=	UODBC IODBC
ODBC_DESC=	ODBC Driver

CONFIGURE_ARGS=	--config=FreeBSD --unbundled
USES=		gmake
MAKE_JOBS_UNSAFE=true

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre \
		libexpat.so:${PORTSDIR}/textproc/expat2
WRKSRC=		${WRKDIR}/pocoproject-poco-23760af
MAKE_ARGS=	CXX=c++ CC=cc POCO_ODBC_LIB=${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MUODBC} && ! ${PORT_OPTIONS:MIODBC}
CONFIGURE_ARGS+=	--omit=Data/ODBC
.endif

.if ${PORT_OPTIONS:MUODBC} && ! ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	libodbcinst.so:${PORTSDIR}/databases/unixODBC
.endif

.if ${PORT_OPTIONS:MIODBC} && ! ${PORT_OPTIONS:MUODBC}
LIB_DEPENDS+=	libiodbc.so:${PORTSDIR}/databases/libiodbc
CFLAGS+=	-I${LOCALBASE}/include/libiodbc
LDFLAGS+=	-L${LOCALBASE}/lib/libiodbc
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--omit=Data/MySQL
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+=	--omit=Data/SQLite
.endif

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/ =/ ?=/g" ${WRKSRC}/build/config/FreeBSD

.include <bsd.port.mk>
