PORTNAME=	vdf
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Library for working with Valve's VDF text format
WWW=		https://github.com/ValvePython/vdf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	ValvePython

USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
