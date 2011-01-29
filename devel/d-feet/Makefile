# New ports collection makefile for:	d-feet
# Date created:		2010-09-11
# Whom:			Thinker K.F. Li <thinker@eeebox.branda.to>
#
# $FreeBSD$
#

PORTNAME=	d-feet
PORTVERSION=	0.1.12
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/d-feet/0.1

#PKGNAMEPREFIX=
#PKGNAMESUFFIX=
#DISTNAME=
#EXTRACT_SUFX=
#DISTFILES=
#DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=
MAINTAINER=	thinker@codemud.net
COMMENT=	D-Feet is a D-Bus debugger written in PyGtk+ by John (J5) Palmieri

RUN_DEPENDS=	\
	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2 \
	${PYTHON_SITELIBDIR}/dbus/bus.py:${PORTSDIR}/devel/py-dbus

USE_GTK=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
