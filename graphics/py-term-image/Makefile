PORTNAME=	term-image
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	term_image-${DISTVERSION}

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Display images in the terminal with Python
WWW=		https://github.com/AnonymouX47/term-image \
		https://pypi.org/project/term-image

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=9.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.23<3:www/py-requests@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils flavors

NO_ARCH=	yes

.include <bsd.port.mk>
