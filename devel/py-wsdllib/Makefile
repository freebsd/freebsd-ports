# New ports collection makefile for:	py-wsdllib
# Date created:		28 July 2003
# Whom:	      		Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	wsdllib
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	ftp://www-126.ibm.com/pub/wsdl4py/wsdl4py/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	wsdl4py-${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A library for using and manipulating WSDL files using Python

BUILD_DEPENDS=	4xslt:${PORTSDIR}/textproc/py-4suite
RUN_DEPENDS=	${PYXML} \
		4xslt:${PORTSDIR}/textproc/py-4suite

BROKEN=		Unfetchable

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYSETUP=	${FILESDIR}/setup.py
MAKE_ENV+=	PORTNAME="${PORTNAME}" PORTVERSION="${PORTVERSION}" COMMENT="${COMMENT}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Coredump during build on alpha 4.x"
.endif

pre-build test:
	# Running the vendor's tests:
	cd ${WRKSRC}/test && ${SETENV} PYTHONPATH=.. ${PYTHON_CMD} test.py

.include <bsd.port.post.mk>
