# New ports collection makefile for:	libzdb
# Date created:				Nov 28 2005
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	libzdb
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Thread-safe connection pool library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnometarget
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"

OPTIONS=	MYSQL "Add MySQL support" on \
		SQLITE " Add Sqlite support" on

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
CONFIGURE_ENV+=	CPPFLAGS+="-I${LOCALBASE}/include/mysql" \
		LDFLAGS+="-L${LOCALBASE}/lib/mysql"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	3
CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

post-patch:
	@${REINPLACE_CMD} 's,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
