PORTNAME=	orange3-bioinformatics
DISTVERSION=	4.3.1
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Orange3-Bioinformatics-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange add-on providing common functionality for bioinformatics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYTHON_PKGNAMEPREFIX}Genesis-PyAPI>0:biology/py-Genesis-PyAPI@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}point-annotator>=2.0:math/py-point-annotator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyclipper>=1.2.0:math/py-pyclipper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-cache>0:www/py-requests-cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resdk>0:biology/py-resdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serverfiles>0:misc/py-serverfiles@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
