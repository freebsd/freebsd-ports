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
# WITH_PYTHON:                  force dependency on Python and run APR's buildconf.
# Really only needed if built from APR's CVS depot.

PORTNAME=	apr
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	apr
DISTFILES=	apr-${PORTVERSION}.tar.gz apr-util-${PORTVERSION}.tar.gz

MAINTAINER=	rodrigc@crodrigues.org
COMMENT=	The Apache Group's Portability Library

.if defined(WITH_PYTHON)
BUILD_DEPENDS=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
USE_PYTHON=		yes
PYTHON_NO_DEPENDS=	yes
.endif

LIB_DEPENDS+=	expat.5:${PORTSDIR}/textproc/expat2

USE_ICONV=		yes
USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259
WANT_LIBTOOL_VER=	15
USE_REINPLACE=		yes
USE_PERL5=		yes
USE_GMAKE=		yes
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
WRKSRC=	${WRKDIR}

APR_UTIL_CONF_ARGS=	--with-apr=../apr-${PORTVERSION} \
			--with-expat=${PREFIX} \
			--with-iconv=${PREFIX}

.include <bsd.port.pre.mk>

.if defined(APR_UTIL_WITHOUT_THREADS)
CONFIGURE_ARGS+=	--disable-threads
APR_UTIL_CONF_ARGS+=	--disable-threads
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-nothr
.else
PKGNAMESUFFIX=	-nothr
.endif
.endif

.if defined(APR_UTIL_WITHOUT_GDBM)
APR_UTIL_CONF_ARGS+=	--without-gdbm
.elif defined(APR_UTIL_WITH_GDBM) || exists(${LOCALBASE}/lib/libgdbm.so.3)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gdbm
.else
PKGNAMESUFFIX=	-gdbm
.endif
.endif

.if defined(APR_UTIL_WITHOUT_BERKELEY_DB)
APR_UTIL_CONF_ARGS+=	--without-berkeley-db
.elif defined(APR_UTIL_WITH_BERKELEY_DB) || exists(${LOCALBASE}/lib/libdb-4.2.so.2)
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
APR_UTIL_CONF_ARGS+=	--with-berkeley-db=${PREFIX}
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-db4
.else
PKGNAMESUFFIX=	-db4
.endif
.endif

.if defined(APR_UTIL_WITH_LDAP)
USE_OPENLDAP=	yes
APR_UTIL_CONF_ARGS+=	--with-ldap-include=${PREFIX}/include \
	--with-ldap-lib=${PREFIX}/lib --with-ldap=ldap
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-ldap
.else
PKGNAMESUFFIX=	-ldap
.endif
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
	@${ECHO_MSG} "Berkeley db4.2 support is disabled."
.elif defined(APR_UTIL_WITH_BERKELEY_DB)
	@${ECHO_MSG} "Berkeley db4.2 support forced."
.elif exists(${LOCALBASE}/lib/libdb-4.2.so.2)
	@${ECHO_MSG} "Berkeley db4.2 support is enabled."
	@${ECHO_MSG} "You can disable Berkeley db4.2 support by defining APR_UTIL_WITHOUT_BERKELEY_DB."
.else
	@${ECHO_MSG} "Berkeley db4.2 was not found."
	@${ECHO_MSG} "You can force Berkeley db4.2 support by defining APR_UTIL_WITH_BERKELEY_DB."
.endif
	@${ECHO_MSG} ""

post-patch:
	${SED} -i .orig1 's/OSVERSION/'${OSVERSION}'/g' \
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

run-autotools:
.if defined(WITH_PYTHON)
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${SCRIPTS_ENV} ${SH} ./buildconf
	cd ${WRKDIR}/apr-util-${PORTVERSION} ; \
	${RM} -fr xml/expat
	cd ${WRKDIR}/apr-util-${PORTVERSION} ; \
		${SETENV} ${SCRIPTS_ENV} ${SH} ./buildconf \
		--with-apr=../apr-${PORTVERSION}
.endif
	cd ${WRKDIR}/apr-${PORTVERSION}; \
		${SETENV} ${SCRIPTS_ENV} ${SH} ./configure ${CONFIGURE_ARGS}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; \
		${SETENV} ${SCRIPTS_ENV} ${SH} \
		./configure ${CONFIGURE_ARGS} ${APR_UTIL_CONF_ARGS}

do-configure:
	${DO_NADA}

do-build:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE} install
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE} install

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
