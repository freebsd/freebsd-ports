# $FreeBSD$

PORTNAME=	pglesslog
PORTVERSION=	1.4.1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2684/
DISTNAME=	pg_lesslogg_${PORTVERSION}_pg84

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Reduce size of PostgreSQL archive log files by replacing backup blocks

USES=		gmake pgsql:8.4
WANT_PGSQL=	server:build
WRKSRC=		${WRKDIR}/pg_lesslog_${PORTVERSION}_pg84

PGSQL_PORT=	databases/postgresql${PGSQL_VER:S,.,,}
PGSQL_SRCDIR=	`cd ${PORTSDIR}/${PGSQL_PORT}-server; ${MAKE} -VWRKSRC`

pre-build:
	${REINPLACE_CMD} "s|top_builddir = ../..|top_builddir = ${PGSQL_SRCDIR}|" ${WRKSRC}/Makefile.*

.include <bsd.port.mk>
