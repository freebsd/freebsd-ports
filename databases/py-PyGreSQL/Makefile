# Ports collection Makefile for:	PyGreSQL
# Version required:			2.3
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.14 1999/04/08 19:05:46 billf Exp $
#

DISTNAME=		PyGreSQL-2.3
PKGNAME=		py-PyGreSQL-2.3
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nectar@FreeBSD.ORG

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python
LIB_DEPENDS=		pq.2:${PORTSDIR}/databases/postgresql

MAKE_ENV=		PYTHON=${PREFIX}/bin/python \
			LN="${LN}" SETENV="${SETENV}" MKDIR="${MKDIR}"

CHOWN?=			chown
CHMOD?=			chmod

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.PyGreSQL

.include <bsd.port.mk>
