PORTNAME=	flake8-pyi
PORTVERSION=	25.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flake8_pyi-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Plugin for flake8 to enable linting .pyi stub files
WWW=		https://github.com/PyCQA/flake8-pyi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=6.0.0<8.0.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=2.1.1:devel/py-pyflakes@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
