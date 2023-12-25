PORTNAME=	geoalchemy2
PORTVERSION=	0.14.3
CATEGORIES=	databases geography python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	GeoAlchemy2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Using SQLAlchemy with Spatial Databases
WWW=		https://geoalchemy-2.readthedocs.io/en/stable/ \
		https://github.com/geoalchemy/geoalchemy2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.4:databases/py-sqlalchemy14@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SHAPELY
SHAPELY_DESC=	Shapely integration

SHAPELY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}shapely>=1.7:devel/py-shapely@${PY_FLAVOR}

.include <bsd.port.mk>
