# ex:ts=8
# Ports collection makefile for:	py-ciphon
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ciphon
PORTVERSION=	0.3.5
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pythonsiphon
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyexpat.so:${PORTSDIR}/textproc/py-expat

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install
	@${MV} -f ${PREFIX}/bin/ciphon.py ${PREFIX}/bin/ciphon

.include <bsd.port.mk>
