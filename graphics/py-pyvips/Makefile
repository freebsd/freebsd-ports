PORTNAME=	pyvips
PORTVERSION=	2.2.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Binding for the libvips image processing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.13:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0,1:devel/py-pkgconfig@${PY_FLAVOR}
LIB_DEPENDS=	libvips.so:graphics/vips
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.13:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0,1:devel/py-pkgconfig@${PY_FLAVOR}

USES=		gnome python:3.6+
USE_GNOME=	glib20
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
