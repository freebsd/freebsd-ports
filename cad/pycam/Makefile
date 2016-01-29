# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycam
PORTVERSION=	0.5.1
CATEGORIES=	cad python
MASTER_SITES=	SOURCEFORGE/pycam/${PORTNAME}/${PORTVERSION}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Toolpath generator for 3-axis CNC machining

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
