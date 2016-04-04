# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	${APR_VERSION}.${APU_VERSION}
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

APR_VERSION=	1.5.2
APU_VERSION=	1.5.4

CPE_VENDOR=	apache
CPE_PRODUCT=	apr-util
CPE_VERSION=	${APU_VERSION}

OPTIONS_SUB=		yes
OPTIONS_GROUP=		APR APU
OPTIONS_GROUP_APR=	IPV6 DEVRANDOM
OPTIONS_GROUP_APU=	BDB GDBM LDAP MYSQL NDBM PGSQL SQLITE FREETDS
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SSL NSS
OPTIONS_DEFAULT=	IPV6 DEVRANDOM BDB GDBM SSL

DEVRANDOM_DESC=		Use /dev/random or compatible
NDBM_DESC=		NDBM support
NSS_DESC=		NSS crypto driver
SSL_DESC=		OpenSSL crypto driver

# APR-Util Options
BDB_USE=		BDB=5+
FREETDS_LIB_DEPENDS=	libsybdb.so:databases/freetds
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
LDAP_USE=		OPENLDAP=yes
MYSQL_USE=		MYSQL=yes
NSS_LIB_DEPENDS=	libnss3.so:security/nss
PGSQL_USES=		pgsql
SQLITE_USES=		sqlite
SSL_USE=		OPENSSL=yes

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

.include <bsd.port.options.mk>

########## APR Options
.if ${PORT_OPTIONS:MIPV6}
APR_CONF_ARGS+=	--enable-ipv6
.else
APR_CONF_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MDEVRANDOM}
APR_CONF_ARGS+=	--with-devrandom
.else
APR_CONF_ARGS+=	--without-devrandom
.endif

######### APR-Util Options
# make sure 1st include is "${APR_WRKDIR}/include"
# to avoid failures if previous apr_version.h is present
APU_CPPFLAGS=	-I${APR_WRKDIR}/include

.if ${PORT_OPTIONS:MGDBM}
APU_CONF_ARGS+=	--with-gdbm=${LOCALBASE}
.else
APU_CONF_ARGS+=	--without-gdbm
.endif

.if ${PORT_OPTIONS:MBDB}
APU_CONF_ARGS+=	--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
.else
APU_CONF_ARGS+=	--without-berkeley-db
.endif

.if ${PORT_OPTIONS:MNDBM}
APU_CONF_ARGS+=	--with-ndbm=/usr
.else
APU_CONF_ARGS+=	--without-ndbm
.endif

.if ${PORT_OPTIONS:MLDAP}
APU_CONF_ARGS+=	--with-ldap-include=${LOCALBASE}/include \
		--with-ldap-lib=${LOCALBASE}/lib --with-ldap=ldap
.else
APU_CONF_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MFREETDS}
APU_CONF_ARGS+=	--with-freetds=${LOCALBASE}
.else
APU_CONF_ARGS+=	--without-freetds
.endif

.if ${PORT_OPTIONS:MMYSQL}
APU_CONF_ARGS+=	--with-mysql=${LOCALBASE}
APU_CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
LIBS+=		-L${LOCALBASE}/lib/mysql
.else
APU_CONF_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
APU_CONF_ARGS+=	--with-pgsql=${LOCALBASE}
APU_CONF_ENV+=	ac_cv_path_PGSQL_CONFIG=""
.else
APU_CONF_ARGS+=	--without-pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
APU_CONF_ARGS+=	--with-sqlite3=${LOCALBASE}
.else
APU_CONF_ARGS+=	--without-sqlite3
.endif

# crypto (apache24)
.if ${PORT_OPTIONS:MSSL} || ${PORT_OPTIONS:MNSS}
APU_CONF_ARGS+=	--with-crypto
.else
APU_CONF_ARGS+=	--without-crypto
.endif

.if ${PORT_OPTIONS:MSSL}
APU_CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
APU_CONF_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
APU_CONF_ARGS+=	--without-openssl
.endif

.if ${PORT_OPTIONS:MNSS}
APU_CPPFLAGS+=	-I${LOCALBASE}/include/nss
LDFLAGS+=	-L${LOCALBASE}/lib/nss
APU_CONF_ARGS+=	--with-nss=${LOCALBASE}
.else
APU_CONF_ARGS+=	--without-nss
.endif

APR_CONF_ENV+=	${CONFIGURE_ENV:O:u} CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"
# include apu specific CPPFLAGS 1st!
APU_CONF_ENV+=	${CONFIGURE_ENV:O:u} CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${APU_CPPFLAGS} ${CPPFLAGS}"

post-extract:
# cleanup files not used on this platform
	@${FIND} ${WRKSRC} -type f \( -name 'NWGNU*' -o -name '*.ds?' -o -name '*.dep' -o -name '*.mak' -o -name '*.win' \) -delete

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

post-install:
	-${FIND} ${STAGEDIR}${PREFIX}/lib/ -name \*.so | ${XARGS} ${STRIP_CMD}

test: build
	@${ECHO_MSG} "# ===> ${.TARGET} apr-${APR_VERSION}"
	-(cd ${APR_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test)
	@${ECHO_MSG} "# ===> ${.TARGET} apr-util-${APU_VERSION}"
	-(cd ${APU_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test)

#regression-test: test

rpfl: configure
# maintainer only: strip PID from logs (better compair)
	${SED} -i '' -E 's|^configure:[0-9]+:|configure:_pid_:|g' ${APR_WRKDIR}/config.log
	${SED} -i '' -E 's|^configure:[0-9]+:|configure:_pid_:|g' ${APU_WRKDIR}/config.log

.include <bsd.port.mk>
