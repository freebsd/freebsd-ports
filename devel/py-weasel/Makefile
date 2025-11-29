PORTNAME=	weasel
PORTVERSION=	0.4.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/explosion/weasel/releases/download/release-v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small and easy workflow system
WWW=		https://github.com/explosion/weasel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpathlib>=0.7.0<1.0.0:devel/py-cloudpathlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}confection>=0.0.4<0.2.0:devel/py-confection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.7.4<3.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13.0<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smart-open>=5.2.1<8.0.0:net/py-smart-open@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}srsly>=2.4.3<3.0.0:devel/py-srsly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer-slim>=0.3.0<1.0.0:devel/py-typer-slim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wasabi>=0.9.1<1.2.0:textproc/py-wasabi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
