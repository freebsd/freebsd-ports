PORTNAME=	py3status
PORTVERSION=	3.54
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensible i3status wrapper written in python
WWW=		https://py3status.readthedocs.io/en/latest/ \
		https://github.com/ultrabug/py3status

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	UDEV
UDEV_DESC=	UDEV support

UDEV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyudev>=0.21.0:devel/py-pyudev@${PY_FLAVOR}

.include <bsd.port.mk>
