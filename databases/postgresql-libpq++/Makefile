# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpq++
PORTVERSION=	4.0
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/libpqpp/stable/
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net

POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_GMAKE=	YES
USE_REINPLACE=	YES
INSTALLS_SHLIB=	YES

post-patch:
	${REINPLACE_CMD} "s,/usr/local/pgsql,${PREFIX},; \
			  s,^CFLAGS.*,CFLAGS=${CFLAGS},; \
			  s,\...SO_MINOR_VERSION.,,; \
			  s,\(\-[IL]\)[^/]*,\\1${LOCALBASE}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
