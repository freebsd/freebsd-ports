PORTNAME=	domdf-python-tools
PORTVERSION=	3.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/domdfcoding/domdf_python_tools/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	domdf_python_tools-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpful functions for Python
WWW=		https://domdf-python-tools.readthedocs.io/en/latest/ \
		https://github.com/domdfcoding/domdf_python_tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-requirements-txt>=0:devel/py-hatch-requirements-txt@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}natsort>=7.0.1:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.1:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
