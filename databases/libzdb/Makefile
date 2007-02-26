# New ports collection makefile for:	libzdb
# Date created:				Nov 28 2005
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	libzdb
PORTVERSION=	2.0
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thread-safe connection pool library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnometarget
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OPTIONS=	MYSQL "Add MySQL support" on \
		SQLITE " Add Sqlite support" on \
		PGSQL "Add PgSQL support" on

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
	@${REINPLACE_CMD} 's,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
