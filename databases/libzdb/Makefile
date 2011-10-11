# New ports collection makefile for:	libzdb
# Date created:				Nov 28 2005
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	libzdb
PORTVERSION=	2.9
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Thread-safe connection pool library

LICENSE=	GPLv3

OPTIONS=	MYSQL "Add MySQL support" on \
		SQLITE "Add Sqlite support" on \
		PGSQL "Add PgSQL support" on

USE_GNOME=	gnomehack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}/bin/mysql_config
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}/bin/pg_config
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

.include <bsd.port.post.mk>
