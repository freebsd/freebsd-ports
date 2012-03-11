# New ports collection makefile for:	pglesslog
# Date created:				4 March 2010
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pglesslog
PORTVERSION=	1.2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2127/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Reduce size of PostgreSQL archive log files by replacing backup blocks

USE_GMAKE=	yes
USE_PGSQL=	client server:build
WANT_PGSQL_VER=	83
WRKSRC=		${WRKDIR}/lesslog-${PORTVERSION}

PGSQL_PORT=	databases/postgresql${PGSQL_VER}
PGSQL_SRCDIR=	`cd ${PORTSDIR}/${PGSQL_PORT}-server; ${MAKE} -VWRKSRC`

pre-build:
	${REINPLACE_CMD} "s|top_builddir = ../..|top_builddir = ${PGSQL_SRCDIR}|" ${WRKSRC}/Makefile.*

.include <bsd.port.mk>
