# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	gflags
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-gflags-${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Commandline flags module for Python

LICENSE=	BSD

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_gflags

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/gflags \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

PROJECTHOST=	python-gflags

NO_STAGE=	yes
post-install:
	${TOUCH} ${PYEASYINSTALL_SITELIBDIR}/gflags

.include <bsd.port.mk>
