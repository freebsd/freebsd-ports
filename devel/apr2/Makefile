# New ports collection makefile for: apr-devel
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	apr-devel
PORTVERSION=	20020309172416
CATEGORIES=	devel
MASTER_SITES=	http://www.apache.org/dist/apr/not-released/
DISTFILES=	apr_20020309172416.tar.gz apr-util_20020309172426.tar.gz

MAINTAINER=	rooneg@electricjellyfish.net

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat

GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}

pre-fetch:
	${SH} pkg-install apr-devel PRE-INSTALL

pre-configure:
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
