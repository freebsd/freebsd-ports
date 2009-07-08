# New ports collection makefile for:	postgresql-contrib
# Date created:		June 10, 2003
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PKGNAMESUFFIX=	-contrib
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	The contrib utilities from the PostgreSQL distribution

USE_PGSQL=	yes
MASTERDIR=	${.CURDIR}/../postgresql${PGSQL_VER}-server

DEFAULT_PGSQL_VER?=82

# can't include <bsd.port.pre.mk> in a slave port
# so set these instead:
LOCALBASE?=	/usr/local
SED?=		/usr/bin/sed

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)[^0-9].*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

USE_BISON=	build

BUILD_DIRS=	src/port contrib
INSTALL_DIRS=	contrib

SLAVE_ONLY=	yes
PKGMESSAGE=	${.CURDIR}/pkg-message

.if ${PGSQL_VER} > 83
CONFIGURE_ARGS+=	--with-libxslt --with-libxml
LIB_DEPENDS=		xslt.2:${PORTSDIR}/textproc/libxslt xml2.5:${PORTSDIR}/textproc/libxml2
.endif

post-install:
.if ${PGSQL_VER} < 81
	@- ${INSTALL_SCRIPT} ${WRKSRC}/contrib/ipc_check/ipc_check.pl ${PREFIX}/bin/ipc_check ;\
	  ${INSTALL_DATA} ${WRKSRC}/contrib/ipc_check/README ${DOCSDIR}/contrib/README.ipc_check ;\
	  ${INSTALL_SCRIPT} ${WRKSRC}/contrib/reindexdb/reindexdb ${PREFIX}/bin/reindexdb ;\
	  ${INSTALL_DATA} ${WRKSRC}/contrib/reindexdb/README ${DOCSDIR}/contrib/README.reindexdb
.endif
	@- ${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/README

.include "${MASTERDIR}/Makefile"
