PORTNAME=	pytesseract
PORTVERSION=	0.3.9
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	wrapper for Google's Tesseract OCR engine

PATCH_STRIP=	-p1

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	tesseract:graphics/tesseract \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
TEST_DEPENDS=	${RUN_DEPENDS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}
		# if py-tox cannot detect py-filelock, be sure to have version 3.4.2_1 of the latter

USES=		localbase python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	madmaze
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} tox-${PYTHON_VER} -e ${PY_FLAVOR} --sitepackages

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 30800
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
