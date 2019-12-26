# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	hgsubversion
PORTVERSION=	1.9.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Mercurial extension that allows using it as a Subversion client

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2

OPTIONS_DEFINE=	SUBVERTPY
OPTIONS_DEFAULT=SUBVERTPY
SUBVERTPY_DESC=	Use subvertpy python bindings

USES=		python:2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

SUBVERTPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subvertpy>=0:devel/py-subvertpy@${PY_FLAVOR}
SUBVERTPY_RUN_DEPENDS_OFF=	${PYTHON_PKGNAMEPREFIX}subversion>=0:devel/py-subversion@${PY_FLAVOR}

.include <bsd.port.mk>
