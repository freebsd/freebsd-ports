# Ports collection Makefile for:	PyGreSQL
# Date created:				2/22/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	PyGreSQL
PORTVERSION=	3.8
PORTEPOCH=	1
CATEGORIES=	databases python
MASTER_SITES=	ftp://ftp.pygresql.org/pub/distrib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A Python interface to PostgreSQL, both classic and DP-API 2.0

BUILD_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base

USE_PGSQL=	yes
USE_PYTHON=	yes
DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py

pre-build:
	@ cd ${WRKSRC} ; ${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' setup.py

do-build:
	@ cd ${WRKSRC} ; ${PYTHON_CMD} setup.py build

do-install:
	@ cd ${WRKSRC} ; ${PYTHON_CMD} setup.py install

post-install:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -lf \
	  ${PYTHONPREFIX_SITELIBDIR}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -lf \
	  ${PYTHONPREFIX_SITELIBDIR}
.if !defined(NOPORTDOCS)
.for docfile in announce.txt changelog.txt
	@ ${MKDIR} ${DOCSDIR}
	  ${INSTALL_DATA} ${WRKSRC}/${docfile} \
	  ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
