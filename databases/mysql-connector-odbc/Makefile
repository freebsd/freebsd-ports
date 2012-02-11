# New ports collection makefile for:	MyODBC
# Date created:				22 Mar 2004
# Whom:					sergey@migsoft.com.ua
#
# $FreeBSD$
#

PORTNAME=	mysql-connector-odbc
PORTVERSION=	5.1.9
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-ODBC/5.1
PKGNAMESUFFIX=	-${DRIVER_MANAGER}-mysql${MYSQL_VER}

MAINTAINER=	sergey@network-asp.biz
COMMENT=	ODBC driver for MySQL${MYSQL_VER} / ${DRIVER_MANAGER}

USE_LDCONFIG=	yes
USE_MYSQL=	yes
DEFAULT_MYSQL_VER=	51
USE_CMAKE=	yes

PLIST_SUB=	VER=${PORTVERSION}

PORTDOCS=	ChangeLog INSTALL \
		README README.debug COPYING Licenses_for_Third-Party_Components.txt

# MyODBC needs an ODBC driver manager to be installed, and it supports both
# iODBC and unixODBC.

.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=		selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

.if !defined(WITH_IODBC) && !defined(WITH_UNIXODBC)
WITH_UNIXODBC?=	yes
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=		odbc.2:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS=		unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC
CMAKE_ARGS              += -DWITH_UNIXODBC=1
DRIVER_MANAGER=		unixodbc
.elif defined(WITH_IODBC)
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
DRIVER_MANAGER=		iodbc
CFLAGS+=		-I${LOCALBASE}/include
.endif

.include <bsd.port.mk>
