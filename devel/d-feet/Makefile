# Created by: Thinker K.F. Li <thinker@eeebox.branda.to>
# $FreeBSD$

PORTNAME=	d-feet
PORTVERSION=	0.1.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME/sources/d-feet/0.1

MAINTAINER=	thinker@codemud.net
COMMENT=	D-Feet is a D-Bus debugger written in PyGtk+ by John (J5) Palmieri

RUN_DEPENDS=	\
	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2 \
	${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
