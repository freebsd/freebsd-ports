# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpq++
PORTVERSION=	4.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	projects/gborg/libpqpp/stable
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	C++ interface for  PostgreSQL

USE_PGSQL=	YES
USE_GMAKE=	YES
USE_REINPLACE=	YES
INSTALLS_SHLIB=	YES

post-patch:
	${REINPLACE_CMD} "s,/usr/local/pgsql,${PREFIX},; \
			  s,^CFLAGS.*,CFLAGS=${CFLAGS},; \
			  s,\...SO_MINOR_VERSION.,,; \
			  s,\-I,\-fPIC \-I,; \
			  s,\(\-[IL]\)[^/]*,\\1${LOCALBASE}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
