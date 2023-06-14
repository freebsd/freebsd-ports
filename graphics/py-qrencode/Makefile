PORTNAME=	qrencode
PORTVERSION=	1.2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Simple wrapper for the C qrencode library
WWW=		https://github.com/Arachnid/pyqrencode/tree/master

LICENSE=	MIT

BUILD_DEPENDS=	libqrencode>0:graphics/libqrencode
RUN_DEPENDS=	libqrencode>0:graphics/libqrencode
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CFLAGS+=	-I${PREFIX}/include

NO_ARCH_IGNORE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
