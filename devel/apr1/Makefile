# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	${APR_VERSION}.${APU_VERSION}
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	APACHE/apr
DISTFILES=	apr-${APR_VERSION}.tar.gz \
		apr-util-${APU_VERSION}.tar.gz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LICENSE=	APACHE20

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		iconv pathfix libtool cpe
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

APR_VERSION=	1.6.3
APU_VERSION=	1.6.1

CPE_VENDOR=	apache
CPE_PRODUCT=	apr-util
CPE_VERSION=	${APU_VERSION}

OPTIONS_SUB=		yes
OPTIONS_GROUP=		APU
OPTIONS_DEFINE=		IPV6 DEVRANDOM
OPTIONS_GROUP_APU=	BDB GDBM LDAP MYSQL NDBM ODBC PGSQL SQLITE
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SSL NSS
OPTIONS_DEFAULT=	DEVRANDOM BDB GDBM SSL

APU_DESC=		Database support
CRYPTO_DESC=		Cryptography provider
DEVRANDOM_DESC=		Use /dev/random or compatible
NDBM_DESC=		NDBM support
NSS_DESC=		NSS crypto driver
SSL_DESC=		OpenSSL crypto driver

# APR-Util Options
BDB_USES=		bdb:5+
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
LDAP_USE=		OPENLDAP=yes
MYSQL_USE=		MYSQL=yes
NSS_LIB_DEPENDS=	libnss3.so:security/nss
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
PGSQL_USES=		pgsql
SQLITE_USES=		sqlite
SSL_USES=		ssl

APR_WRKDIR=	${WRKDIR}/apr-${APR_VERSION}
APU_WRKDIR=	${WRKDIR}/apr-util-${APU_VERSION}
WRKSRC=		${APR_WRKDIR}
PATCH_WRKSRC=	${WRKDIR}
PATHFIX_WRKSRC=	${WRKDIR}

SHLIB_APR_MAJOR=${APR_VERSION:C/^1/0/}
SHLIB_APU_MAJOR=${APU_VERSION:C/^1/0/}

PLIST_SUB+=	SHLIB_APR_MAJOR="${SHLIB_APR_MAJOR}" \
		SHLIB_APU_MAJOR="${SHLIB_APU_MAJOR}"

APR_CONF_ARGS=	--with-installbuilddir=${DATADIR}/build-1 \
		--enable-threads \
		--enable-posix-shm

APU_CONF_ARGS=	--with-apr=${APR_WRKDIR} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${ICONV_PREFIX}

########## APR Options
IPV6_VARS=		APR_CONF_ARGS+=--enable-ipv6
IPV6_VARS_OFF=		APR_CONF_ARGS+=--disable-ipv6
DEVRANDOM_VARS=		APR_CONF_ARGS+=--with-devrandom
DEVRANDOM_VARS_OFF=	APR_CONF_ARGS+=--without-devrandom

######### APR-Util Options
# make sure 1st include is "${APR_WRKDIR}/include"
# to avoid failures if previous apr_version.h is present
APU_CPPFLAGS=	-I${APR_WRKDIR}/include

BDB_VARS=	APU_CONF_ARGS+=--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
BDB_VARS_OFF=	APU_CONF_ARGS+=--without-berkeley-db
GDBM_VARS=	APU_CONF_ARGS+=--with-gdbm=${LOCALBASE}
LDAP_VARS=	APU_CONF_ARGS+="--with-ldap-include=${LOCALBASE}/include \
			--with-ldap-lib=${LOCALBASE}/lib --with-ldap=ldap"
MYSQL_VARS=	APU_CONF_ARGS+=--with-mysql=${LOCALBASE} \
		APU_CPPFLAGS+="-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H" \
		LIBS+=-L${LOCALBASE}/lib/mysql
NDBM_VARS=	APU_CONF_ARGS+=--with-ndbm=/usr
NSS_VARS=	APU_CONF_ARGS+=--with-nss=${LOCALBASE} \
		APU_CPPFLAGS+=-I${LOCALBASE}/include/nss \
		LDFLAGS+=-L${LOCALBASE}/lib/nss
ODBC_VARS=	APU_CONF_ARGS+=--with-odbc=${LOCALBASE}
SSL_VARS=	APU_CONF_ARGS+=--with-openssl=${OPENSSLBASE} \
		APU_CPPFLAGS+=-I${OPENSSLINC} \
		LDFLAGS+=-L${OPENSSLLIB}
SSL_VARS_OFF=	APU_CONF_ARGS+=--without-openssl
PGSQL_VARS=	APU_CONF_ARGS+=--with-pgsql=${LOCALBASE} \
		APU_CONF_ENV+=ac_cv_path_PGSQL_CONFIG=""
SQLITE_VARS=		APU_CONF_ARGS+=--with-sqlite3=${LOCALBASE}
SQLITE_VARS_OFF=	APU_CONF_ARGS+=--without-sqlite3

.for db in GDBM NDBM LDAP ODBC MYSQL NSS PGSQL
${db}_VARS_OFF=	APU_CONF_ARGS+=--without-${db:tl}
.endfor

APR_CONF_ENV+=	${CONFIGURE_ENV:O:u} CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"
# include apu specific CPPFLAGS 1st!
APU_CONF_ENV+=	${CONFIGURE_ENV:O:u} CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${APU_CPPFLAGS} ${CPPFLAGS}"

.include <bsd.port.options.mk>

# crypto (apache24)
.if ${PORT_OPTIONS:MSSL} || ${PORT_OPTIONS:MNSS}
APU_CONF_ARGS+=	--with-crypto
.else
APU_CONF_ARGS+=	--without-crypto
.endif

post-extract:
# cleanup files not used on this platform
	@${FIND} ${WRKDIR} -type f \( -name 'NWGNU*' -o -name '*.ds?' -o -name '*.dep' -o -name '*.mak' -o -name '*.win' \) -delete

post-patch:
	@${REINPLACE_CMD} -e 's/OSVERSION/${OSVERSION}/g' \
		${APR_WRKDIR}/configure
	@${REINPLACE_CMD} -e '/recursive:/s/$$/ .MAKE/' \
		${APR_WRKDIR}/build/apr_rules.mk.in

do-configure:
	@${ECHO_MSG} "# ===> ${.TARGET} apr-${APR_VERSION}"
	(cd ${APR_WRKDIR} && \
		${SETENV} ${APR_CONF_ENV} ./configure ${APR_CONF_ARGS} ${CONFIGURE_ARGS})
	@${ECHO_MSG} "# ===> ${.TARGET} apr-util-${APU_VERSION}"
	(cd ${APU_WRKDIR} && \
		${SETENV} ${APU_CONF_ENV} ./configure ${APU_CONF_ARGS} ${CONFIGURE_ARGS})

do-build:
	@${ECHO_MSG} "# ===> ${.TARGET} apr-${APR_VERSION}"
	(cd ${APR_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS})
	@${ECHO_MSG} "# ===> ${.TARGET} apr-util-${APU_VERSION}"
	(cd ${APU_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS})

pre-install:
# always create the modules directory
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/apr-util-1
	${ECHO} "keep me" > ${STAGEDIR}${PREFIX}/lib/apr-util-1/.keep.me

do-install:
	@${ECHO_MSG} "# ===> ${.TARGET} apr-${APR_VERSION}"
	(cd ${APR_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${INSTALL_TARGET} ${MAKE_ARGS})
	@${ECHO_MSG} "# ===> ${.TARGET} apr-util-${APU_VERSION}"
	(cd ${APU_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${INSTALL_TARGET} ${MAKE_ARGS})

	-${FIND} ${STAGEDIR}${PREFIX}/lib/ -name \*.so | ${XARGS} ${STRIP_CMD}

do-test:
	@${ECHO_MSG} "# ===> ${.TARGET} apr-${APR_VERSION}"
	-(cd ${APR_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test)
	@${ECHO_MSG} "# ===> ${.TARGET} apr-util-${APU_VERSION}"
	-(cd ${APU_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test)

#regression-test: test

rpfl: configure
# maintainer only: strip PID from logs (better compare)
	${SED} -i '' -E 's|^configure:[0-9]+:|configure:_pid_:|g' ${APR_WRKDIR}/config.log
	${SED} -i '' -E 's|^configure:[0-9]+:|configure:_pid_:|g' ${APU_WRKDIR}/config.log

.include <bsd.port.mk>
