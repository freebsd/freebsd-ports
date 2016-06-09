# Created by: vanilla@
# $FreeBSD$

PORTNAME=	libzdb
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thread-safe connection pool library

LICENSE=	GPLv3

USES=		gmake libtool pathfix
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFINE=		SSL
OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE SSL
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE

MYSQL_USE=		mysql=yes
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}/bin/mysql_config
MYSQL_CONFIGURE_OFF=	--without-mysql
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgresql=${LOCALBASE}/bin/pg_config
PGSQL_CONFIGURE_OFF=	--without-postgresql
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}
SQLITE_CONFIGURE_OFF=	--without-sqlite
SSL_USE=		openssl=yes
SSL_CONFIGURE_ON=	--enable-openssl=${OPENSSLBASE}
SSL_CONFIGURE_OFF=	--disable-openssl

.include <bsd.port.mk>
