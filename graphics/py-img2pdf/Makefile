# $FreeBSD$

PORTNAME=	img2pdf
DISTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Convert images to PDF via direct JPEG inclusion

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_ENUM34} \
		${PY_PILLOW}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdfrw>0:textproc/py-pdfrw@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# Note: The tests only work with Python 3, see also:
# https://gitlab.mister-muffin.de/josch/img2pdf/issues/60
do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
