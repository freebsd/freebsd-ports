# New ports collection makefile for:	py-clutter
# Date created:		2008-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/py-clutter/Makefile,v 1.8 2010/08/26 21:06:34 marcus Exp $
#

PORTNAME=	clutter
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	http://www.clutter-project.org/sources/pyclutter/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python modules for Clutter toolkit

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo
LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

BROKEN=		bad plist

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		gettext
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pygnome2 pygtk2
USE_PYTHON=	2.5+
CONFIGURE_ARGS=	--disable-docs

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
