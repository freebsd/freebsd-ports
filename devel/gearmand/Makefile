PORTNAME=	gearmand
PORTVERSION=	1.0.6
PORTREVISION=	24
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/1.0/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gearman C Server and Library
WWW=		http://www.gearman.org/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c++11-lang pathfix gmake perl5 python:build \
	libtool localbase:ldflags
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_RC_SUBR=	gearmand

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-lib-prefix=${LOCALBASE} --with-boost=${LOCALBASE} \
		--localstatedir=/var/db/${PORTNAME} --enable-static

LDFLAGS+=	-lexecinfo

CONFLICTS=	p5-Gearman-Server-1.* gearmand-1.1.*

SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS}

USERS=		gearmand
GROUPS=		gearmand

OPTIONS_DEFINE=	DRIZZLE MEMCACHED PGSQL SQLITE MYSQL HIREDIS TOKYOCAB
OPTIONS_DEFAULT=SQLITE

DRIZZLE_DESC=	Drizzle support for persistent queue
HIREDIS_DESC=	Hiredis support for persistent queue
MEMCACHED_DESC=	memcached support for persistent queue
MYSQL_DESC=	MySQL support for persistent queue
PGSQL_DESC=	PostgreSQL support for persistent queue
SQLITE_DESC=	SQLite support for persistent queue
TOKYOCAB_DESC=	Tokyo Cabinet support for persistent queue

DRIZZLE_LIB_DEPENDS=		libdrizzle.so:databases/libdrizzle
DRIZZLE_CONFIGURE_ENABLE=	libdrizzle
HIREDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
HIREDIS_CONFIGURE_ENABLE=	hires
HIREDIS_CONFIGURE_ENV=		LIBHIREDIS_CPPFLAGS=-I${LOCALBASE}/include/hiredis \
			LIBHIREDIS_LDFLAGS=-L${LOCALBASE}/lib
MEMCACHED_LIB_DEPENDS=		libmemcached.so:databases/libmemcached
MEMCACHED_CONFIGURE_ENABLE=	libmemcached
MYSQL_USES=			mysql
MYSQL_CONFIGURE_ON=	--with-mysql=yes
MYSQL_CONFIGURE_OFF=	--with-mysql=no
MYSQL_VARS=		IGNORE_WITH_MYSQL="80 81"
PGSQL_USES=			pgsql
PGSQL_CONFIGURE_ENABLE=	libpq
SQLITE_USES=	sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite3=${LOCALBASE}
SQLITE_CONFIGURE_OFF=	--without-sqlite3
TOKYOCAB_LIB_DEPENDS=		libtokyocabinet.so:databases/tokyocabinet
TOKYOCAB_CONFIGURE_ENABLE=	libtokyocabinet
TOKYOCAB_CONFIGURE_ENV=		LIBTOKYOCABINET_CPPFLAGS=-I${LOCALBASE}/include \
			LIBTOKYOCABINET_LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMEMCACHED}
# This hack is required for the test programs invoked by configure,
# in the event that libmemcached was compiled with SASL support.
.if exists(${LOCALBASE}/lib/libsasl.so)
LDFLAGS+=		-lsasl
CONFIGURE_ARGS+=	--with-memcached-sasl=${LOCALBASE}/bin/memcached
.elif exists(${LOCALBASE}/lib/libsasl2.a)
LDFLAGS+=		-lsasl2
CONFIGURE_ARGS+=	--with-memcached-sasl=${LOCALBASE}/bin/memcached
.else
CONFIGURE_ARGS+=	--with-memcached=${LOCALBASE}/bin/memcached
.endif
.endif

.include <bsd.port.mk>
