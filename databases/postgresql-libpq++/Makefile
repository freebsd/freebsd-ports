# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	libpq++
PORTVERSION=	4.0
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	projects/gborg/libpqpp/stable
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	C++ interface for  PostgreSQL

DEPRECATED=	Not maintained upstreams for 10+ years.
EXPIRATION_DATE=2013-11-17

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 1000024
BROKEN=		Does not build under FreeBSD 10
.endif

USE_PGSQL=	YES
USES=		gmake
USE_LDCONFIG=	YES

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} "s,/usr/local/pgsql,${PREFIX},; \
			  s,^CFLAGS.*,CFLAGS=${CFLAGS},; \
			  s,\...SO_MINOR_VERSION.,,; \
			  s,\-I,\-fPIC \-I,; \
			  s,\(\-[IL]\)[^/]*,\\1${LOCALBASE}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
