# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pycogent
PORTVERSION=	1.9
PORTREVISION=	3
CATEGORIES=	biology python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Toolkit for statistical analysis of biological sequences

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0.13:databases/py-sqlalchemy10@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:-2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist cython

.include <bsd.port.mk>
