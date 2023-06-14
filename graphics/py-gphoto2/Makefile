PORTNAME=	gphoto2
PORTVERSION=	2.3.4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python-gphoto2

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Python bindings for libgphoto2
WWW=		https://pypi.org/project/gphoto2/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

USES=		pkgconfig python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	examples/*.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/-O3/d' \
		-e 's|share/python-gphoto2/examples|${EXAMPLESDIR_REL}|' \
		-e 's|share/python-gphoto2|${DOCSDIR_REL}|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
