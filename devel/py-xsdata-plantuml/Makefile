PORTNAME=	xsdata-plantuml
PORTVERSION=	24.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xsdata_plantuml-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	xsdata PlantUML generator
WWW=		https://github.com/tefra/xsdata-plantuml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xsdata>=${PORTVERSION}:devel/py-xsdata@${PY_FLAVOR}
# xsdata[cli]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-default-group>=1.2:devel/py-click-default-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docformatter>=1.7.2:devel/py-docformatter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toposort>=1.5:devel/py-toposort@${PY_FLAVOR} \
		ruff>=0.3.0:devel/ruff

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
