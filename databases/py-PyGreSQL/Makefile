# Ports collection Makefile for:	PyGreSQL
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		py-PyGreSQL
PORTVERSION=		2.4
CATEGORIES=		databases python
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/               \
			http://www.nectar.cc/distfiles/
DISTNAME=		PyGreSQL-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nectar@FreeBSD.org

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python
LIB_DEPENDS=		pq.2:${PORTSDIR}/databases/postgresql

MAKE_ENV=		PYTHON=${PREFIX}/bin/python \
			LN="${LN}" SETENV="${SETENV}" MKDIR="${MKDIR}"

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.PyGreSQL

.include <bsd.port.mk>
