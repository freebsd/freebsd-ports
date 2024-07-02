PORTNAME=	nkdfu
PORTVERSION=	0.2
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	Python DFU tool for updating Nitrokeys' firmware (Nitrokey Pro only)
WWW=		https://github.com/Nitrokey/nkdfu

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fire>=0:devel/py-fire@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}intelhex>=2.3.0:devel/py-intelhex@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}libusb1>=1.9.3:devel/py-libusb1@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fire>=0:devel/py-fire@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}intelhex>=2.3.0:devel/py-intelhex@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}libusb1>=1.9.3:devel/py-libusb1@${PY_FLAVOR}

PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2.0<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=  nkdfu/dfu_flash.py
NO_ARCH=	yes

.include <bsd.port.mk>
