PORTNAME=	electrum
PORTVERSION=	4.2.2
CATEGORIES=	finance python
MASTER_SITES=	https://download.electrum.org/${PORTVERSION}/ \
		http://download.electrum.org/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Electrum-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Easy to use Bitcoin client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp-socks>=0.3:net/py-aiohttp-socks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.3.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiorpcX>=0.22.0:devel/py-aiorpcX@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bitstring>0:devel/py-bitstring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.6:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonrpclib-pelix>0:devel/py-jsonrpclib-pelix@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbkdf2>=1.3:security/py-pbkdf2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.12:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QDarkStyle>=2.7:textproc/py-QDarkStyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}secp256k1>0:math/py-secp256k1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.7.9:databases/py-sqlite3@${PY_FLAVOR}

USES=		cpe python:3.8+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

PYDISTUTILS_PKGNAME=	Electrum

SHEBANG_FILES=	electrum/electrum
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

OPTIONS_DEFINE=		GUI HARDWARE
OPTIONS_DEFAULT=	GUI HARDWARE
OPTIONS_SUB=		yes

HARDWARE_DESC=	Enable Bitcoin hardware wallet support

GUI_USES=		desktop-file-utils pyqt:5
GUI_USE=		PYQT=pyqt5,sip
HARDWARE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bitbox02>=0.13.0:security/py-bitbox02@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}btchip-python>=0.1.32:security/py-btchip-python@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ckcc-protocol>=0.7.7:security/py-ckcc-protocol@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}keepkey>=6.3.1:security/py-keepkey@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}trezor>=0.13.0:security/py-trezor@${PY_FLAVOR}
HARDWARE_USE=		PYTHON=cython
HARDWARE_SUB_FILES=	pkg-message-hwwallet
HARDWARE_PLIST_FILES=	"@sample etc/devd/hardware_wallet.conf.sample"

post-patch-GUI-off:
	@${REINPLACE_CMD} -e '/electrum\.desktop/d' ${WRKSRC}/setup.py

post-install-HARDWARE-on:
	${INSTALL_DATA} ${FILESDIR}/hardware_wallet.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
