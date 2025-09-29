PORTNAME=	cadquery-pywrap
DISTVERSIONPREFIX=	occt
DISTVERSION=	7.5
PORTREVISION=	4
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	C++ binding generator for python
WWW=		https://github.com/CadQuery/pywrap

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	This port was part of an effort to port CadQuery. This has been abandoned, so this port is no longer needed as it serves no other purpose.
EXPIRATION_DATE=2025-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}clang>0:devel/py-clang@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cymbal>0:devel/py-cymbal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logzero>0:devel/py-logzero@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path>0:devel/py-path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.6:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schema>0:devel/py-schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toposort>0:devel/py-toposort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		llvm:11,run python
USE_GITHUB=	yes
GH_ACCOUNT=	CadQuery
GH_PROJECT=	pywrap
GH_TAGNAME=	e8c7bc9
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
