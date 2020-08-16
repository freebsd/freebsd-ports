# $FreeBSD$

PORTNAME=	cadquery
DISTVERSION=	2.0.1
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Python module for building parametric 3D CAD models

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ezdxf/__init__.py:cad/py-ezdxf@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/OCP.so:cad/py-ocp@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pyparsing.py:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/typing_extensions.py:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.6+,run
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	CadQuery
GH_PROJECT=	cadquery

post-extract:
# Move into a sub-directory so that we don't pollute site-packages.
	${MV} ${WRKSRC}/tests ${WRKSRC}/cadquery/tests

.include <bsd.port.mk>
