PORTNAME=	wheel
PORTVERSION=	0.38.4
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Built-package format for Python
WWW=		https://github.com/pypa/wheel

LICENSE=	MIT

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=268500
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar
NO_ARCH=	yes

OPTIONS_DEFINE=	PIP SIGNATURE

PIP_DESC=	Use pip to install wheels
SIGNATURE_DESC=	Enable digital signature of wheels

PIP_RUN_DEPENDS=	pip-${PYTHON_VER}:devel/py-pip@${PY_FLAVOR}
SIGNATURE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirspec>=13.05:devel/py-dirspec@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ed25519ll>=0.6_1:security/py-ed25519ll@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}keyring>=1.3:security/py-keyring@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg@${PY_FLAVOR}

.include <bsd.port.mk>
