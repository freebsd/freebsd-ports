# New ports collection makefile for:  PostgreSQL ODBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
# Completely rewritten by Alex Goncharov <alex-goncharov@comcast.net> on 2008-08-30.

#
# $FreeBSD$
#

# -- 2009-07-23 -- Alex Goncharov -->

# The driver has to be built against a driver manager; there is no
# reason to expect that it can be built against *any* driver manager.
# In days old, iODBC was the common choice of a driver manager on
# Unix.  Today, everybody builds and tests against another driver
# manager, unixODBC.

# When I took over this port, I made the build against unixODBC to be
# the default, and introduced the WITH_IODBC variable to build against
# iODBC.  At that point (2008-08-30), the i0DBC build worked and
# produced a workable driver.

# Starting from the new driver release, 08.04.0100, I am no longer
# trying to build the WITH_IODBC=yes case.  I keep this switch here,
# but you should really never use it -- iODBC has long been
# unmaintained and ODBC driver developers use unixODBC for builds and
# tests.

# -- 2008-08-30 -- Alex Goncharov ->

# Following the existing convention, and other postgresql-* pieces,
# this is considered to be a part of the `postgresql' port.

PORTNAME=		postgresql
PORTVERSION=		08.04.0100
PORTREVISION=		0
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	odbc/versions/src
# PKGNAMESUFFIX will be changed for the driver used with iODBC
PKGNAMESUFFIX=		-odbc
DISTNAME=		psqlodbc-${PORTVERSION}
DIST_SUBDIR=		postgresql

MAINTAINER=		ports@FreeBSD.org
COMMENT=		PostgreSQL ODBC driver

BUILD_DEPENDS=		pg_config:${PORTSDIR}/databases/postgresql83-client

GNU_CONFIGURE=		YES

IGNORE=			does not work properly (see ports/144993)

.if !defined(WITH_IODBC)
WITH_UNIXODBC=	yes
.endif

.if defined(WITH_UNIXODBC)
# I.e. even if WITH_IODBC is defined
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
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
