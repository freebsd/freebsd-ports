# $FreeBSD$

PORTNAME=	pglesslog
PORTVERSION=	1.4.2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2718/
DISTNAME=	pg_lesslog_${PORTVERSION}_pg90_beta

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Reduce size of PostgreSQL archive log files by replacing backup blocks

USES=		gmake pgsql:9.0
WANT_PGSQL=	server:build
WRKSRC=		${WRKDIR}/pg_lesslog_${PORTVERSION}_pg90

PGSQL_PORT=	databases/postgresql${PGSQL_VER:S,.,,}
PGSQL_SRCDIR=	`cd ${PORTSDIR}/${PGSQL_PORT}-server; ${MAKE} -VWRKSRC`

pre-build:
	${REINPLACE_CMD} "s|top_builddir = ../..|top_builddir = ${PGSQL_SRCDIR}|" ${WRKSRC}/Makefile.*

post-build:
	${STRIP_CMD} ${WRKSRC}/pg_compresslog ${WRKSRC}/pg_decompresslog

.include <bsd.port.mk>
