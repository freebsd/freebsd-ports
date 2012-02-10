# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
# Completely rewritten by Alex Goncharov <alex-goncharov@comcast.net> on 2008-08-30.

# $FreeBSD$
#

PORTNAME=		postgresql
PORTVERSION=		08.04.0200
PORTREVISION=	1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	odbc/versions/src
PKGNAMESUFFIX=		-odbc
DISTNAME=		psqlodbc-${PORTVERSION}
DIST_SUBDIR=		postgresql

MAINTAINER=		ports@FreeBSD.org
COMMENT=		PostgreSQL ODBC driver

USE_OPENSSL=	yes
USE_PGSQL=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=		YES

.if !defined(WITH_IODBC)
WITH_UNIXODBC=	yes
.endif

.if defined(WITH_UNIXODBC)
# I.e. even if WITH_IODBC is defined
LIB_DEPENDS+=		odbc.2:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS+=		unixODBC>=2.2.14_1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=${LOCALBASE}
.else
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}

# Modify a suffix in this case
PKGNAMESUFFIX=	-iodbc
.endif

DATADIR_1=	${DATADIR}/odbc
DOCSDIR_1=	${DOCSDIR}/odbc
post-install:
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR_1}
	${INSTALL_DATA} ${WRKSRC}/*.sql ${DATADIR_1}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR_1}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR_1}
.endif

.include <bsd.port.mk>
