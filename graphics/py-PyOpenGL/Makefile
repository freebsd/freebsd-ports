PORTNAME=	PyOpenGL
PORTVERSION=	3.1.7
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	PyOpenGL-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	OpenGL (and related library) interface for Python
WWW=		https://pyopengl.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PY_PILLOW}
RUN_DEPENDS=	${PYNUMPY} \
		${PY_PILLOW}

NO_ARCH=	yes

OPTIONS_DEFINE=	TKINTER
OPTIONS_DEFAULT=	TKINTER
TKINTER_DESC=	Build with tkinter for X support

USES=		dos2unix gl python
USE_GL=		glut
USE_PYTHON=	distutils autoplist

TKINTER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	${REINPLACE_CMD} -e 's|posix |posix|g' ${WRKSRC}/OpenGL/__init__.py

.include <bsd.port.mk>
