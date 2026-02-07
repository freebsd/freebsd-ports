PORTNAME=	comicapi
DISTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	archivers python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_ACCOUNT}/commit/
PATCHFILES=	956c383e5f133f3147f55f8f65b501db1c4a0284.patch:-p1

MAINTAINER=	matthew@wener.org
COMMENT=	Comic archive (cbr/cbz) and metadata utilities
WWW=		https://github.com/comictagger/comicapi

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycountry>=0:textproc/py-pycountry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=0:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text2digits>=0:textproc/py-text2digits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wordninja>=0:textproc/py-wordninja@${PY_FLAVOR}
TEST_DEPENDS=	${7Z_RUN_DEPENDS} \
		${CBR_RUN_DEPENDS}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	comictagger
GH_TAGNAME=	2bf8332
USE_PYTHON=	autoplist pep517 pytest

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}
TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		7Z CBR ICU
OPTIONS_DEFAULT=	ICU

7Z_DESC=	7-Zip
CBR_DESC=	CBR
ICU_DESC=	ICU

7Z_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}py7zr>=0:archivers/py-py7zr@${PY_FLAVOR}
CBR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rarfile>=0:archivers/py-rarfile@${PY_FLAVOR} \
			rar>=0:archivers/rar
ICU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=0:devel/py-pyicu@${PY_FLAVOR}

.include <bsd.port.mk>
