PORTNAME=	orange3-bioinformatics
DISTVERSION=	4.8.4
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange add-on providing common functionality for bioinformatics
WWW=		https://github.com/biolab/orange3-bioinformatics/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expiring misc/orange3
EXPIRATION_DATE=2025-06-21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYTHON_PKGNAMEPREFIX}Genesis-PyAPI>0:biology/py-Genesis-PyAPI@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}point-annotator>=2.0:math/py-point-annotator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyclipper>=1.2.0:math/py-pyclipper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-cache0>0:www/py-requests-cache0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resdk>0:biology/py-resdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}serverfiles>0:misc/py-serverfiles@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
