# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urbanaccess
PORTVERSION=	0.2.2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for creating GTFS transit and OSM pedestrian networks

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geopy>=1.11.0:net/py-geopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.11,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osmnet>=0.1.4:graphics/py-osmnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandana>=0.2.0:graphics/py-pandana@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.17.0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.17.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11:devel/py-six@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
