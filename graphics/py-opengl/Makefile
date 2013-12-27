# Created by: Randall Hopper <aa8vb@ipass.net>
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	3.0.1
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	SF/py${PORTNAME}/PyOpenGL/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyOpenGL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL (and related library) interface for Python

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

OPTIONS_DEFINE=	TKINTER
OPTIONS_DEFAULT=	TKINTER
TKINTER_DESC=	Build with tkinter for X support
OPTIONSFILE?=	${PORT_DBDIR}/${PORTNAME}/options

USES=		dos2unix
USE_GL=		glut
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTKINTER}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	${REINPLACE_CMD} -e 's|posix |posix|g' ${WRKSRC}/OpenGL/__init__.py

.include <bsd.port.post.mk>
