# New ports collection makefile for:	py-clutter
# Date created:		2008-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/pyclutter/0.8/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python modules for Clutter toolkit

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
    		${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS=	clutter-glx-0.8:${PORTSDIR}/graphics/clutter \
		clutter-gst-0.8:${PORTSDIR}/multimedia/clutter-gst \
		clutter-cairo-0.8:${PORTSDIR}/graphics/clutter-cairo \
		clutter-gtk-0.8:${PORTSDIR}/graphics/clutter-gtk

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack pygnome2 pygtk2
USE_GSTREAMER=	yes
USE_PYTHON=	2.4+
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
