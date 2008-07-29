# New ports collection makefile for: apr
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#
# Tunables:
# APR_UTIL_WITHOUT_THREADS:	disable threads support
# APR_UTIL_WITH_GDBM:		force dependency on the GNU dbm
# APR_UTIL_WITHOUT_GDBM:	unconditionally disable the use of GNU dbm
# APR_UTIL_WITH_BERKELEY_DB:	force dependency on Sleepycat's Berkeley DB 4.2
# APR_UTIL_WITHOUT_BERKELEY_DB:	unconditionally disable the use of db4.2
# (the database bindings are detected and recorded automatically if these
# switches are not set)
# APR_UTIL_WITH_LDAP:		force dependency on OpenLDAP

PORTNAME=	apr
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	apr
DISTFILES=	apr-${PORTVERSION}.tar.gz apr-util-${PORTVERSION}.tar.gz

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	The Apache Group's Portability Library

LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2

USE_ICONV=		yes
USE_AUTOTOOLS=	automake:19 autoconf:261 libtool:15:env
USE_PERL5_BUILD=	yes
USE_GMAKE=		yes
USE_PYTHON_BUILD=	yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
WRKSRC=	${WRKDIR}

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
SHLIB_MAJOR=	3

APR_UTIL_CONF_ARGS=	--with-apr=../apr-${PORTVERSION} \
			--with-expat=${LOCALBASE} \
			--with-iconv=${LOCALBASE}

.include <bsd.port.pre.mk>

.if defined(APR_UTIL_WITHOUT_THREADS)
CONFIGURE_ARGS+=	--disable-threads
APR_UTIL_CONF_ARGS+=	--disable-threads
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nothr
.else
PKGNAMESUFFIX=	-nothr
.endif
.else
CONFIGURE_ARGS+=	--enable-threads
.endif

.if defined(APR_UTIL_WITHOUT_GDBM)
APR_UTIL_CONF_ARGS+=	--without-gdbm
.elif defined(APR_UTIL_WITH_GDBM) || exists(${LOCALBASE}/lib/libgdbm.so.3)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
APR_UTIL_CONF_ARGS+=	--with-gdbm=${LOCALBASE}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gdbm
.else
PKGNAMESUFFIX=	-gdbm
.endif
.else
APR_UTIL_CONF_ARGS+=	--without-gdbm
.endif

.if defined(WITH_BDB)
APR_UTIL_WITH_BERKELEY_DB=	yes
.endif

.if defined(APR_UTIL_WITHOUT_BERKELEY_DB)
APR_UTIL_CONF_ARGS+=	--without-berkeley-db
.elif defined(APR_UTIL_WITH_BERKELEY_DB) || exists(${LOCALBASE}/lib/libdb-4.2.so.2)
USE_BDB=	42+
APR_UTIL_CONF_ARGS+=	--with-berkeley-db=${BDB_INCLUDE_DIR}:${BDB_LIB_DIR}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
.else
PKGNAMESUFFIX=	-${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
.endif
.endif

.if defined(APR_UTIL_WITH_LDAP)
PLIST_SUB+=	LDAP=""
USE_OPENLDAP=	yes
APR_UTIL_CONF_ARGS+=	--with-ldap-include=${LOCALBASE}/include \
	--with-ldap-lib=${LOCALBASE}/lib --with-ldap=ldap
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ldap
.else
PKGNAMESUFFIX=	-ldap
.endif
.else
PLIST_SUB+=	LDAP="@comment "
.endif

pre-extract:
	@${ECHO_MSG} ""
.if defined(APR_UTIL_WITHOUT_THREADS)
	@${ECHO_MSG} "apr library will be built without threads support."
.else
	@${ECHO_MSG} "apr library will be built with threads support."
	@${ECHO_MSG} "All programs which use apr must be linked with threads too."
	@${ECHO_MSG} "You can disable threads by defining APR_UTIL_WITHOUT_THREADS."
.endif
	@${ECHO_MSG} ""
.if defined(APR_UTIL_WITHOUT_GDBM)
	@${ECHO_MSG} "GDBM support is disabled."
.elif defined(APR_UTIL_WITH_GDBM)
	@${ECHO_MSG} "GDBM support is forced."
.elif exists(${LOCALBASE}/lib/libgdbm.so.3)
	@${ECHO_MSG} "GDBM support is enabled."
	@${ECHO_MSG} "You can disable GDBM support by defining APR_UTIL_WITHOUT_GDBM."
.else
	@${ECHO_MSG} "GDBM was not found."
	@${ECHO_MSG} "You can force GDBM support by defining APR_UTIL_WITH_GDBM."
.endif
	@${ECHO_MSG} ""
.if defined(APR_UTIL_WITHOUT_BERKELEY_DB)
	@${ECHO_MSG} "Berkeley DB support is disabled."
.elif defined(APR_UTIL_WITH_BERKELEY_DB)
	@${ECHO_MSG} "Berkeley DB support forced."
.elif exists(${LOCALBASE}/lib/libdb-4.2.so.2)
	@${ECHO_MSG} "Berkeley db4.2 support is enabled."
	@${ECHO_MSG} "You can disable Berkeley db4.2 support by defining APR_UTIL_WITHOUT_BERKELEY_DB."
.else
	@${ECHO_MSG} "Berkeley DB was not found."
	@${ECHO_MSG} "You can force Berkeley DB support by defining APR_UTIL_WITH_BERKELEY_DB."
.endif
	@${ECHO_MSG} ""

post-patch:
	${REINPLACE_CMD} -e 's/OSVERSION/'${OSVERSION}'/g' \
		${WRKDIR}/apr-${PORTVERSION}/build/apr_hints.m4
	${FIND} ${WRKDIR} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

pre-configure:
.for d in apr apr-util
.for f in config.guess config.sub
	${CP} -f ${TEMPLATES}/${f} ${WRKDIR}/${d}-${PORTVERSION}/build/${f}
	${CHMOD} a+rx ${WRKDIR}/${d}-${PORTVERSION}/build/${f}
.endfor
.endfor

run-autotools::
	cd ${WRKDIR}/apr-${PORTVERSION} ; \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf
	cd ${WRKDIR}/apr-util-${PORTVERSION} ; \
		${RM} -fr xml/expat
	cd ${WRKDIR}/apr-util-${PORTVERSION} ; \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./buildconf \
		--with-apr=../apr-${PORTVERSION}
	cd ${WRKDIR}/apr-${PORTVERSION}; \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; \
		${SETENV} ${CONFIGURE_ENV} ${SH} \
		./configure ${CONFIGURE_ARGS} ${APR_UTIL_CONF_ARGS}

do-configure:
	${DO_NADA}

do-build:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${INSTALL_TARGET}

debug_autoconf:
	@echo "LIBTOOL: ${LIBTOOL_VERSION}"
	@echo "AUTOCONF: dev ${dev_acver} cur ${cur_acver} use ${use_acver}"
	@echo "AUTOMAKE: dev ${dev_amver} cur ${cur_amver} use ${use_amver}"
	@echo "AUTOCONF_DIR: ${AUTOCONF_DIR}"
	@echo "BUILD_DEPENDS: ${BUILD_DEPENDS}"
	@echo "ACLOCAL_DIR: ${ACLOCAL_DIR}"
	@echo "LIBTOOLFILES: ${LIBTOOLFILES}"
	@echo "LIBTOOL_SHAREDIR: ${LIBTOOL_SHAREDIR}"
	@echo "LIBTOOL_LIBEXECDIR: ${LIBTOOL_LIBEXECDIR}"
	@echo "LIBTOOL_M4: ${LIBTOOL_M4}"

.include <bsd.port.post.mk>
