# Ports collection Makefile for:	PyGreSQL
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		PyGreSQL
PORTVERSION=		3.0
CATEGORIES=		databases python
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/
PKGNAMEPREFIX=		py-
DISTNAME=		PyGreSQL-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nectar@FreeBSD.org

BUILD_DEPENDS=		${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
RUN_DEPENDS=		${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
LIB_DEPENDS=		pq.2:${PORTSDIR}/databases/postgresql7

USE_PYTHON=		yes
MAKE_ENV=		PYTHON_VERSION=${PYTHON_VERSION} \
			PYTHON_LIBDIR=${PYTHON_LIBDIR} \
			PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
			PYTHON=${PYTHON_CMD} \
			LN="${LN}" SETENV="${SETENV}" MKDIR="${MKDIR}"

DATETIME_DEP=		${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.PyGreSQL

.include <bsd.port.mk>
