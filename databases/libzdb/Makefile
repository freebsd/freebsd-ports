# New ports collection makefile for:	libzdb
# Date created:				Nov 28 2005
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	libzdb
PORTVERSION=	1.0.3
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Thread-safe connection pool library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OPTIONS=	MYSQL "Add MySQL support" on \
		SQLITE " Add Sqlite support" on

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include/mysql" \
		LDFLAGS="-L${LOCALBASE}/lib/mysql"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.include <bsd.port.post.mk>
