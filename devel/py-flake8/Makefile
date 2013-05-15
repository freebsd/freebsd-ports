# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	flake8
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Code checking using pep8 and pyflakes

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mccabe>=0.2:${PORTSDIR}/devel/py-mccabe \
		${PYTHON_PKGNAMEPREFIX}pep8>=1.4.3:${PORTSDIR}/devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.6.1:${PORTSDIR}/devel/py-pyflakes

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	bin/flake8 \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
