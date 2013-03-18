# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	flake8
PORTVERSION=	2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	william88@gmail.com
COMMENT=	Code checking using pep8 and pyflakes

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mccabe>=0.2:${PORTSDIR}/devel/py-mccabe \
		${PYTHON_PKGNAMEPREFIX}pep8>=1.4.3:${PORTSDIR}/devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}flakes>=0.6.1:${PORTSDIR}/devel/py-pyflakes

USE_PYTHON=	-2.7 # It actually python3 ready, but still needs some work
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%% bin/flake8

.include <bsd.port.mk>
