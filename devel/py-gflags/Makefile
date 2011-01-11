# New ports collection makefile for:	py-gflags
# Date created:		2011-01-10
# Whom:			Julien Laffaye <kimelto@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gflags
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-gflags-${PORTVERSION}

MAINTAINER=	kimelto@gmail.com
COMMENT=	Commandline flags module for Python

PROJECTHOST=	python-gflags
LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_gflags

post-install:
	${TOUCH} ${PYEASYINSTALL_SITELIBDIR}/gflags

.include <bsd.port.mk>
