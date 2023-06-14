PORTNAME=	apptools
DISTVERSION=	5.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Enthought application tools
WWW=		https://docs.enthought.com/apptools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
# See ${WRKSRC}/image_LICENSE.txt for information that other
# files *LICENSE* are not used

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.0.1:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traitsui>=0:graphics/py-traitsui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
# The requirements are defined in apptools/__init__.py

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
