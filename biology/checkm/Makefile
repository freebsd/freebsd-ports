# $FreeBSD$

PORTNAME=	CheckM
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.12
PORTREVISION=	1
CATEGORIES=	biology python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quality assessment tool for the microbial genomes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}DendroPy>=4.0.0:science/py-DendroPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.3.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.8.3:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.9.0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	Ecogenomics
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
