# Created by: vanilla@
# $FreeBSD$

PORTNAME=	libzdb
PORTVERSION=	2.11.3
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thread-safe connection pool library

LICENSE=	GPLv3

OPTIONS_DEFINE=	MYSQL \
		SQLITE \
		PGSQL

OPTIONS_DEFAULT=MYSQL SQLITE PGSQL

NO_STAGE=	yes

USES=	gmake pathfix
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MYSQL_USE=	mysql=yes
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}/bin/mysql_config
MYSQL_CONFIGURE_OFF=	--without-mysql
SQLITE_USE=	sqlite=3
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}
SQLITE_CONFIGURE_OFF=	--without-sqlite
PGSQL_USE=	pgsql=yes
PGSQL_CONFIGURE_ON=	--with-postgresql=${LOCALBASE}/bin/pg_config
PGSQL_CONFIGURE_OFF=	--without-postgresql

.include <bsd.port.mk>
