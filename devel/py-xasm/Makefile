PORTNAME=	xasm
PORTVERSION=	1.2.0
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdis>=6.0.3:devel/py-xdis@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
