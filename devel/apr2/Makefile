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
PORTREVISION=	8
CATEGORIES=	devel
#MASTER_SITES=	http://www.apache.org/dist/apr/
#DISTFILES=	apr-${PORTVERSION}.tar.gz apr-util-${PORTVERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTFILES=	apr-APR_0_9_BRANCH_20040113112838.tar.gz apr-util-APU_0_9_BRANCH_20040113112849.tar.gz

MAINTAINER=	rodrigc@crodrigues.org
COMMENT=	The Apache Group's Portability Library

LIB_DEPENDS+=	expat.4:${PORTSDIR}/textproc/expat2 \
		iconv.3:${PORTSDIR}/converters/libiconv

WANT_AUTOCONF_VER=	253

USE_PERL5=		yes
USE_GMAKE=		yes
USE_LIBTOOL_VER=	14
LIBTOOLFILES=		# none
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
WRKSRC=	${WRKDIR}

APR_CONF_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" ${CONFIGURE_ENV} \
		CONFIG_SHELL=/bin/sh

APR_UTIL_CONF_ENV=	\
		CC="${CC}" CFLAGS="${CFLAGS}" ${CONFIGURE_ENV} \
		CONFIG_SHELL=/bin/sh \
		CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"

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
.elif defined(APR_UTIL_WITH_BERKELEY_DB) || exists(${LOCALBASE}/lib/libdb4.so.0)
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-db4
.else
PKGNAMESUFFIX=	-db4
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
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${SCRIPTS_ENV} ./buildconf
	cd ${WRKDIR}/apr-util-${PORTVERSION}; \
		${SETENV} ${SCRIPTS_ENV} ./buildconf \
		--with-apr=../apr-${PORTVERSION}

do-configure:
	cd ${WRKDIR}/apr-${PORTVERSION}; \
		${SETENV} ${APR_CONF_ENV} ./configure ${CONFIGURE_ARGS}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; \
		${SETENV} ${APR_UTIL_CONF_ENV} \
		./configure ${CONFIGURE_ARGS} ${APR_UTIL_CONF_ARGS}

do-build:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE} install
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} ${GMAKE} install

.include <bsd.port.post.mk>
