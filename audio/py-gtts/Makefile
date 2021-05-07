PORTNAME=	gtts
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library/CLI tool to interface with Google Translate text-to-speech API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.9:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testfixtures>0:devel/py-testfixtures@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	pndurette
GH_PROJECT=	gTTS
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

do-test:
	# Comment out hardcoded pytest version requirement
	@${REINPLACE_CMD} -Ee 's|(^minversion)|#\1|' ${WRKSRC}/pytest.ini
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
