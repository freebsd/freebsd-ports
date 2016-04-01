# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	2.0.${SNAPDATE}
CATEGORIES=	devel
MASTER_SITES=	LOCAL/ohauer
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}_${SNAPDATE}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LICENSE=	APACHE20

LIB_DEPENDS=	libexpat.so:textproc/expat2

NO_PACKAGE=	yes

# r1676013
SNAPDATE=	20150425134304

USES=		autoreconf:build cpe iconv libtool pathfix perl5 \
		python:2.7,build tar:xz
CPE_PRODUCT=	apr-util
CPE_VENDOR=	apache
CPE_VERSION=	${PORTVERSION:S|.${SNAPDATE}||}
USE_PERL5=		build
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		DEVELOPER_ONLY
OPTIONS_GROUP=		APR APU
OPTIONS_GROUP_APR=	IPV6 DEVRANDOM
OPTIONS_GROUP_APU=	BDB GDBM MYSQL NDBM PGSQL SQLITE
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SSL NSS
OPTIONS_DEFAULT=	THREADS IPV6 DEVRANDOM BDB GDBM SSL

DEVELOPER_ONLY_DESC=	I want to test apr2 not the maintainer
DEVRANDOM_DESC=		Use /dev/random or compatible
NDBM_DESC=		NDBM support
NSS_DESC=		NSS crypto driver
SSL_DESC=		OpenSSL crypto driver

WRKSRC=	${WRKDIR}/apr

DEVRANDOM_CONFIGURE_WITH=	devrandom

# APR-Util Options
BDB_USE=		BDB=48+
GDBM_CONFIGURE_WITH=	gdbm=${LOCALBASE}
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
IPV6_CONFIGURE_ENABLE=	ipv6
MYSQL_CFLAGS=		-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
MYSQL_CONFIGURE_WITH=	mysql=${LOCALBASE}
MYSQL_LIBS=		-L${LOCALBASE}/lib/mysql
MYSQL_USE=		MYSQL=yes
NDBM_CONFIGURE_WITH=	ndbm=/usr
PGSQL_CONFIGURE_ENV=	ac_cv_path_PGSQL_CONFIG=""
PGSQL_CONFIGURE_WITH=	pgsql=${LOCALBASE}
PGSQL_USES=		pgsql
SQLITE_CONFIGURE_WITH=	sqlite3=${LOCALBASE}
SQLITE_USES=		sqlite

# crypto
SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}
SSL_CPPFLAGS=		-I${OPENSSLINC}
SSL_LDFLAGS=		-L${OPENSSLLIB}
NSS_LIB_DEPENDS=	libnss3.so:security/nss
NSS_CPPFLAGS=		-I${LOCALBASE}/include/nss
NSS_LDFLAGS=		-L${LOCALBASE}/lib/nss
NSS_CONFIGURE_WITH=	nss=${LOCALBASE}

.include <bsd.port.options.mk>

CONFIGURE_ENV+=	CC="${CC}"
CONFIGURE_ARGS+=--with-installbuilddir=${DATADIR}/build-2 \
		--enable-threads \
		--enable-posix-shm \
		--with-expat=${LOCALBASE} \
		--with-iconv=${ICONV_PREFIX}

SHLIB_MAJOR=	0
PLIST_SUB+=	SHLIB_MAJOR="${SHLIB_MAJOR}"

# stick BDB here, else BDB_INCLUDE_DIR and BDB_LIB_DIR
# are not resolvable
.if ${PORT_OPTIONS:MBDB}
CONFIGURE_ARGS+=	--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

.if ! ${PORT_OPTIONS:MDEVELOPER_ONLY}
IGNORE=	not for the general public. Maintainer only supports developers of apr
.endif

# crypto required (apache24)
.if ${PORT_OPTIONS:MSSL} || ${PORT_OPTIONS:MNSS}
CONFIGURE_ARGS+=	--with-crypto
.else
CONFIGURE_ARGS+=	--without-crypto
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%OSVERSION%%|${OSVERSION}|g' ${WRKSRC}/build/apr_hints.m4
	${REINPLACE_CMD} -e '1s|${SETENV} python|${PYTHON_CMD}|' \
		${WRKSRC}/build/gen-build.py
	${REINPLACE_CMD} -e 's|PrintPath python|PrintPath ${PYTHON_VERSION}|' \
		-e 's|python -c|${PYTHON_VERSION} -c|' \
		${WRKSRC}/build/buildcheck.sh

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf)

pre-install:
# looking forward to sub packages and create the modules directory
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/apr-2
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/apr-2/.keep.me

post-install:
	${FIND} ${STAGEDIR}/${PREFIX}/lib -name \*.so | ${XARGS} ${STRIP_CMD}

test:	build
	@-make test -C ${WRKSRC}

#regression-test:	test

.include <bsd.port.mk>
