# Created by: wes@FreeBSD.org
# $FreeBSD$

PORTNAME=	poco
PORTVERSION=	1.4.3
PORTREVISION=	3
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-ssl
DISTNAME=	poco-${PORTVERSION}p1-all

MAINTAINER=	wes@FreeBSD.org
COMMENT=	C++ Portable Components library with NetSSL and Database libraries

BROKEN=		Fails to build

CONFLICTS=	poco-[0-9]*

OPTIONS_DEFINE=	TEST SAMPLES MYSQL SQLITE ODBC
SAMPLES_DESC=	Build sample programs

OPTIONS_DEFAULT=	MYSQL SQLITE

CONFIGURE_ARGS= --config=FreeBSD

USES=		gmake tar:bzip2

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

ODBC_CONFIGURE_OFF= --omit=Data/ODBC
ODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/libiodbc

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
USE_LDCONFIG=	yes

.include <bsd.port.mk>
