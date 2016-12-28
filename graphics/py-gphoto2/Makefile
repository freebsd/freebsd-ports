# $FreeBSD$

PORTNAME=	gphoto2
PORTVERSION=	1.5.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python-gphoto2

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Python bindings for libgphoto2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} \
		-e 's|share/python-gphoto2/examples|${EXAMPLESDIR:S,${PREFIX}/,,}|' \
		-e 's|share/python-gphoto2|${DOCSDIR:S,${PREFIX}/,,}|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
