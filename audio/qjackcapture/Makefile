PORTNAME=	qjackcapture
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI for the jack_capture program using PyQt5
WWW=		https://github.com/SpotlightKid/qjackcapture

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}natsort>0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjacklib>0:audio/py-pyjacklib@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PY_DEPENDS} \
		jack_capture:audio/jack-capture

USES=		desktop-file-utils gmake pyqt:5 python shebangfix
USE_PYQT=	pyqt5

SHEBANG_FILES=	qjackcapture/app.py

USE_GITHUB=	yes
GH_ACCOUNT=	SpotlightKid

MAKE_ARGS=	PYTHON=${PYTHON_CMD}

PLIST_SUB=	VER=${DISTVERSION}

.include <bsd.port.mk>
