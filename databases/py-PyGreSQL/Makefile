# Ports collection Makefile for:	PyGreSQL
# Version required:			2.1
# Date created:				6/25/1998
# Whom:					n@nectar.com
#
# $Id: Makefile,v 1.8 1998/10/12 04:14:44 jseger Exp $
#

DISTNAME=		PyGreSQL-2.1
PKGNAME=		py-PyGreSQL-2.1
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=		.tgz

MAINTAINER=		n@nectar.com

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python
LIB_DEPENDS=		pq.1:${PORTSDIR}/databases/postgresql

WRKSRC=			${WRKDIR}

MAKE_ENV=		PYTHON=${PREFIX}/bin/python \
			LN="${LN}" SETENV="${SETENV}" MKDIR="${MKDIR}"

CHOWN?=			chown
CHMOD?=			chmod

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.PyGreSQL

.include <bsd.port.mk>
