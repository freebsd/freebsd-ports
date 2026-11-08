PORTNAME=	crossmap
DISTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lift over genomics coordinates between assemblies
WWW=		https://github.com/liguowang/CrossMap

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bx-python>0:biology/py-bx-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyBigWig>0:biology/py-pybigwig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

NO_ARCH=	yes

.include <bsd.port.mk>
