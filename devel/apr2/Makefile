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
# APR_UTIL_WITH_BERKELEY_DB:	force dependency on Sleepycat's Berkeley DB 4
# APR_UTIL_WITHOUT_BERKELEY_DB:	unconditionally disable the use of db4
# (the database bindings are detected and recorded automatically if these
# switches are not set)

PORTNAME=	apr
PORTVERSION=	0.9.4
PORTREVISION=	9
CATEGORIES=	devel
#MASTER_SITES=	http://www.apache.org/dist/apr/
#DISTFILES=	apr-${PORTVERSION}.tar.gz apr-util-${PORTVERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTFILES=	apr-APR_0_9_BRANCH_20040113112838.tar.gz apr-util-APU_0_9_BRANCH_20040113112849.tar.gz

MAINTAINER=	rodrigc@crodrigues.org
COMMENT=	The Apache Group's Portability Library

LIB_DEPENDS+=	expat.5:${PORTSDIR}/textproc/expat2

USE_ICONV=	yes
USE_AUTOCONF_VER=	257
USE_PERL5=		yes
USE_GMAKE=		yes
USE_LIBTOOL_VER=	15
LIBTOOLFILES=		# none
USE_AUTOMAKE_VER=	17
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
WRKSRC=	${WRKDIR}

APR_UTIL_CONF_ARGS=	--with-apr=../apr-${PORTVERSION} \
			--with-expat=${PREFIX} \
			--with-iconv=${PREFIX}

.include <bsd.port.pre.mk>

<<<<<<< Makefile
#.if ${OSVERSION} < 500000
#BROKEN=		"Configure fails on 4.x"
#.endif

=======
>>>>>>> 1.37
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
.elif defined(APR_UTIL_WITH_BERKELEY_DB) || exists(${LOCALBASE}/lib/libdb4.so.0)
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-db4
.else
PKGNAMESUFFIX=	-db4
.endif
.endif

LIBTOOL_M4=${LOCALBASE}/share/aclocal/libtool${USE_LIBTOOL_VER}.m4

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
	@${ECHO_MSG} "Berkeley db4 support is disabled."
.elif defined(APR_UTIL_WITH_BERKELEY_DB)
	@${ECHO_MSG} "Berkeley db4 support forced."
.elif exists(${LOCALBASE}/lib/libdb4.so.0)
	@${ECHO_MSG} "Berkeley db4 support is enabled."
	@${ECHO_MSG} "You can disable Berkeley db4 support by defining APR_UTIL_WITHOUT_BERKELEY_DB."
.else
	@${ECHO_MSG} "Berkeley db4 was not found."
	@${ECHO_MSG} "You can force Berkeley db4 support by defining APR_UTIL_WITH_BERKELEY_DB."
.endif
	@${ECHO_MSG} ""

post-extract:
	cd ${WRKDIR}; \
	${LN} -s apr-APR_0_9_BRANCH apr-${PORTVERSION}; \
	${LN} -s apr-util-APU_0_9_BRANCH apr-util-${PORTVERSION}

pre-configure:
	${DO_NADA}

run-autotools:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${SCRIPTS_ENV} AUTOCONF=${AUTOCONF} AUTOHEADER=${AUTOHEADER} LIBTOOL_M4=${LIBTOOL_M4} ${SH} ./buildconf
	cd ${WRKDIR}/apr-util-${PORTVERSION} ; \
	${RM} -fr xml/expat
	cd ${WRKDIR}/apr-util-${PORTVERSION} ; \
		${SETENV} ${SCRIPTS_EV} AUTOCONF=${AUTOCONF} AUTOHEADER=${AUTOHEADER} LIBTOOL_M4=${LIBTOOL_M4} ${SH} ./buildconf \
		--with-apr=../apr-${PORTVERSION}
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
