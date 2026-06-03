PORTNAME=	markitdown
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Utility tool for converting various files to Markdown
WWW=		https://pypi.org/project/tlv8/

LICENSE=	APACHE20

IGNORE=		run error:No module named 'magika'

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mammoth>=0:converters/py-mammoth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdownify>=0:textproc/py-markdownify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=0:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-pptx>=0:textproc/py-python-pptx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}puremagic>=0:sysutils/py-puremagic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
