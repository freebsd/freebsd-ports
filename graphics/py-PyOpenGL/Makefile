# Created by: Randall Hopper <aa8vb@ipass.net>
# $FreeBSD$

PORTNAME=	PyOpenGL
PORTVERSION=	3.1.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	PyOpenGL-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	OpenGL (and related library) interface for Python

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	TKINTER
OPTIONS_DEFAULT=	TKINTER
TKINTER_DESC=	Build with tkinter for X support

USES=		dos2unix python
USE_GL=		glut
USE_PYTHON=	distutils autoplist

TKINTER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter
TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	${REINPLACE_CMD} -e 's|posix |posix|g' ${WRKSRC}/OpenGL/__init__.py

.include <bsd.port.mk>
