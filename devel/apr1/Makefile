# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	${APR_VERSION}.${APU_VERSION}
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	apr
DISTFILES=	apr-${APR_VERSION}.tar.gz apr-util-${APU_VERSION}.tar.gz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

MAKE_JOBS_SAFE=	yes

NO_OPTIONS_SORT=yes
OPTIONS_GROUP=		APR APU
OPTIONS_GROUP_APR=	THREADS IPV6 DEVRANDOM
OPTIONS_GROUP_APU=	BDB GDBM LDAP MYSQL NDBM PGSQL SQLITE FREETDS
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SSL
OPTIONS_DEFAULT=	THREADS IPV6 DEVRANDOM BDB GDBM SSL

DEVRANDOM_DESC=	Use /dev/random or compatible
NDBM_DESC=	NDBM support
SSL_DESC=	OpenSSL crypto driver
NSS_DESC=	NSS crypto driver

.include <bsd.port.options.mk>

APR_VERSION=	1.4.6
APU_VERSION=	1.4.1

USE_ICONV=		yes
USE_AUTOTOOLS=	automake autoconf libtool:env
USE_PYTHON_BUILD=	-2.7
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV=	CC="${CC}"

NO_WRKSUBDIR=	yes
APR_WRKDIR=	${WRKDIR}/apr-${APR_VERSION}
APU_WRKDIR=	${WRKDIR}/apr-util-${APU_VERSION}

PLIST_SUB=	SHLIB_APR_MAJOR="${SHLIB_APR_MAJOR}" SHLIB_APU_MAJOR="${SHLIB_APU_MAJOR}"
SHLIB_APR_MAJOR=	4
SHLIB_APU_MAJOR=	4

APR_CONF_ARGS=	--with-installbuilddir=${DATADIR}/build-1
APU_CONF_ARGS=	--with-apr=${APR_WRKDIR} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${LOCALBASE}

########## APR Options
.if ${PORT_OPTIONS:MTHREADS}
APR_CONF_ARGS+=	--enable-threads
.else
APR_CONF_ARGS+=	--disable-threads
.endif

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
.if ${PORT_OPTIONS:MGDBM}
PLIST_SUB+=	GDBM=""
APU_EXTRAS=	yes
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
APU_CONF_ARGS+=	--with-gdbm=${LOCALBASE}
.else
PLIST_SUB+=	GDBM="@comment "
APU_CONF_ARGS+=	--without-gdbm
.endif

.if ${PORT_OPTIONS:MBDB}
APU_EXTRAS=	yes
PLIST_SUB+=	BDB=""
USE_BDB=	42+
APU_CONF_ARGS+=	--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
.else
PLIST_SUB+=	BDB="@comment "
APU_CONF_ARGS+=	--without-berkeley-db
.endif

.if ${PORT_OPTIONS:MNDBM}
APU_EXTRAS=	yes
PLIST_SUB+=	NDBM=""
APU_CONF_ARGS+=	--with-ndbm=/usr
.else
PLIST_SUB+=	NDBM="@comment "
APU_CONF_ARGS+=	--without-ndbm
.endif

.if ${PORT_OPTIONS:MLDAP}
APU_EXTRAS=	yes
PLIST_SUB+=	LDAP=""
USE_OPENLDAP=	yes
APU_CONF_ARGS+=	--with-ldap-include=${LOCALBASE}/include \
	--with-ldap-lib=${LOCALBASE}/lib --with-ldap=ldap
.else
PLIST_SUB+=	LDAP="@comment "
APU_CONF_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MFREETDS}
APU_EXTRAS=	yes
PLIST_SUB+=	FREETDS=""
APU_CONF_ARGS+=	--with-freetds=${LOCALBASE}
LIB_DEPENDS=	sybdb:${PORTSDIR}/databases/freetds
.else
PLIST_SUB+=	FREETDS="@comment "
APU_CONF_ARGS+=	--without-freetds
.endif

.if ${PORT_OPTIONS:MMYSQL}
APU_EXTRAS=	yes
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	YES
APU_CONF_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_ENV+=	LIBS="${LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
.else
PLIST_SUB+=	MYSQL="@comment "
APU_CONF_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
APU_EXTRAS=	yes
PLIST_SUB+=	PGSQL=""
USE_PGSQL=	YES
APU_CONF_ARGS+=	--with-pgsql=${LOCALBASE}
CONFIGURE_ENV+=	ac_cv_path_PGSQL_CONFIG=""
.else
PLIST_SUB+=	PGSQL="@comment "
APU_CONF_ARGS+=	--without-pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
APU_EXTRAS=	yes
PLIST_SUB+=	SQLITE3=""
USE_SQLITE=	YES
APU_CONF_ARGS+=	--with-sqlite3=${LOCALBASE}
.else
APU_CONF_ARGS+=	--without-sqlite3
PLIST_SUB+=	SQLITE3="@comment "
.endif

# crypto (apache24)
.if ${PORT_OPTIONS:MSSL} || ${PORT_OPTIONS:MNSS}
APU_CONF_ARGS+=	--with-crypto
.endif

.if ${PORT_OPTIONS:MSSL}
APU_EXTRAS=	yes
USE_OPENSSL=	yes
PLIST_SUB+=	SSL=""
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
APU_CONF_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
PLIST_SUB+=	SSL="@comment "
APU_CONF_ARGS+=	--without-openssl
.endif

# TODO figure out why nss flag is ignored if ssl is set
# this works on other OS as expected
.if ${PORT_OPTIONS:MNSS}
APU_EXTRAS=	yes
PLIST_SUB+=	NSS=""
LIB_DEPENDS+=	nss3:${PORTSDIR}/security/nss
CFLAGS+=	-I${LOCALBASE}/include/nss
LDFLAGS+=	-L${LOCALBASE}/lib/nss
APU_CONF_ARGS+=	--with-nss=${LOCALBASE}
.else
PLIST_SUB+=	NSS="@comment "
.endif

.if defined(APU_EXTRAS)
PLIST_SUB+=	APU_EXTRAS=""
.else
PLIST_SUB+=	APU_EXTRAS="@comment "
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's/OSVERSION/${OSVERSION}/g' \
		${APR_WRKDIR}/build/apr_hints.m4
	${FIND} ${APR_WRKDIR} ${APU_WRKDIR} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g' \
		${APR_WRKDIR}/build/apr_threads.m4 ${APR_WRKDIR}/build/apr_hints.m4 \
		${APU_WRKDIR}/build/apu-conf.m4
	${REINPLACE_CMD} -e '1 s/python/${PYTHON_VERSION}/' \
		${APR_WRKDIR}/build/gen-build.py
	${REINPLACE_CMD} -e 's/void main/int main/' ${APR_WRKDIR}/build/apr_network.m4

run-autotools::
	cd ${APR_WRKDIR} ; \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf
	cd ${APU_WRKDIR} ; \
		${RM} -fr xml/expat
	cd ${APU_WRKDIR} ; \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf \
		--with-apr=${APR_WRKDIR}
	${REINPLACE_CMD} -e 's/ gsed//g' \
		${APR_WRKDIR}/build/libtool.m4 \
		${APR_WRKDIR}/configure
	cd ${APR_WRKDIR}; \
		${SETENV} ${CONFIGURE_ENV} ${SH} \
		./configure ${CONFIGURE_ARGS} ${APR_CONF_ARGS}
	cd ${APU_WRKDIR}; \
		${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" ${SH} \
		./configure ${CONFIGURE_ARGS} ${APU_CONF_ARGS}

do-configure:
	${DO_NADA}

do-build:
	cd ${APR_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${APU_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	cd ${APR_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
	cd ${APU_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}

test: build
	-@(cd ${APR_WRKDIR}; ${MAKE} test)
	-@(cd ${APU_WRKDIR}; ${MAKE} test)

#regression-test: test

debug_autoconf:
	@${ECHO} "LIBTOOL: ${LIBTOOL_VERSION}"
	@${ECHO} "AUTOCONF: dev ${dev_acver} cur ${cur_acver} use ${use_acver}"
	@${ECHO} "AUTOMAKE: dev ${dev_amver} cur ${cur_amver} use ${use_amver}"
	@${ECHO} "AUTOCONF_DIR: ${AUTOCONF_DIR}"
	@${ECHO} "BUILD_DEPENDS: ${BUILD_DEPENDS}"
	@${ECHO} "ACLOCAL_DIR: ${ACLOCAL_DIR}"
	@${ECHO} "LIBTOOLFILES: ${LIBTOOLFILES}"
	@${ECHO} "LIBTOOL_SHAREDIR: ${LIBTOOL_SHAREDIR}"
	@${ECHO} "LIBTOOL_LIBEXECDIR: ${LIBTOOL_LIBEXECDIR}"
	@${ECHO} "LIBTOOL_M4: ${LIBTOOL_M4}"
	@${ECHO} "${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS} ${APR_CONF_ARGS}"
	@${ECHO} "${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" ${SH} ./configure ${CONFIGURE_ARGS} ${APR_UTIL_CONF_ARGS}"

.include <bsd.port.mk>
