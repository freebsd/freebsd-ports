# New ports collection makefile for: apr
# Date created:		19 February 2002
# Whom:			Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#

PORTNAME=	apr
PORTVERSION=	20020725223645
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.apache.org/dist/apr/not-released/
DISTFILES=	apr_${PORTVERSION}.tar.gz apr-util_20020725223700.tar.gz

MAINTAINER=	rooneg@electricjellyfish.net

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes

USE_PERL5=	yes
WRKSRC=	${WRKDIR}

pre-fetch:
	@${SH} pkg-install apr PRE-INSTALL

pre-configure:
	@(cd ${WRKDIR}/apr/ && ./buildconf)
	@(cd ${WRKDIR}/apr-util/ && ./buildconf)

do-configure:
	@(cd ${WRKDIR}/apr/ && ./configure --prefix=${PREFIX})
	@(cd ${WRKDIR}/apr-util/ && ${ENV} CPPFLAGS=-I${PREFIX}/include LDFLAGS=-L${PREFIX}/lib ./configure --prefix=${PREFIX} --with-apr=../apr/ --with-expat=${PREFIX})

do-build:
	@(cd ${WRKDIR}/apr/ && make)
	@(cd ${WRKDIR}/apr-util/ && make)

do-install:
	@(cd ${WRKDIR}/apr/ && make install)
	(cd ${WRKDIR}/apr-util/ && make install)

.include <bsd.port.mk>
