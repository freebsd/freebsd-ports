PORTNAME=	xsdata-attrs
PORTVERSION=	24.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xsdata_attrs-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	xsdata attrs plugin
WWW=		https://xsdata-attrs.readthedocs.io/en/latest/ \
		https://github.com/tefra/xsdata-attrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xsdata>=${PORTVERSION}:devel/py-xsdata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
