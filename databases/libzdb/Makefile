# New ports collection makefile for:	libzdb
# Date created:				Nov 28 2005
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	libzdb
PORTVERSION=	2.2.3
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thread-safe connection pool library

OPTIONS=	MYSQL "Add MySQL support" on \
		SQLITE " Add Sqlite support" on \
		PGSQL "Add PgSQL support" on

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread |${PTHREAD_LIBS} |g ; \
		 s|_mysql/lib |_mysql/lib/mysql |g ; \
		 s|_mysql/include |_mysql/include/mysql |g ; \
		 s|_mysql/include"|_mysql/include/mysql"|g ; \
		 s|_mysql/lib/l|_mysql/lib/mysql/l|g ; \
		 s|_mysql/lib/ |_mysql/lib/mysql |g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
