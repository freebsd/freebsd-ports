# New ports collection makefile for:	PostgreSQL eRServer
# Date created:		1 Sep 2003
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	erserver
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/erserver/stable/
DISTNAME=	${PORTNAME}_v${PORTVERSION}
DIST_SUBDIR=	postgresql

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Trigger-based asynchronous replication system for PostgreSQL

PGSQL_PORT=	${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		${PGINC}/executor/spi.h:${PGSQL_PORT}
RUN_DEPENDS=	${JAVAJARDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		postgres:${PGSQL_PORT}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	1.2+
USE_PERL5=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME} JAVA=${JAVA}
CONFIGURE_ARGS=	--with-pgincludes=${PGINC}
MAKE_ENV=	JAVA_HOME=${JAVA_HOME} JAVA=${JAVA} \
		PATH=${JAVA_HOME}/bin:${PATH}
MAKE_ARGS=	sqldir=${DATADIR} templdir=${DATADIR} docdir=${DOCSDIR} \
		libdir=${PREFIX}/lib/postgresql javadir=${JAVAJARDIR} \
		siteperldir=${SITE_PERL}

DEFAULT_PGSQL_VER?=74

.include <bsd.port.pre.mk>
# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -n 's/postmaster.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

PGINC=		${LOCALBASE}/include/postgresql/server

pre-install:
	${MKDIR} ${DOCSDIR}

.include <bsd.port.post.mk>
