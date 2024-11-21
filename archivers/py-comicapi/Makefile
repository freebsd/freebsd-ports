PORTNAME=	comicapi
PORTVERSION=	3.2.0
CATEGORIES=	archivers python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@wener.org
COMMENT=	Comic archive (cbr/cbz) and metadata utilities
WWW=		https://github.com/comictagger/comicapi

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycountry>=0:textproc/py-pycountry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=0:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text2digits>=0:textproc/py-text2digits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wordninja>=0:textproc/py-wordninja@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	comictagger
GH_TAGNAME=	2bf8332
USE_PYTHON=	autoplist distutils pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		7Z CBR ICU
OPTIONS_DEFAULT=	ICU

7Z_DESC=	7-Zip
CBR_DESC=	CBR
ICU_DESC=	ICU

7Z_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py7zr>=0:archivers/py-py7zr@${PY_FLAVOR}
CBR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rarfile>=0:archivers/py-rarfile@${PY_FLAVOR} \
			unrar>=0:archivers/unrar
ICU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=0:devel/py-pyicu@${PY_FLAVOR}

# The two sorting tests may fail based on system locale
do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v

.include <bsd.port.mk>
