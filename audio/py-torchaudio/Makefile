PORTNAME=	torchaudio
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	3
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

USES=		python
USE_PYTHON=	pep517 autoplist pytest

MAKE_ENV=	USE_FFMPEG=0 # ffmpeg integration is broken or unavailable, see https://github.com/pytorch/audio/issues/3716

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	audio

# workaround for missing libsox.so, see https://github.com/pytorch/audio/issues/4062
PLIST_FILES=	lib/python${_PYTHON_VERSION}/site-packages/torchaudio/lib/libsox.so

post-patch:
	@${REINPLACE_CMD} \
		-e 's| URL .*| URL file://${DISTDIR}/sox-14.4.2.tar.bz2|' \
		${WRKSRC}/third_party/sox/CMakeLists.txt

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && ${STRIP_CMD} \
		torchaudio/lib/_torchaudio.so \
		torchaudio/lib/_torchaudio_sox.so \
		torchaudio/lib/libtorchaudio.so \
		torchaudio/lib/libtorchaudio_sox.so
	# workaround for missing libsox.so, see https://github.com/pytorch/audio/issues/4062
	@${CP} \
		${WRKSRC}/build/*/third_party/sox/libsox.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/torchaudio/lib

.include <bsd.port.mk>
