PORTNAME=	prodigy-lig
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	biology python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Prediction of protein-small molecule binding affinities
WWW=		https://nestor.science.uu.nl/prodigy/lig

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		gmake python
USE_PYTHON=	pep517 noflavors autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	haddocking

NO_ARCH=	yes

.include <bsd.port.mk>
