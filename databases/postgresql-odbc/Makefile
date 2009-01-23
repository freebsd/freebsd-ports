# New ports collection makefile for:  PostgreSQL ODBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
# Completely rewritten by Alex Goncharov <alex-goncharov@comcast.net> on 2008-08-30.

#
# $FreeBSD$
#

# PostgreSQL ODBC driver should work under either unixODBC or iODBC
# driver manager, when compliled against one. (Important: Do not try
# to have both installed -- they have overlapping files).

# It looks like most people are using unixODBC these days, rather than
# iODBC, so let's make unixODBC the default choice: to select iODBC,
# set WITH_IODBC, without setting WITH_UNIXODBC.  When the latter is
# set or when neither is set, we go with WITH_UNIXODBC.

# Following the existing convention, and other postgresql-* pieces,
# this is considered to be a part of the `postgresql' port.

PORTNAME=		postgresql
PORTVERSION=		08.03.0400
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	odbc/versions/src
# PKGNAMESUFFIX will be changed for the driver used with iODBC
PKGNAMESUFFIX=		-odbc
DISTNAME=		psqlodbc-${PORTVERSION}
DIST_SUBDIR=		postgresql

MAINTAINER=		alex-goncharov@comcast.net
COMMENT=		PostgreSQL ODBC driver

BUILD_DEPENDS=		pg_config:${PORTSDIR}/databases/postgresql83-client

GNU_CONFIGURE=		YES

.if !defined(WITH_IODBC)
WITH_UNIXODBC=	yes
.endif

.if defined(WITH_UNIXODBC)
# I.e. even if WITH_IODBC is defined
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=${LOCALBASE}

BROKEN=			does not compile
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
