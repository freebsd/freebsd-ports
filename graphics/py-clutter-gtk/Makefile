# New ports collection makefile for:	py-clutter-gtk
# Date created:		04 Sep 2009
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/py-clutter-gtk/Makefile,v 1.3 2010/02/15 10:36:26 kwm Exp $
#

PORTNAME=	clutter
PORTVERSION=	0.10.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/pyclutter-gtk/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	gtk
DISTNAME=	py${PORTNAME}-gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python modules for Clutter-gtk toolkit

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${LOCALBASE}/libdata/pkgconfig/pyclutter-1.0.pc:${PORTSDIR}/graphics/py-clutter
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${LOCALBASE}/libdata/pkgconfig/pyclutter-1.0.pc:${PORTSDIR}/graphics/py-clutter
LIB_DEPENDS=	clutter-gtk-0.10:${PORTSDIR}/graphics/clutter-gtk

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack pygnome2 pygtk2
USE_PYTHON=	2.5+
CONFIGURE_ARGS=	--disable-docs
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
