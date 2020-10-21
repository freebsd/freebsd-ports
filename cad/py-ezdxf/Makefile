# $FreeBSD$

PORTNAME=	ezdxf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.2
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Create and modify DXF drawings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geomdl>0:graphics/py-geomdl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geomdl>0:graphics/py-geomdl@${PY_FLAVOR}

USES=	python:3.6+
USE_PYTHON=	concurrent distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	mozman
GH_PROJECT=	ezdxf

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
