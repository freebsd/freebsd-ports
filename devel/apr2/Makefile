# New ports collection makefile for: apr
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	${APR_VERSION}.${APU_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://svn.apache.org/snapshots/apr/ 
DISTNAME=	${PORTNAME}_${SNAPDATE}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

NO_LATEST_LINK= yes

SNAPDATE= 20100527031346

MAKE_JOBS_SAFE=	yes

OPTIONS=	THREADS "Enable Threads in apr"				on  \
		IPV6	"Enable IPV6 Support in apr"			on  \
		BDB	"Enable Berkley BDB support in apr-util"	on  \
		GDBM	"Enable GNU dbm support in apr-util"		on  \
		LDAP	"Enable LDAP support in apr-util"		off \
		MYSQL	"Enable MySQL suport in apr-util"		off \
		NDBM	"Enable NDBM support in apr-util"		off \
		PGSQL	"Enable Postgresql suport in apr-util"		off \
		SQLITE  "Enable SQLite3 support in apr-util"		off \
		DEVRANDOM "Use /dev/random or compatible in apr"	on \
		DEVELOPER_ONLY "I want to test apr2 not the maintainer" off

USE_ICONV=		yes
USE_AUTOTOOLS=	automake:19 autoconf:262 libtool:22:env
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	-2.6
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV=	CC="${CC}"

CONFIGURE_ARGS=	--with-installbuilddir=${DATADIR}/build-2 \
	--with-expat=${LOCALBASE} \
	--with-iconv=${LOCALBASE}

WRKSRC=	${WRKDIR}/apr

SHLIB_MAJOR=	0
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.include <bsd.port.options.mk>

.if !defined(WITH_DEVELOPER_ONLY)
IGNORE=	not for the general public. Maintainer only supports developers of apr
.endif

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--disable-threads
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nothr
.else
PKGNAMESUFFIX=	-nothr
.endif
.else
CONFIGURE_ARGS+=	--enable-threads
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.else
CONFIGURE_ARGS+=	--enable-ipv6
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ipv6
.else
PKGNAMESUFFIX=	-ipv6
.endif
.endif

.if defined(WITHOUT_DEVRANDOM)
CONFIGURE_ARGS+=	--without-devrandom
.else
CONFIGURE_ARGS+=	--with-devrandom
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-devrandom
.else
PKGNAMESUFFIX=	-devrandom
.endif
.endif

######### APR-Util Options
.if defined(WITHOUT_GDBM)
PLIST_SUB+=	GDBM="@comment "
CONFIGURE_ARGS+=	--without-gdbm
.else
PLIST_SUB+=	GDBM=""
EXTRAS=	yes
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm=${LOCALBASE}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gdbm
.else
PKGNAMESUFFIX=	-gdbm
.endif
.endif

.if defined(WITHOUT_BDB)
PLIST_SUB+=	BDB="@comment "
CONFIGURE_ARGS+=	--without-berkeley-db
.else
EXTRAS=	yes
PLIST_SUB+=	BDB=""
USE_BDB=	42+
CONFIGURE_ARGS+=	--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
.else
PKGNAMESUFFIX=	-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
.endif
.endif

.if defined(WITH_NDBM)
EXTRAS=	yes
PLIST_SUB+=	NDBM=""
CONFIGURE_ARGS+=	--with-ndbm=/usr
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ndbm
.else
PKGNAMESUFFIX=	-ndbm
.endif
.else
PLIST_SUB+=	NDBM="@comment "
CONFIGURE_ARGS+=	--without-ndbm
.endif

.if defined(WITH_LDAP)
EXTRAS=	yes
PLIST_SUB+=	LDAP=""
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap-include=${LOCALBASE}/include \
	--with-ldap-lib=${LOCALBASE}/lib --with-ldap=ldap
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ldap${OPENLDAP_VER}
.else
PKGNAMESUFFIX=	-ldap
.endif
.else
PLIST_SUB+=	LDAP="@comment "
CONFIGURE_ARGS+=	--without-ldap
.endif

.if defined(WITH_MYSQL)
EXTRAS=	yes
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_ENV+=	LIBS="${LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-mysql${MYSQL_VER}
.else
PKGNAMESUFFIX=	-mysql
.endif
.else
PLIST_SUB+=	MYSQL="@comment "
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_PGSQL)
EXTRAS=	yes
PLIST_SUB+=	PGSQL=""
USE_PGSQL=	YES
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
CONFIGURE_ENV+=	ac_cv_path_PGSQL_CONFIG=""
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-pgsql${PGSQL_VER}
.else
PKGNAMESUFFIX=	-pgsql
.endif
.else
PLIST_SUB+=	PGSQL="@comment "
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if defined(WITH_SQLITE)
EXTRAS=	yes
PLIST_SUB+=	SQLITE3=""
USE_SQLITE=	YES
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-sqlite3
.else
PKGNAMESUFFIX=	-sqlite3
.endif
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if defined(EXTRAS)
PLIST_SUB+=	EXTRAS=""
.else
PLIST_SUB+=	EXTRAS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's/OSVERSION/${OSVERSION}/g' ${WRKSRC}/build/apr_hints.m4
	${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/build/apr_threads.m4 \
		${WRKSRC}/build/apr_hints.m4 \
		${WRKSRC}/build/apu-conf.m4
	${REINPLACE_CMD} -e '1 s/python/${PYTHON_VERSION}/' ${WRKSRC}/build/gen-build.py

run-autotools:
	@(cd ${WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf)

test:	build
	@(cd ${WRKSRC}; make test)

#regression-test:	test

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
	@${ECHO} "${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS} ${CONFIGURE_ARGS}"

.include <bsd.port.mk>
