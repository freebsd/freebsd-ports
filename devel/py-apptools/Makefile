PORTNAME=	apptools
DISTVERSION=	5.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Enthought application tools
WWW=		https://docs.enthought.com/apptools/ \
		https://github.com/enthought/apptools/

LICENSE=	BSD3CLAUSE LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL20=	${WRKSRC}/image_LICENSE_CP.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traits>=6.2.0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitsui>=0:graphics/py-traitsui@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
