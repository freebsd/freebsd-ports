PORTNAME=	decompyle3
PORTVERSION=	3.9.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/rocky/python-uncompyle6/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python cross-version byte-code decompiler
WWW=		https://github.com/rocky/python-decompile3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spark-parser>=1.8.9<1.9.0:devel/py-spark-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdis>=6.1.0<6.2.0:devel/py-xdis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>
