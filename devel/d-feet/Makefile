# Created by: Thinker K.F. Li <thinker@eeebox.branda.to>
# $FreeBSD$

PORTNAME=	d-feet
PORTVERSION=	0.1.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/d-feet/0.1

MAINTAINER=	thinker@codemud.net
COMMENT=	D-Feet is a D-Bus debugger written in PyGtk+ by John (J5) Palmieri

RUN_DEPENDS=	\
	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2 \
	${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
