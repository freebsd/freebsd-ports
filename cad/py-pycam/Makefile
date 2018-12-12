# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pycam
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	cad python
MASTER_SITES=	SOURCEFORGE/pycam/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Toolpath generator for 3-axis CNC machining

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:x11-toolkits/py-gtk2@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:x11-toolkits/py-gtkglext@${PY_FLAVOR}

USES=		python:-2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
