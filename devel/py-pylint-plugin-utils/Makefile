PORTNAME=	pylint-plugin-utils
PORTVERSION=	0.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities and helpers for writing Pylint plugins
WWW=		https://github.com/PyCQA/pylint-plugin-utils

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pylint${PYTHON_PKGNAMESUFFIX}>=1.7:devel/pylint@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
