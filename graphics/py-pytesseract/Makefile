PORTNAME=	pytesseract
PORTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	wrapper for Google's Tesseract OCR engine

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	tesseract:graphics/tesseract \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
TEST_DEPENDS=	tesseract:graphics/tesseract \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		localbase python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} tox

.include <bsd.port.mk>
