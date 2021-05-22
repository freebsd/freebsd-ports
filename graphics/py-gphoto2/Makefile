PORTNAME=	gphoto2
PORTVERSION=	2.0.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python-gphoto2

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Python bindings for libgphoto2

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

USES=		compiler pkgconfig python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	examples/*.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} \
		-e 's|share/python-gphoto2/examples|${EXAMPLESDIR:S,${PREFIX}/,,}|' \
		-e 's|share/python-gphoto2|${DOCSDIR:S,${PREFIX}/,,}|' \
		${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
EXTRA_PATCHES=	${FILESDIR}/extra-patch-setup.py
.endif

.include <bsd.port.post.mk>
