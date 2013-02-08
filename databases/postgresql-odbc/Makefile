# Create by: Palle Girgensohn <girgen@partitur.se>
# $FreeBSD$

PORTNAME=	postgresql
PORTVERSION=	09.01.0200
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	odbc/versions/src
PKGNAMESUFFIX=	-odbc
DISTNAME=	psqlodbc-${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	PostgreSQL ODBC driver

LICENSE=	LGPL20

USE_OPENSSL=	yes
USE_PGSQL=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

PORTDOCS=	odbc/
PLIST_FILES=	lib/psqlodbcw.la lib/psqlodbcw.so

.if !defined(WITH_IODBC) || defined(WITH_UNIXODBC)
# I.e. even if WITH_IODBC is defined
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS+=	unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=${LOCALBASE}
.else
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}

# Modify a suffix in this case
PKGNAMESUFFIX=	-iodbc
.endif

.include <bsd.port.options.mk>

DATADIR_1=	${DATADIR}/odbc
DOCSDIR_1=	${DOCSDIR}/odbc
post-install:
.if ${PORT_OPTIONS:MDATA}
	@${MKDIR} ${DATADIR_1}
	${INSTALL_DATA} ${WRKSRC}/*.sql ${DATADIR_1}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR_1}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR_1}
.endif

.include <bsd.port.mk>
