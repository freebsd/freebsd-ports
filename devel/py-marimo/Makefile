PORTNAME=	marimo
PORTVERSION=	0.23.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Reactive Python notebook
WWW=		https://marimo.io/

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0<9:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.16.0:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=2.0.0:security/py-itsdangerous \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.18.0<0.20.0:devel/py-jedi \
		${PYTHON_PKGNAMEPREFIX}loro>=1.10.0:devel/py-loro \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.6<4:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}msgspec>=0.20.0:devel/py-msgspec \
		${PYTHON_PKGNAMEPREFIX}narwhals>=2.0.0:math/py-narwhals \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.0:sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.19<3:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>=10.21.2<11:textproc/py-pymdown-extensions \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.18:www/py-python-multipart \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=27.1.0:net/py-pyzmq \
		${PYTHON_PKGNAMEPREFIX}starlette>=0.37.2:www/py-starlette \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.12.0:textproc/py-tomlkit \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.22.0:www/py-uvicorn \
		${PYTHON_PKGNAMEPREFIX}websockets>=14.2.0:devel/py-websockets
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}uv-build>=0.8.3<0.12.0:devel/py-uv-build

USES=		python
USE_PYTHON=	autoplist noflavors pep517

.include <bsd.port.mk>
