PORTNAME=	isort
PORTVERSION=	5.13.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python utility/library to sort Python imports
WWW=		https://github.com/PyCQA/isort

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	COLORS
COLORS_DESC=	Color output support

COLORS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.5:devel/py-colorama@${PY_FLAVOR}

.include <bsd.port.mk>
