# Ports collection Makefile for:	PyGreSQL
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		py-PyGreSQL
PORTVERSION=		2.4
CATEGORIES=		databases python
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/
DISTNAME=		PyGreSQL-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nectar@FreeBSD.org

BUILD_DEPENDS=		python1.5:${PORTSDIR}/lang/python15
RUN_DEPENDS=		python1.5:${PORTSDIR}/lang/python15
LIB_DEPENDS=		pq.2:${PORTSDIR}/databases/postgresql7

MAKE_ENV=		PYTHON=${PREFIX}/bin/python \
			LN="${LN}" SETENV="${SETENV}" MKDIR="${MKDIR}"

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.PyGreSQL

.include <bsd.port.mk>
