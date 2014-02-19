# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	gearmand
PORTVERSION=	1.1.8
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/gearmand/1.2/${PORTVERSION}/+download/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Gearman C Server and Library

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs \
		libexecinfo>=0:${PORTSDIR}/devel/libexecinfo \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		execinfo:${PORTSDIR}/devel/libexecinfo

CONFLICTS=	p5-Gearman-Server-1.* gearmand-1.0.*

PKGNAMESUFFIX=	-devel

USERS=		gearmand
GROUPS=		gearmand

USE_PERL5=	build
GNU_CONFIGURE=	yes
USES=		pathfix perl5 gmake
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=yes
USE_RC_SUBR=	gearmand
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS}

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

# Workaround for missing sigignore that wasn't introduced until
# FreeBSD 8.0
.if ${OSVERSION} < 800041
BROKEN=	Does not compile without POSIX spawn() support
.endif

.if ${PORT_OPTIONS:MDRIZZLE}
LIB_DEPENDS+=		drizzle:${PORTSDIR}/databases/libdrizzle
CONFIGURE_ARGS+=	--enable-libdrizzle
.else
CONFIGURE_ARGS+=	--disable-libdrizzle
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
LIB_DEPENDS+=		memcached:${PORTSDIR}/databases/libmemcached
BUILD_DEPENDS+=		memcached>=0:${PORTSDIR}/databases/memcached
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
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=yes
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-libpq
.else
CONFIGURE_ARGS+=	--disable-libpq
.endif

.if ${PORT_OPTIONS:MSQLITE}
BUILD_DEPENDS+=		sqlite3>=3.0.0:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if ${PORT_OPTIONS:MTOKYOCAB}
LIB_DEPENDS+=		tokyocabinet:${PORTSDIR}/databases/tokyocabinet
CONFIGURE_ARGS+=	--enable-libtokyocabinet
CONFIGURE_ENV+=		LIBTOKYOCABINET_CPPFLAGS=-I${LOCALBASE}/include \
			LIBTOKYOCABINET_LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-libtokyocabinet
.endif

.if ${PORT_OPTIONS:MHIREDIS}
LIB_DEPENDS+=		hiredis:${PORTSDIR}/databases/hiredis
CONFIGURE_ARGS+=	--enable-hires
CONFIGURE_ENV+=		LIBHIREDIS_CPPFLAGS=-I${LOCALBASE}/include/hiredis \
			LIBHIREDIS_LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-hires
.endif

.include <bsd.port.mk>
