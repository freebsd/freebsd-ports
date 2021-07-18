# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	gearmand
PORTVERSION=	1.0.6
PORTREVISION=	22
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/1.0/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gearman C Server and Library

BROKEN_FreeBSD_13=	error: use of undeclared identifier 'abi'

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid

CONFLICTS=	p5-Gearman-Server-1.* gearmand-1.1.*

USERS=		gearmand
GROUPS=		gearmand

USES=		compiler:c++11-lang pathfix gmake perl5 python:build,3.6+ libtool
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	gearmand
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS}
USE_CXXSTD=	gnu++98

CONFIGURE_ARGS+=--with-lib-prefix=${LOCALBASE} --with-boost=${LOCALBASE} \
		--localstatedir=/var/db/${PORTNAME} --enable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

OPTIONS_DEFINE=	DRIZZLE MEMCACHED PGSQL SQLITE MYSQL HIREDIS TOKYOCAB
OPTIONS_DEFAULT=SQLITE

DRIZZLE_DESC=	Drizzle support for persistent queue
MEMCACHED_DESC=	memcached support for persistent queue
MYSQL_DESC=	MySQL support for persistent queue
PGSQL_DESC=	PostgreSQL support for persistent queue
SQLITE_DESC=	SQLite support for persistent queue
HIREDIS_DESC=	Hiredis support for persistent queue
TOKYOCAB_DESC=	Tokyo Cabinet support for persistent queue

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDRIZZLE}
LIB_DEPENDS+=		libdrizzle.so:databases/libdrizzle
CONFIGURE_ARGS+=	--enable-libdrizzle
.else
CONFIGURE_ARGS+=	--disable-libdrizzle
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
LIB_DEPENDS+=		libmemcached.so:databases/libmemcached
BUILD_DEPENDS+=		memcached>=0:databases/memcached
CONFIGURE_ARGS+=	--enable-libmemcached
# This hack is required for the test programs invoked by configure,
# in the event that libmemcached was compiled with SASL support.
.if exists(${LOCALBASE}/lib/libsasl.so)
LDFLAGS+=		-L${LOCALBASE}/lib -lsasl
CONFIGURE_ARGS+=	--with-memcached-sasl=${LOCALBASE}/bin/memcached
.elif exists(${LOCALBASE}/lib/libsasl2.a)
LDFLAGS+=		-L${LOCALBASE}/lib -lsasl2
CONFIGURE_ARGS+=	--with-memcached-sasl=${LOCALBASE}/bin/memcached
.else
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-memcached=${LOCALBASE}/bin/memcached
.endif
.else
CONFIGURE_ARGS+=	--disable-libmemcached
.endif

.if ${PORT_OPTIONS:MMYSQL}
USES+=			mysql
CONFIGURE_ARGS+=	--with-mysql=yes
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=			pgsql
CONFIGURE_ARGS+=	--enable-libpq
.else
CONFIGURE_ARGS+=	--disable-libpq
.endif

.if ${PORT_OPTIONS:MSQLITE}
BUILD_DEPENDS+=		sqlite3>=3.0.0:databases/sqlite3
LIB_DEPENDS+=		libsqlite3.so:databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if ${PORT_OPTIONS:MTOKYOCAB}
LIB_DEPENDS+=		libtokyocabinet.so:databases/tokyocabinet
CONFIGURE_ARGS+=	--enable-libtokyocabinet
CONFIGURE_ENV+=		LIBTOKYOCABINET_CPPFLAGS=-I${LOCALBASE}/include \
			LIBTOKYOCABINET_LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-libtokyocabinet
.endif

.if ${PORT_OPTIONS:MHIREDIS}
LIB_DEPENDS+=		libhiredis.so:databases/hiredis
CONFIGURE_ARGS+=	--enable-hires
CONFIGURE_ENV+=		LIBHIREDIS_CPPFLAGS=-I${LOCALBASE}/include/hiredis \
			LIBHIREDIS_LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-hires
.endif

.include <bsd.port.mk>
