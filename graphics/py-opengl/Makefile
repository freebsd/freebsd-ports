# New ports collection makefile for:	PyOpenGL
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	opengl
PORTVERSION=	2.0.0.44
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	py-
DISTNAME=	PyOpenGL-${PORTVERSION:S/.b/b/}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		swig:${PORTSDIR}/devel/swig11
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_MESA=	yes

OSMAJOR!=	/usr/bin/uname -r | sed -e 's/\..*//'
PLIST_SUB+=	OSMAJOR=${OSMAJOR} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

pre-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc[.]h|stdlib.h|g'

do-configure:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/config/freebsd.cfg ${WRKSRC}/Tkinter.py

post-install:
	${LOCALBASE}/bin/tclsh8.3 ${WRKSRC}/register.tcl

.include <bsd.port.mk>
