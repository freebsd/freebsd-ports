# New ports collection makefile for: apr-devel
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	apr-devel
PORTVERSION=	20020504162319
CATEGORIES=	devel
MASTER_SITES=	http://www.apache.org/dist/apr/not-released/
DISTFILES=	apr_${PORTVERSION}.tar.gz apr-util_20020504162329.tar.gz

MAINTAINER=	rooneg@electricjellyfish.net

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}

pre-fetch:
	${SH} pkg-install apr-devel PRE-INSTALL

pre-configure:
	(find ${WRKDIR}/apr-util/ -name Makefile.in -exec \
	 ${PERL} -pi -e 's/\@APRUTIL_INCLUDES\@ \@APRUTIL_PRIV_INCLUDES\@/\@APRUTIL_PRIV_INCLUDES\@ \@APRUTIL_INCLUDES\@/g' \{\} \;)

	(cd ${WRKDIR}/apr/ && ./buildconf)
	(cd ${WRKDIR}/apr-util/ && ./buildconf)

do-configure:
	(cd ${WRKDIR}/apr/ && ./configure --prefix=${PREFIX})
	(cd ${WRKDIR}/apr-util/ && ./configure --prefix=${PREFIX} --with-apr=../apr/ --with-expat=${PREFIX})

do-build:
	(cd ${WRKDIR}/apr/ && make)
	(cd ${WRKDIR}/apr-util/ && make)

do-install:
	(cd ${WRKDIR}/apr/ && make install)
	(cd ${WRKDIR}/apr-util/ && make install)

.include <bsd.port.mk>
