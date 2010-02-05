# New ports collection makefile for:	py-clutter
# Date created:		2008-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/py-clutter/Makefile,v 1.3 2009/09/26 13:41:59 marcus Exp $
#

PORTNAME=	clutter
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/pyclutter/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python modules for Clutter toolkit

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack pygnome2 pygtk2
USE_PYTHON=	2.5+
CONFIGURE_ARGS=	--disable-docs
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
