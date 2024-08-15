PORTNAME=	vcrpy
DISTVERSION=	6.0.1
PORTREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Automatically mock HTTP interactions to simplify and speed up testing
WWW=		https://github.com/kevin1024/vcrpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.5:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>0:devel/py-wrapt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>0:www/py-yarl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
