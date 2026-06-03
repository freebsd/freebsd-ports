PORTNAME=	py3status
PORTVERSION=	3.63
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensible i3status wrapper written in python
WWW=		https://ultrabug.github.io/py3status/ \
		https://github.com/ultrabug/py3status

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.26.1:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	UDEV
UDEV_DESC=	UDEV support

UDEV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyudev>=0.21.0:devel/py-pyudev@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
