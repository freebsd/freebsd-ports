# New ports collection makefile for:	antlr2-python-runtime
# Date created:		1 February 2011
# Whom:			arrowdodger <6yearold@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	antlr2-python-runtime
PORTVERSION=	2.7.7
CATEGORIES=	devel
MASTER_SITES=	http://www.antlr2.org/download/
DISTNAME=	antlr-${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	ANTLR v2 python runtime library

USE_PYTHON=	yes
PYDISTUTILS_PKGNAME=antlr
PYDISTUTILS_PKGVERSION=2.7.5RC1
INSTALLS_EGGINFO=yes

ANTLR_PYTHON_DIR=	${WRKDIR}/${DISTNAME}/lib/python

do-configure:
	@(cd ${ANTLR_PYTHON_DIR} && ${PYTHON_CMD} setup.py config)

do-build:
	@(cd ${ANTLR_PYTHON_DIR} && ${PYTHON_CMD} setup.py build && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${ANTLR_PYTHON_DIR})

do-install:
	@(cd ${ANTLR_PYTHON_DIR} && ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
