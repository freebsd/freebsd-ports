# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpqxx
PORTVERSION=	2.6.9
CATEGORIES=	databases
MASTER_SITES=	ftp://thaiopensource.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	software/libpqxx
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A new C++ interface for PostgreSQL

USE_PGSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}

CONFIGURE_ARGS=	--with-postgres=${LOCALBASE} \
		--enable-shared \
		--with-postgres-include=${LOCALBASE}/include/postgresql

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CPPFLAGS+=	-I${LOCALBASE}/include/stlport
LDFLAGS+=	-L${LOCALBASE}/lib -lstlport_gcc ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
.endif

.include <bsd.port.post.mk>
