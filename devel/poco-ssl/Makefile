# ex:ts=8
# New ports collection makefile for:	poco-ssl
# Date created:			Jan 28, 2007
# Whom:				wes
#
# $FreeBSD$
#

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

OPTIONS=	TESTS	"Build testsuites" off \
		SAMPLES	"Build sample programs" off \
		MYSQL	"Build MySQL driver" on \
		UODBC	"Build with ODBC driver" off \
		IODBC	"Build with iODBC driver" on \
		SQLITE	"Build SQLite driver" on

CONFIGURE_ARGS= --config=FreeBSD

.if !defined(WITH_TESTS)
CONFIGURE_ARGS+= --no-tests
.endif

.if !defined(WITH_SAMPLES)
CONFIGURE_ARGS+= --no-samples
.endif

#
# ODBC
#
.if defined(WITH_UODBC) && defined(WITH_IODBC)
IGNORE=		please select either UODBC or IODBC, but not both
.endif

.if !defined(WITH_UODBC) && !defined(WITH_IODBC)
CONFIGURE_ARGS+= --omit=Data/ODBC
.endif

.if defined(WITH_UODBC) && !defined(WITH_IODBC)
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
.endif

.if defined(WITH_IODBC) && !defined(WITH_UODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+= --omit=Data/MySQL
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+= --omit=Data/SQLite
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
