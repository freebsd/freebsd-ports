# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pycogent
PORTVERSION=	1.9
CATEGORIES=	biology python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Toolkit for statistical analysis of biological sequences

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/bin/sphinx-build:textproc/py-sphinx@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=1.0.13:databases/py-sqlalchemy10@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:-2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist cython

.include <bsd.port.mk>
