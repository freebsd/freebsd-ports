PORTNAME=	crossmap
DISTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lift over genomics coordinates between assemblies
WWW=		https://github.com/liguowang/CrossMap

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0.10.4:devel/py-nose@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bx-python>0:biology/py-bx-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyBigWig>0:biology/py-pybigwig@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils

NO_ARCH=	yes

.include <bsd.port.mk>
