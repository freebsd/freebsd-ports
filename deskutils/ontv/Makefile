# New ports collection makefile for:	ontv
# Date created:		2006-07-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/ontv/Makefile,v 1.7 2007/07/23 21:02:59 mezz Exp $
#

PORTNAME=	ontv
PORTVERSION=	2.4.0
PORTREVISION=	10
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME Applet for monitoring current and upcoming TV programs

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte \
		tv_grab_be:${PORTSDIR}/textproc/p5-xmltv

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix pygnomedesktop pygnomeextras
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	ontv.schemas
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
