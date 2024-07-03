PORTNAME=	pyocd
PORTVERSION=	0.36.0
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Python based tool for programming and debugging Arm Cortex-M uC
WWW=		https://pyocd.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intelhex>=0:devel/py-intelhex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=0:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>=0.12.0:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0.7.2:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylink-square>=0:comms/py-pylink-square@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libusb-package>=0:devel/py-libusb-package@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
