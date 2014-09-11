# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	2.0.${SNAPDATE}
CATEGORIES=	devel
MASTER_SITES=	LOCAL/ohauer
DISTNAME=	${PORTNAME}_${SNAPDATE}
PKGNAMESUFFIX=	2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LICENSE=	APACHE20

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

NO_PACKAGE=	yes

SNAPDATE=	20140626144503

USES=			tar:xz iconv perl5 pathfix libtool
USE_AUTOTOOLS=		automake:env autoconf:env libtoolize:env
USE_PERL5=		build
USE_PYTHON_BUILD=	2
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		DEVELOPER_ONLY
OPTIONS_GROUP=		APR APU
OPTIONS_GROUP_APR=	THREADS IPV6 DEVRANDOM
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
# is there a valid requirement to build without threads
# if not make thread a mandantory default
THREADS_CONFIGURE_ENABLE=	threads

# APR-Util Options
BDB_USE=		BDB=48+
GDBM_CONFIGURE_WITH=	gdbm=${LOCALBASE}
GDBM_LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm
IPV6_CONFIGURE_ENABLE=	ipv6
MYSQL_CFLAGS=		-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
MYSQL_CONFIGURE_WITH=	mysql=${LOCALBASE}
MYSQL_LIBS=		-L${LOCALBASE}/lib/mysql
MYSQL_USE=		MYSQL=yes
NDBM_CONFIGURE_WITH=	ndbm=/usr
PGSQL_CONFIGURE_ENV=	ac_cv_path_PGSQL_CONFIG=""
PGSQL_CONFIGURE_WITH=	pgsql=${LOCALBASE}
PGSQL_USE=		PGSQL=yes
SQLITE_CONFIGURE_WITH=	sqlite3=${LOCALBASE}
SQLITE_USE=		SQLITE=yes

# crypto
SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}
SSL_CPPFLAGS=		-I${OPENSSLINC}
SSL_LDFLAGS=		-L${OPENSSLLIB}
NSS_LIB_DEPENDS=	libnss3.so:${PORTSDIR}/security/nss
NSS_CPPFLAGS=		-I${LOCALBASE}/include/nss
NSS_LDFLAGS=		-L${LOCALBASE}/lib/nss
NSS_CONFIGURE_WITH=	nss=${LOCALBASE}

.include <bsd.port.options.mk>

CONFIGURE_ENV+=	CC="${CC}"
CONFIGURE_ARGS+=--with-installbuilddir=${DATADIR}/build-2 \
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
	${REINPLACE_CMD} -e '1s|${SETENV} python|${LOCALBASE}/bin/${PYTHON_VERSION}|' \
		${WRKSRC}/build/gen-build.py
	${REINPLACE_CMD} -e 's|PrintPath python|PrintPath ${PYTHON_VERSION}|' \
		-e 's|python -c|${PYTHON_VERSION} -c|' \
		${WRKSRC}/build/buildcheck.sh

run-autotools:
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

debug_autoconf:
	@${ECHO} "LIBTOOL: ${LIBTOOL_VERSION}"
	@${ECHO} "AUTOCONF: dev ${dev_acver} cur ${cur_acver} use ${use_acver}"
	@${ECHO} "AUTOMAKE: dev ${dev_amver} cur ${cur_amver} use ${use_amver}"
	@${ECHO} "AUTOCONF_DIR: ${AUTOCONF_DIR}"
	@${ECHO} "BUILD_DEPENDS: ${BUILD_DEPENDS}"
	@${ECHO} "ACLOCAL_DIR: ${ACLOCAL_DIR}"
	@${ECHO} "LIBTOOL_SHAREDIR: ${LIBTOOL_SHAREDIR}"
	@${ECHO} "LIBTOOL_LIBEXECDIR: ${LIBTOOL_LIBEXECDIR}"
	@${ECHO} "LIBTOOL_M4: ${LIBTOOL_M4}"
	@${ECHO} "==================="
	@${ECHO} "${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS}" | ${TR} -s ' ' '\n'

.include <bsd.port.mk>
