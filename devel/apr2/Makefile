# New ports collection makefile for: apr
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	apr
PORTVERSION=	0.9.2.a
INTERNALPORTVERSION=	0.9.2
CATEGORIES=	devel
MASTER_SITES=	http://www.apache.org/dist/apr/
DISTFILES=	apr-${INTERNALPORTVERSION}-alpha.tar.gz apr-util-${INTERNALPORTVERSION}-alpha.tar.gz

MAINTAINER=	rodrigc@attbi.com
COMMENT=	The Apache Group's Portability Library

BUILD_DEPENDS+=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS+=	expat.4:${PORTSDIR}/textproc/expat2 \
		iconv.3:${PORTSDIR}/converters/libiconv

WANT_AUTOCONF_VER=	253

USE_PERL5=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes

WRKSRC=	${WRKDIR}

APR_CONF_ENV=	${CONFIGURE_ENV} \
		CONFIG_SHELL=/bin/sh

APR_UTIL_CONF_ENV=${CONFIGURE_ENV} \
		CONFIG_SHELL=/bin/sh \
		CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"

APR_UTIL_CONF_ARGS=	--with-apr=../apr-${INTERNALPORTVERSION} \
			--with-expat=${PREFIX} \
			--with-iconv=${PREFIX}

pre-fetch:
	${SH} pkg-install apr PRE-INSTALL

pre-configure:
	cd ${WRKDIR}/apr-${INTERNALPORTVERSION}; ./buildconf
	cd ${WRKDIR}/apr-util-${INTERNALPORTVERSION}; ./buildconf \
		--with-apr=../apr-${INTERNALPORTVERSION}

do-configure:
	cd ${WRKDIR}/apr-${INTERNALPORTVERSION}; \
		${SETENV} ${APR_CONF_ENV} ./configure ${CONFIGURE_ARGS}
	cd ${WRKDIR}/apr-util-${INTERNALPORTVERSION}; \
		${SETENV} ${APR_UTIL_CONF_ENV} \
		./configure ${CONFIGURE_ARGS} ${APR_UTIL_CONF_ARGS} 

do-build:
	cd ${WRKDIR}/apr-${INTERNALPORTVERSION}; ${SETENV} ${MAKE_ENV} make
	cd ${WRKDIR}/apr-util-${INTERNALPORTVERSION}; ${SETENV} ${MAKE_ENV} make

do-install:
	cd ${WRKDIR}/apr-${INTERNALPORTVERSION}; ${SETENV} ${MAKE_ENV} make install
	cd ${WRKDIR}/apr-util-${INTERNALPORTVERSION}; ${SETENV} ${MAKE_ENV} make install

.include <bsd.port.mk>
