# New ports collection makefile for: apr
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	${APR_VERSION}.${APU_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	apr
DISTFILES=	apr-${APR_VERSION}.tar.gz apr-util-${APU_VERSION}.tar.gz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2

MAKE_JOBS_SAFE=	yes

OPTIONS=	THREADS "Enable Threads in apr"						on  \
			IPV6	"Enable IPV6 Support in apr"				on	\
			GDBM	"Enable GNU dbm support in apr-util"		on  \
			BDB		"Enable Berkley BDB support in apr-util"	on  \
			NDBM	"Enable NDBM support in apr-util"			off \
			LDAP	"Enable LDAP support in apr-util"			off \
			MYSQL	"Enable MySQL suport in apr-util"			off \
			PGSQL	"Enable Postgresql suport in apr-util"		off \
			SQLITE  "Enable SQLite3 support in apr-util"			off

APR_VERSION=	1.3.9
APU_VERSION=	1.3.9

USE_ICONV=		yes
USE_AUTOTOOLS=	automake:19 autoconf:262 libtool:22:env
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

NO_WRKSUBDIR=	yes
APR_WRKDIR=	${WRKDIR}/apr-${APR_VERSION}
APU_WRKDIR=	${WRKDIR}/apr-util-${APU_VERSION}

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
SHLIB_MAJOR=	3

APR_CONF_ARGS=	--with-installbuilddir=${DATADIR}/build-1
APU_CONF_ARGS=	--with-apr=${APR_WRKDIR} \
			--with-expat=${LOCALBASE} \
			--with-iconv=${LOCALBASE}

.include <bsd.port.options.mk>

########## APR Options
.if defined(WITHOUT_THREADS)
APR_CONF_ARGS+=	--disable-threads
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nothr
.else
PKGNAMESUFFIX=	-nothr
.endif
.else
APR_CONF_ARGS+=	--enable-threads
.endif

.if defined(WITHOUT_IPV6)
APR_CONF_ARGS+=	--disable-ipv6
.else
APR_CONF_ARGS+=	--enable-ipv6
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ipv6
.else
PKGNAMESUFFIX=	-ipv6
.endif
.endif

######### APR-Util Options
.if defined(WITHOUT_GDBM)
PLIST_SUB+=	GDBM="@comment "
APU_CONF_ARGS+=	--without-gdbm
.elif defined(WITH_GDBM)
PLIST_SUB+=	GDBM=""
APU_EXTRAS=	yes
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
APU_CONF_ARGS+=	--with-gdbm=${LOCALBASE}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gdbm
.else
PKGNAMESUFFIX=	-gdbm
.endif
.else
PLIST_SUB+=	GDBM="@comment "
APR_UTIL_CONF_ARGS+=	--without-gdbm
.endif

.if defined(WITHOUT_BDB)
PLIST_SUB+=	BDB="@comment "
APU_CONF_ARGS+=	--without-berkeley-db
.elif defined(WITH_BDB)
APU_EXTRAS=	yes
PLIST_SUB+=	BDB=""
USE_BDB=	42+
APU_CONF_ARGS+=	--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
.else
PKGNAMESUFFIX=	-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
.endif
.endif

.if defined(WITHOUT_NDBM)
PLIST_SUB+=	NDBM="@comment "
APU_CONF_ARGS+=	--without-ndbm
.elif defined(WITH_NDBM)
APU_EXTRAS=	yes
PLIST_SUB+=	NDBM=""
APU_CONF_ARGS+=	--with-ndbm=/usr
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ndbm
.else
PKGNAMESUFFIX=	-ndbm
.endif
.endif

.if defined(WITH_LDAP)
APU_EXTRAS=	yes
PLIST_SUB+=	LDAP=""
USE_OPENLDAP=	yes
APU_CONF_ARGS+=	--with-ldap-include=${LOCALBASE}/include \
	--with-ldap-lib=${LOCALBASE}/lib --with-ldap=ldap
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ldap
.else
PKGNAMESUFFIX=	-ldap
.endif
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if defined(WITH_MYSQL)
APU_EXTRAS=	yes
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	YES
APU_CONF_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_ENV+=	LIBS="${LIBS}"
CFLAGS+=	-I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-mysql
.else
PKGNAMESUFFIX=	-mysql
.endif
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
APU_EXTRAS=	yes
PLIST_SUB+=	PGSQL=""
USE_PGSQL=	YES
APU_CONF_ARGS+=	--with-pgsql=${LOCALBASE}
CONFIGURE_ENV+=	ac_cv_path_PGSQL_CONFIG=""
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-pgsql
.else
PKGNAMESUFFIX=	-pgsql
.endif
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
APU_EXTRAS=	yes
PLIST_SUB+=	SQLITE3=""
USE_SQLITE=	YES
CONFIGURE_ARGS+= --with-sqlite3=${LOCALBASE}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-sqlite3
.else
PKGNAMESUFFIX=	-sqlite3
.endif
.else
CONFIGURE_ARGS+= --without-sqlite3
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if defined(APU_EXTRAS)
PLIST_SUB+=	APU_EXTRAS=""
.else
PLIST_SUB+=	APU_EXTRAS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's/OSVERSION/'${OSVERSION}'/g' \
		${APR_WRKDIR}/build/apr_hints.m4
	${FIND} ${APR_WRKDIR} ${APU_WRKDIR} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g' \
		${APR_WRKDIR}/build/apr_threads.m4 ${APR_WRKDIR}/build/apr_hints.m4 \
		${APU_WRKDIR}/build/apu-conf.m4 

run-autotools::
	cd ${APR_WRKDIR} ; \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf
	cd ${APU_WRKDIR} ; \
		${RM} -fr xml/expat
	cd ${APU_WRKDIR} ; \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf \
		--with-apr=${APR_WRKDIR}
	cd ${APR_WRKDIR}; \
		${SETENV} ${CONFIGURE_ENV} ${SH} \
		./configure ${CONFIGURE_ARGS} ${APR_CONF_ARGS}
	cd ${APU_WRKDIR}; \
		${SETENV} ${CONFIGURE_ENV} ${SH} \
		./configure ${CONFIGURE_ARGS} ${APU_CONF_ARGS}

do-configure:
	${DO_NADA}

do-build:
	cd ${APR_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${APU_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	cd ${APR_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
	cd ${APU_WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}

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
	@${ECHO} "${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS} ${APR_UTIL_CONF_ARGS}"

.include <bsd.port.mk>
