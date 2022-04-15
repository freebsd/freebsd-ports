PORTNAME=	CheckM
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9
CATEGORIES=	biology python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quality assessment tool for the microbial genomes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}DendroPy>=4.4.0:science/py-DendroPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.12.0.1:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19.1:science/py-scipy@${PY_FLAVOR}

USES=		dos2unix python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	Ecogenomics
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
