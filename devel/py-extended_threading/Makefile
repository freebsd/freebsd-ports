# New ports collection makefile for:   py-extended_threading
# Date created:        14 Jan 2008
# Whom:                James Stapleton <fbsdporter@var-dev.net>
#
# $FreeBSD$
#

PORTNAME=	extended_threading
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES+=	http://www.var-dev.net/programming/python/extended_threading/ \
		http://www.var-dev.com/programming/python/extended_threading/ \
		http://www.var-dev.org/programming/python/extended_threading/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	extended_threading-0_2

MAINTAINER=	fbsdporter@var-dev.net
COMMENT=	A library to extend pythons threading library

USE_PYTHON=	yes

USE_BZIP2=	YES

do-build:
	(cd ${WRKDIR}/extended_threading/extended_threading/ && \
	echo "import sys; import py_compile; for f in sys.argv: py_compile.compile(f)" | ${PYTHON_CMD} *.py)

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/extended_threading
	(cd ${WRKDIR}/extended_threading/extended_threading/ && \
	${CP} -rfv * ${PYTHON_SITELIBDIR}/extended_threading)

.include <bsd.port.mk>
