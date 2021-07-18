PORTNAME=	resdk
DISTVERSION=	13.3.0
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Resolwe SDK to interact with Resolwe server and Resolwe Bioinformatics

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet<=4.0,>=2.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2018.4:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.6.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}slumber>=0.7.1:www/py-slumber@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.5.1:devel/py-tzlocal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>0:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:textproc/py-xlrd@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
