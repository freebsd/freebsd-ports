PORTNAME=	pygfx
DISTVERSION=	0.17.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Powerful and versatile visualization for Python
WWW=		https://pygfx.org/ \
		https://github.com/pygfx/pygfx

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freetype-py>0:print/py-freetype-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hsluv>=5:graphics/py-hsluv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.1,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylinalg>=0.6.8:math/py-pylinalg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rendercanvas>=2.6.1:graphics/py-rendercanvas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uharfbuzz>0:print/py-uharfbuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wgpu>=0.30.1:graphics/py-wgpu@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
