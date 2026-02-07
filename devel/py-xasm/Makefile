PORTNAME=	xasm
PORTVERSION=	1.2.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/rocky/python-xasm/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python cross-version byte-code assembler
WWW=		https://github.com/rocky/python-xasm

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.gpl2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdis>=6.1.8<6.3.0:devel/py-xdis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
