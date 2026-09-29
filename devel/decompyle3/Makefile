PORTNAME=	decompyle3
PORTVERSION=	3.9.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/rocky/python-uncompyle6/releases/download/${PORTVERSION}/

PATCH_SITES=	https://github.com/rocky/python-decompile3/commit/
PATCHFILES=	661f660cbe1ba67a9f550d2d3fd4b018fd360cc4.patch:-p1 \
		25fb9036b8dba51b81de9917a2aec39f76feb339.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python cross-version byte-code decompiler
WWW=		https://github.com/rocky/python-decompile3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spark-parser>=1.8.9<1.9.2:devel/py-spark-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdis>=6.2:devel/py-xdis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>
