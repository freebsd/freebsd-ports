PORTNAME=	agx-emulsion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-alpha
DISTVERSIONSUFFIX=	-84-g0e0baf2
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spectral simulation of analog photography processes
WWW=		https://github.com/andreavolpato/agx-emulsion

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openimageio>0:graphics/py-openimageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colour-science>=0.4.6:graphics/py-colour-science@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dotmap>=1.3.30:devel/py-dotmap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lmfit>=1.3.2:math/py-lmfit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}magicgui>=0.10.0:x11-toolkits/py-magicgui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari>=0.5.5:misc/py-napari@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.61.0:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=3.4.0:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyfftw>=0.15.0:math/py-pyFFTW@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.14.1:science/py-scipy@${PY_FLAVOR}

USES=		pyqt:5 python
USE_PYTHON=	distutils concurrent autoplist
USE_PYQT=	pyqt5

USE_GITHUB=	yes
GH_ACCOUNT=	andreavolpato

NO_ARCH=	yes

.include <bsd.port.mk>
