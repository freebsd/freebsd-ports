# New ports collection makefile for:	PyOpenGL
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	opengl
PORTVERSION=	1.5.6
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	py-
DISTNAME=	PyOpenGL-${PORTVERSION:S/.b/b/}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/numpy \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/numpy \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_MESA=	yes

OSMAJOR!=	/usr/bin/uname -r | sed -e 's/\..*//'
PLIST_SUB+=	OSMAJOR=${OSMAJOR}

SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-configure:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/config.py ${WRKSRC}/Tkinter.py

do-build:
	${SETUP_CMD} build

do-install:        
	${SETUP_CMD} install

post-install:
	${LOCALBASE}/bin/tclsh8.3 ${WRKSRC}/register.tcl

.include <bsd.port.mk>
