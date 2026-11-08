PORTNAME=	torchaudio
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.1
CATEGORIES=	audio python # machine-learning
MASTER_SITES=	https://downloads.sourceforge.net/project/sox/sox/14.4.2/:sox
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	sox-14.4.2.tar.bz2:sox
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}_GH0.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch-based audio signal processing and machine learning library
WWW=		https://pytorch.org/audio/stable/index.html \
		https://github.com/pytorch/audio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		ninja:devel/ninja \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libabsl_symbolize.so:devel/abseil \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}soundfile>0:audio/py-SoundFile@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}torchcodec>0:multimedia/py-torchcodec@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}expecttest>0:devel/py-expecttest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	--disable-plugin-autoload \
		--ignore=test/integration_tests \
		--ignore=test/torchaudio_unittest/example \
		--ignore=test/torchaudio_unittest/functional \
		--ignore=test/torchaudio_unittest/models \
		-k 'not pitch_shift and not PitchShift'

MAKE_ENV=	USE_FFMPEG=0 # ffmpeg integration is broken or unavailable, see https://github.com/pytorch/audio/issues/3716

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	audio

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64"
MAKE_ENV=	LD_STATIC_TLS_EXTRA=4096 # see pkg-message in misc/py-pytorch
.endif

# tests as of 2.11.1: integration_tests, example and models dirs skipped; remaining tests hit segfaults in torch/scipy C extensions in test environment; poudriere build passes

.include <bsd.port.post.mk>
