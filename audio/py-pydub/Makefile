PORTNAME=	pydub
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.1
CATEGORIES=	audio
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Manipulate audio with an simple and easy high level interface
WWW=		http://pydub.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simpleaudio>0:audio/py-simpleaudio@${PY_FLAVOR} \
		ffmpeg:multimedia/ffmpeg

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/jiaaro/pydub/issues/712

USE_GITHUB=	yes
GH_ACCOUNT=	jiaaro

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

.include <bsd.port.mk>
