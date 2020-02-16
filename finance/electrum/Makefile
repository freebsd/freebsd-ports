# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	electrum
PORTVERSION=	3.3.8
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://download.electrum.org/${PORTVERSION}/ \
		http://download.electrum.org/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Electrum-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Easy to use Bitcoin client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp-socks>0:net/py-aiohttp-socks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.3.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiorpcX>=0.18:devel/py-aiorpcX@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.9:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonrpclib-pelix>0:devel/py-jsonrpclib-pelix@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbkdf2>=1.3:security/py-pbkdf2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.6.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaes>0:security/py-pyaes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QDarkStyle<2.7:textproc/py-QDarkStyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=5.1:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}secp256k1>0:math/py-secp256k1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR}

# Supports 3.4+ but aiorpcX is 3.6+
USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

PYDISTUTILS_PKGNAME=	Electrum
NO_ARCH=	yes
OPTIONS_SUB=	yes

OPTIONS_DEFINE=	GUI HARDWARE
OPTIONS_DEFAULT=GUI HARDWARE

GUI_USES=	desktop-file-utils pyqt:5
GUI_USE=	PYQT=gui_run,sip,widgets

HARDWARE_USE=	PYTHON=cython
HARDWARE_DESC=	Enable Bitcoin hardware wallet support

HARDWARE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}btchip-python>=0.1.26:security/py-btchip-python@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}trezor>=0.11.0:security/py-trezor@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}keepkey>0:security/py-keepkey@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ckcc-protocol>=0.7.2:security/py-ckcc-protocol@${PY_FLAVOR}

HARDWARE_PLIST_FILES=	"@sample etc/devd/hardware_wallet.conf.sample"

HARDWARE_SUB_FILES=	pkg-message-hwwallet

post-patch-GUI-off:
	@${REINPLACE_CMD} -e '/electrum\.desktop/d' ${WRKSRC}/setup.py

post-install-HARDWARE-on:
	${INSTALL_DATA} ${FILESDIR}/hardware_wallet.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
