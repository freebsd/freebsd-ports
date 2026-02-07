PORTNAME=	xsdata-pydantic
PORTVERSION=	24.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xsdata_pydantic-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	xsdata pydantic plugin
WWW=		https://xsdata-pydantic.readthedocs.io/en/latest/ \
		https://github.com/tefra/xsdata-pydantic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.6:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xsdata>=${PORTVERSION}:devel/py-xsdata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
