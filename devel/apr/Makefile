# New ports collection makefile for: apr
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	apr
PORTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://www.apache.org/dist/apr/
DISTFILES=	apr-${PORTVERSION}.tar.gz apr-util-${PORTVERSION}.tar.gz

MAINTAINER=	rodrigc@attbi.com

BUILD_DEPENDS+=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS+=	expat.4:${PORTSDIR}/textproc/expat2 \
		iconv.3:${PORTSDIR}/converters/libiconv

WANT_AUTOCONF_VER=	253

USE_PERL5=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

WRKSRC=	${WRKDIR}

APR_CONF_ENV=	${CONFIGURE_ENV} \
		CONFIG_SHELL=/bin/sh

APR_UTIL_CONF_ENV=${CONFIGURE_ENV} \
		CONFIG_SHELL=/bin/sh \
		CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib"

APR_UTIL_CONF_ARGS=	--with-apr=../apr-${PORTVERSION} --with-expat=${PREFIX}

pre-fetch:
	${SH} pkg-install apr PRE-INSTALL

pre-configure:
	cd ${WRKDIR}/apr-${PORTVERSION}; ./buildconf
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ./buildconf

do-configure:
	cd ${WRKDIR}/apr-${PORTVERSION}; \
		${SETENV} ${APR_CONF_ENV} ./configure ${CONFIGURE_ARGS}
	cd ${WRKDIR}/apr-util-${PORTVERSION}; \
		${SETENV} ${APR_UTIL_CONF_ENV} \
		./configure ${CONFIGURE_ARGS} ${APR_UTIL_CONF_ARGS} 

do-build:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} make
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} make

do-install:
	cd ${WRKDIR}/apr-${PORTVERSION}; ${SETENV} ${MAKE_ENV} make install
	cd ${WRKDIR}/apr-util-${PORTVERSION}; ${SETENV} ${MAKE_ENV} make install

.include <bsd.port.mk>
