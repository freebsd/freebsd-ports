PORTNAME=	pytesseract
PORTVERSION=	0.3.7
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	wrapper for Google's Tesseract OCR engine

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	tesseract:graphics/tesseract

USES=		localbase python:3.4+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
