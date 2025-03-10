PORTNAME=	usbtmc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Pure Python USBTMC driver for controlling instruments over USB
WWW=		https://github.com/python-ivi/python-usbtmc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	python-ivi
GH_PROJECT=	python-usbtmc

.include <bsd.port.mk>
