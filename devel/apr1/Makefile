# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	${APR_VERSION}.${APU_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	apr
DISTFILES=	apr-${APR_VERSION}.tar.gz apr-util-${APU_VERSION}.tar.gz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2


OPTIONS_GROUP=		APR APU
OPTIONS_GROUP_APR=	THREADS IPV6 DEVRANDOM
OPTIONS_GROUP_APU=	BDB GDBM LDAP MYSQL NDBM PGSQL SQLITE FREETDS
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SSL NSS
OPTIONS_DEFAULT=	THREADS IPV6 DEVRANDOM BDB GDBM SSL

DEVRANDOM_DESC=	Use /dev/random or compatible
NDBM_DESC=	NDBM support
SSL_DESC=	OpenSSL crypto driver
NSS_DESC=	NSS crypto driver

APR_VERSION=	1.5.0
APU_VERSION=	1.5.3

USES=		iconv pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

NO_WRKSUBDIR=	yes
APR_WRKDIR=	${WRKDIR}/apr-${APR_VERSION}
APU_WRKDIR=	${WRKDIR}/apr-util-${APU_VERSION}

PLIST_SUB+=	SHLIB_APR_MAJOR="${SHLIB_APR_MAJOR}" SHLIB_APU_MAJOR="${SHLIB_APU_MAJOR}"
SHLIB_APR_MAJOR=	5
SHLIB_APU_MAJOR=	5

APR_CONF_ARGS=	--with-installbuilddir=${DATADIR}/build-1
APU_CONF_ARGS=	--with-apr=${APR_WRKDIR} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${ICONV_PREFIX}

.include <bsd.port.options.mk>

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
LIB_DEPENDS+=	libgdbm.so:${PORTSDIR}/databases/gdbm
APU_CONF_ARGS+=	--with-gdbm=${LOCALBASE}
.else
PLIST_SUB+=	GDBM="@comment "
APU_CONF_ARGS+=	--without-gdbm
.endif

.if ${PORT_OPTIONS:MBDB}
APU_EXTRAS=	yes
PLIST_SUB+=	BDB=""
USE_BDB=	48+
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
LIB_DEPENDS+=	libsybdb.so:${PORTSDIR}/databases/freetds
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
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
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
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
APU_CONF_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
PLIST_SUB+=	SSL="@comment "
APU_CONF_ARGS+=	--without-openssl
.endif

.if ${PORT_OPTIONS:MNSS}
APU_EXTRAS=	yes
PLIST_SUB+=	NSS=""
LIB_DEPENDS+=	libnss3.so:${PORTSDIR}/security/nss
CPPFLAGS+=	-I${LOCALBASE}/include/nss
LDFLAGS+=	-L${LOCALBASE}/lib/nss
APU_CONF_ARGS+=	--with-nss=${LOCALBASE}
.else
PLIST_SUB+=	NSS="@comment "
.endif

CONFIGURE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

.if defined(APU_EXTRAS)
PLIST_SUB+=	APU_EXTRAS=""
.else
PLIST_SUB+=	APU_EXTRAS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/OSVERSION/${OSVERSION}/g' \
		${APR_WRKDIR}/configure
	@${REINPLACE_CMD} -e '/recursive:/s/$$/ .MAKE/' \
		${APR_WRKDIR}/build/apr_rules.mk.in
# Fix pthread: Please do not remove, else apr-1-config returns wrong values
	@${REINPLACE_CMD} -e 's/-lpthread/-pthread/g' \
		${APR_WRKDIR}/configure

do-configure:
	@(cd ${APR_WRKDIR} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} ${APR_CONF_ARGS})
	@(cd ${APU_WRKDIR} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} ${APU_CONF_ARGS})

do-build:
	@(cd ${APR_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS})
	@(cd ${APU_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS})

do-install:
	@(cd ${APR_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET} ${MAKE_ARGS})
	@(cd ${APU_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET} ${MAKE_ARGS})

test: build
	-@(cd ${APR_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} test)
	-@(cd ${APU_WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} test)

#regression-test: test

.include <bsd.port.mk>
