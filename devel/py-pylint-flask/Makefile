PORTNAME=	pylint-flask
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pylint plugin to analyze Flask applications
WWW=		https://github.com/jschaf/pylint-flask

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=1.0:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylint-plugin-utils>=0.2.1:devel/py-pylint-plugin-utils@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=2.8.3:devel/pylint

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
