# New ports collection makefile for:	PyOpenGL
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	opengl
PORTVERSION=	2.0.1.07
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyOpenGL-${PORTVERSION:S/.b/b/}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	An OpenGL (and related library) interface for Python

BUILD_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
#		swig1.3:${PORTSDIR}/devel/swig13
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

OPTIONS=	TKINTER "Build with tkinter for X support" On
OPTIONSFILE?=	${PORT_DBDIR}/${PORTNAME}/options

USE_GL=		yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyOpenGL

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TKINTER)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s|||"
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/config/freebsd.cfg ${WRKSRC}/Tkinter.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/OpenGL -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/OpenGL -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
