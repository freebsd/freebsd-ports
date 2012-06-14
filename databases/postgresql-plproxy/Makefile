# Ports collection makefile for:  postgresql-plproxy
# Date created:    27 July 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	plproxy
PORTVERSION=	2.4
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3274/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PL/Proxy is database partitioning system

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_BISON=	build

PORTSCOUT=	site:http://pgfoundry.org/frs/?group_id=1000207

MAKE_ARGS+=	CFLAGS+=-DSYS_SOCKET_H

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -En 's/.*PostgreSQL[^0-9]*([0-9]+)\.([0-9]+)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | \
		${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)[^0-9].*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

.if ${PGSQL_VER} > 91
PLIST_SUB+=	NEW_CONTRIB_DIR=""  OLD_CONTRIB_DIR="@comment "
.else
PLIST_SUB+=	NEW_CONTRIB_DIR="@comment "  OLD_CONTRIB_DIR=""
.endif

.include <bsd.port.post.mk>
