PORTNAME=	pynitrokey
DISTVERSION=	0.10.0
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Command line interface for Nitrokey FIDO2, Nitr. Start, Nitr.3, NetHSM
WWW=		https://pypi.org/project/pynitrokey/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.2,<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=43:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fido2>=2,<3:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.14,<0.15:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intelhex>=0:devel/py-intelhex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nkdfu>=0:comms/py-nkdfu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nitrokey>=0.4<0.5:security/py-nitrokey@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tlv8>=0:converters/py-tlv8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=0:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nethsm>=1.4.1,<2:security/py-nethsm@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=0:devel/py-poetry@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.2,<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=43:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fido2>=2,<3:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.14,<0.15:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intelhex>=0:devel/py-intelhex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nkdfu>=0:comms/py-nkdfu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nitrokey>=0.4<0.5:security/py-nitrokey@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tlv8>=0:converters/py-tlv8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=0:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nethsm>=1.4.1,<2:security/py-nethsm@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent cryptography pep517

SHEBANG_FILES=	pynitrokey/start/upgrade_by_passwd.py \
		pynitrokey/start/usb_strings.py

NO_ARCH=	yes

.include <bsd.port.mk>
