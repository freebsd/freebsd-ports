PORTNAME=	pdf2image
PORTVERSION=	1.17.0
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Wrapper to convert pdf to a pil image list
WWW=		https://github.com/Belval/pdf2image

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		pdftocairo:graphics/poppler-utils \
		pdftoppm:graphics/poppler-utils

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
