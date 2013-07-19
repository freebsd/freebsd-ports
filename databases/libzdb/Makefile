# Created by: vanilla@
# $FreeBSD$
#

PORTNAME=	libzdb
PORTVERSION=	2.11.3
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Thread-safe connection pool library

LICENSE=	GPLv3

OPTIONS_DEFINE=	MYSQL \
		SQLITE \
		PGSQL

OPTIONS_DEFAULT=MYSQL SQLITE PGSQL

.include <bsd.port.options.mk>

USES=	pathfix
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}/bin/mysql_config
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}/bin/pg_config
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

.include <bsd.port.post.mk>
