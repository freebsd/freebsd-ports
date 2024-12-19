PORTNAME=	keydb
DISTVERSIONPREFIX=	v
DISTVERSION=	6.3.4
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	zi@FreeBSD.org
COMMENT=	High performance fork of Redis--a persistent key-value database
WWW=		https://docs.keydb.dev/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	assertion failed: static_assert(sizeof(long) == sizeof(long long),"")
BROKEN_powerpc=	assertion failed: static_assert(sizeof(long) == sizeof(long long),"")

LIB_DEPENDS=	libuuid.so:misc/libuuid \
		liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd

USES=		compiler:c11 cpe gmake localbase:ldflags pkgconfig:build

USE_GITHUB=	yes
GH_ACCOUNT=	Snapchat
GH_PROJECT=	KeyDB
USE_RC_SUBR=	keydb keydb_sentinel

MAKE_ENV=	OPTIMIZATION= \
		V=yo

LDFLAGS+=	-lpthread -lm -lexecinfo

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		KEYDB_DBDIR=${KEYDB_DBDIR} \
		KEYDB_LOGDIR=${KEYDB_LOGDIR} \
		KEYDB_RUNDIR=${KEYDB_RUNDIR} \
		KEYDB_USER=${USERS}

USERS=		keydb
GROUPS=		keydb

PLIST_SUB=	KEYDB_DBDIR=${KEYDB_DBDIR} \
		KEYDB_GROUP=${GROUPS} \
		KEYDB_LOGDIR=${KEYDB_LOGDIR} \
		KEYDB_RUNDIR=${KEYDB_RUNDIR} \
		KEYDB_USER=${USERS}

OPTIONS_DEFINE=	TLS
OPTIONS_DEFAULT=TLS

TLS_DESC=	Use TLS (openssl req.)

TLS_USES=	ssl
TLS_MAKE_ENV=	BUILD_TLS=yes

BIN_FILES=	keydb-benchmark keydb-check-aof keydb-check-rdb keydb-cli \
		keydb-sentinel keydb-server

KEYDB_DBDIR?=	/var/db/keydb
KEYDB_RUNDIR?=	/var/run/keydb
KEYDB_LOGDIR?=	/var/log/keydb

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 && !${CFLAGS:M-march=*}
# Needed for __atomic_fetch_add_8
USE_GCC=	yes
CFLAGS+=	-march=i586
.endif

.if defined(_ADDFLAGS)
CFLAGS+=	-fPIC
LDFLAGS+=	-Wl,-E
.endif

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/src/Makefile

post-build:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/keydb.conf > ${WRKDIR}/keydb.conf

do-install:
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKSRC}/src/!} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/keydb.conf ${STAGEDIR}${PREFIX}/etc/keydb.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sentinel.conf ${STAGEDIR}${PREFIX}/etc/keydb_sentinel.conf.sample
	${MKDIR} ${STAGEDIR}${KEYDB_LOGDIR} \
		${STAGEDIR}${KEYDB_DBDIR} \
		${STAGEDIR}${KEYDB_RUNDIR}

.include <bsd.port.post.mk>
