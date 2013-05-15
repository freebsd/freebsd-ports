# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	pytest-runner
PORTVERSION=	1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Test support for pytest runner in setup.py

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hgtools>=0:${PORTSDIR}/devel/py-hgtools

USE_ZIP=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
