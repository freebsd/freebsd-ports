PORTNAME=	pyocr
DISTVERSION=	0.8
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for OCR engines (Tesseract, Cuneiform, etc)

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW}

USES=		gmake python:3.4+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
