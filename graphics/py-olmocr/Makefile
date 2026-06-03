PORTNAME=	olmocr
DISTVERSION=	0.4.27
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PDF and image OCR toolkit using visual language models
WWW=		https://olmocr.allenai.org/ \
		https://github.com/allenai/olmocr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	pdftoppm:graphics/poppler-utils \
		${PYTHON_PKGNAMEPREFIX}bleach>0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cached-path>0:devel/py-cached-path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ftfy>0:textproc/py-ftfy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lingua-language-detector>0:textproc/py-lingua-language-detector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>0:textproc/py-markdown2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdownify>0:textproc/py-markdownify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf>=5.2.0:print/py-pypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdfium2>0:graphics/py-pypdfium2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}smart-open>0:net/py-smart-open@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>0:archivers/py-zstandard@${PY_FLAVOR}
RUN_DEPENDS_gpu=	\
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.57.3:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vllm>=0.11.2:misc/py-vllm@${PY_FLAVOR}
RUN_DEPENDS+=	${RUN_DEPENDS_gpu}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
