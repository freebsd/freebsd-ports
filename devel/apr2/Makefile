# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$

PORTNAME=	apr
PORTVERSION=	2.0.${SNAPDATE}
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://svn-master.apache.org/snapshots/apr/
DISTNAME=	${PORTNAME}_${SNAPDATE}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache Portability Library

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

NO_LATEST_LINK=	yes

SNAPDATE=	20110821151329


NO_OPTIONS_SORT=yes
OPTIONS_DEFINE=	THREADS IPV6 DEVRANDOM BDB GDBM MYSQL NDBM PGSQL SQLITE DEVELOPER_ONLY
OPTIONS_DEFAULT=THREADS IPV6 DEVRANDOM BDB GDBM

NDBM_DESC=	NDBM support in apr-util
DEVRANDOM_DESC= Use /dev/random or compatible
DEVELOPER_ONLY_DESC=	I want to test apr2 not the maintainer

NO_STAGE=	yes
.include <bsd.port.options.mk>

USES=		iconv perl5
USE_AUTOTOOLS=	automake autoconf libtool:env
USE_PERL5=	build
USE_PYTHON_BUILD=	2
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV=	CC="${CC}"

CONFIGURE_ARGS=	--with-installbuilddir=${DATADIR}/build-2 \
	--with-expat=${LOCALBASE} \
	--with-iconv=${ICONV_PREFIX}

WRKSRC=	${WRKDIR}/apr

SHLIB_MAJOR=	0
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.if empty(PORT_OPTIONS:MDEVELOPER_ONLY)
IGNORE=	not for the general public. Maintainer only supports developers of apr
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nothr
. else
PKGNAMESUFFIX=	-nothr
. endif
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ipv6
. else
PKGNAMESUFFIX=	-ipv6
. endif
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MDEVRANDOM}
CONFIGURE_ARGS+=	--with-devrandom
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-devrandom
. else
PKGNAMESUFFIX=	-devrandom
. endif
.else
CONFIGURE_ARGS+=	--without-devrandom
.endif

######### APR-Util Options
.if ${PORT_OPTIONS:MGDBM}
PLIST_SUB+=	GDBM=""
EXTRAS=	yes
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm=${LOCALBASE}
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gdbm
. else
PKGNAMESUFFIX=	-gdbm
. endif
.else
PLIST_SUB+=	GDBM="@comment "
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if ${PORT_OPTIONS:MBDB}
EXTRAS=	yes
PLIST_SUB+=	BDB=""
USE_BDB=	42+
CONFIGURE_ARGS+=	--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
. else
PKGNAMESUFFIX=	-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
. endif
.else
PLIST_SUB+=	BDB="@comment "
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

.if ${PORT_OPTIONS:MNDBM}
EXTRAS=	yes
PLIST_SUB+=	NDBM=""
CONFIGURE_ARGS+=	--with-ndbm=/usr
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ndbm
. else
PKGNAMESUFFIX=	-ndbm
. endif
.else
PLIST_SUB+=	NDBM="@comment "
CONFIGURE_ARGS+=	--without-ndbm
.endif

.if ${PORT_OPTIONS:MMYSQL}
EXTRAS=	yes
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
CONFIGURE_ENV+=	LIBS="${LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-mysql${MYSQL_VER}
. else
PKGNAMESUFFIX=	-mysql
. endif
.else
PLIST_SUB+=	MYSQL="@comment "
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
EXTRAS=	yes
PLIST_SUB+=	PGSQL=""
USE_PGSQL=	YES
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
CONFIGURE_ENV+=	ac_cv_path_PGSQL_CONFIG=""
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-pgsql${PGSQL_VER}
. else
PKGNAMESUFFIX=	-pgsql
. endif
.else
PLIST_SUB+=	PGSQL="@comment "
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
EXTRAS=	yes
PLIST_SUB+=	SQLITE3=""
USE_SQLITE=	YES
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
. if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-sqlite3
. else
PKGNAMESUFFIX=	-sqlite3
. endif
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
