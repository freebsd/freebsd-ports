# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	datatest
PORTVERSION=	0.11.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing tools for data validation and analysis

LICENSE=	APACHE20

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	OPTIONAL
OPTIONAL_DESC=	Optional dependencies

OPTIONAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbfread>=0:textproc/py-dbfread@${PY_FLAVOR} \
			${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}pandas>=0,1:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}squint>=0:databases/py-squint@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR}

.include <bsd.port.mk>
