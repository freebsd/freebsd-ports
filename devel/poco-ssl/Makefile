# Created by: wes@FreeBSD.org
# $FreeBSD$

PORTNAME=	poco
PORTVERSION=	1.4.3
PORTREVISION=	2
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-ssl
DISTNAME=	poco-${PORTVERSION}p1-all

MAINTAINER=	wes@FreeBSD.org
COMMENT=	C++ Portable Components library with NetSSL and Database libraries

CONFLICTS=	poco-[0-9]*

OPTIONS_DEFINE=	TEST SAMPLES MYSQL SQLITE
SAMPLES_DESC=	Build sample programs
UODBC_DESC=	Build with ODBC driver
IODBC_DESC=	Build with iODBC driver

OPTIONS_RADIO=	ODBC
OPTIONS_RADIO_ODBC=	UODBC IODBC
ODBC_DESC=	ODBC Driver

OPTIONS_DEFAULT=	MYSQL IODBC SQLITE

CONFIGURE_ARGS= --config=FreeBSD

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MTEST}
CONFIGURE_ARGS+= --no-tests
.endif

.if ! ${PORT_OPTIONS:MSAMPLES}
CONFIGURE_ARGS+= --no-samples
.endif

#
# ODBC
#

.if ! ${PORT_OPTIONS:MUODBC} && ! ${PORT_OPTIONS:MIODBC}
CONFIGURE_ARGS+= --omit=Data/ODBC
.endif

.if ${PORT_OPTIONS:MUODBC} && ! ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
.endif

.if ${PORT_OPTIONS:MIODBC} && ! ${PORT_OPTIONS:MUODBC}
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+= --omit=Data/MySQL
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+= --omit=Data/SQLite
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
