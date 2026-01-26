PORTNAME=	torchaudio
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
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
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}SoundFile>0:audio/py-SoundFile@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}torchcodec>0:multimedia/py-torchcodec@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

MAKE_ENV=	USE_FFMPEG=0 # ffmpeg integration is broken or unavailable, see https://github.com/pytorch/audio/issues/3716

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	audio

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 2.10.0: 8 failed, 37 passed, 2 skipped, 75 errors in 308.41s (0:05:08)

.include <bsd.port.mk>
