PORTNAME=	pytesseract
PORTVERSION=	0.3.13
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	wrapper for Google's Tesseract OCR engine
WWW=		https://github.com/madmaze/pytesseract

PATCH_STRIP=	-p1

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	tesseract:graphics/tesseract \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
TEST_DEPENDS=	${RUN_DEPENDS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}
		# if py-tox cannot detect py-filelock, be sure to have version 3.4.2_1 of the latter

USES=		localbase python
USE_GITHUB=	yes
GH_ACCOUNT=	madmaze
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
		# FIXME hack alert. graphics/leptonica by default does not include
		# jpeg2000 (openjpeg) support, and the pytesseract self-test is not
		# smart enough to detect that and skip the test, so let us check
		# and punch out the jpeg2000 test if it is pointless running it.
		# https://github.com/madmaze/pytesseract/issues/419
		@if ${READELF} -d ${LOCALBASE}/lib/liblept.so | ${EGREP} -q '\<NEEDED\>.+\<libopenjp2\.so\.[[:digit:]]' ; then : ; else \
			if [ $$? -ne 1 ] ; then exit 1 ; fi ; \
			${ECHO_MSG} >&2 '===>   liblept.so (graphics/leptonica) is linked without libopenjp2, disabling JPEG2000 test' ; \
			${REINPLACE_CMD} '/jpeg2000/d' ${WRKSRC}/tests/pytesseract_test.py ; \
		fi
		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} tox-${PYTHON_VER} -e ${PY_FLAVOR} --sitepackages

.include <bsd.port.mk>
