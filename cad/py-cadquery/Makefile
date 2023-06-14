PORTNAME=	${GH_ACCOUNT:tl}
DISTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Python module for building parametric 3D CAD models
WWW=		https://github.com/CadQuery/cadquery

LICENSE=	APACHE20

DEPRECATED=	Depends on exppired cad/py-ocp
EXPIRATION_DATE=2023-06-21

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ezdxf/__init__.py:cad/py-ezdxf@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/OCP.so:cad/py-ocp@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pyparsing.py:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/typing_extensions.py:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:run
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	CadQuery

post-extract:
# Move into a sub-directory so that we don't pollute site-packages.
	${MV} ${WRKSRC}/tests ${WRKSRC}/cadquery/tests

.include <bsd.port.mk>
