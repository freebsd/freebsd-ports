PORTNAME=	gphoto2
PORTVERSION=	2.5.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Python bindings for libgphoto2
WWW=		https://pypi.org/project/gphoto2/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

USES=		pkgconfig python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	examples/*.py

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_MAKE_ENV=	WITH_EXAMPLES=yes

.include <bsd.port.mk>
