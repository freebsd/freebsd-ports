PORTNAME=	scikit-image
PORTVERSION=	0.25.2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	scikit_image-${DISTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Image processing in Python
WWW=		https://scikit-image.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.4:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0.16:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pythran>=0.16:devel/py-pythran@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}imageio>2.35.0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.4:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=3.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11.4:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tifffile>=2022.8.12:graphics/py-tifffile@${PY_FLAVOR}

USES=		compiler:c++11-lang python shebangfix
USE_PYTHON=	autoplist cython3 pep517

BINARY_ALIAS=	python=${PYTHON_CMD} \
		python3=${PYTHON_CMD}

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/skimage -name "*.so" -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
