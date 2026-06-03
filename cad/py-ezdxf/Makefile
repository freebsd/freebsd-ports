PORTNAME=	ezdxf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Create and modify DXF drawings
WWW=		https://ezdxf.mozman.at/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geomdl>0:graphics/py-geomdl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}geomdl>0:graphics/py-geomdl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	concurrent distutils autoplist pytest

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mozman

.include <bsd.port.mk>
