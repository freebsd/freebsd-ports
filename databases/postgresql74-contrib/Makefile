# New ports collection makefile for:	postgresql-contrib
# Date created:		June 10, 2003
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PKGNAMESUFFIX=	-contrib
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	The contrib utilities from the PostgreSQL distribution

USE_PGSQL=	yes
DEFAULT_PGSQL_VER=74
MASTERDIR=	${.CURDIR}/../postgresql${DEFAULT_PGSQL_VER}-server

USE_BISON=	build

BUILD_DIRS=	src/port contrib
INSTALL_DIRS=	contrib

SLAVE_ONLY=	yes

post-install:
	@- ${INSTALL_SCRIPT} ${WRKSRC}/contrib/ipc_check/ipc_check.pl ${PREFIX}/bin/ipc_check ;\
	  ${INSTALL_DATA} ${WRKSRC}/contrib/ipc_check/README ${DOCSDIR}/contrib/README.ipc_check ;\
	  ${INSTALL_SCRIPT} ${WRKSRC}/contrib/reindexdb/reindexdb ${PREFIX}/bin/reindexdb ;\
	  ${INSTALL_DATA} ${WRKSRC}/contrib/reindexdb/README ${DOCSDIR}/contrib/README.reindexdb ;\
	  ${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/README

.include "${MASTERDIR}/Makefile"
