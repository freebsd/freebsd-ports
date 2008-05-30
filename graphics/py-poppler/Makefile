# New ports collection makefile for:	py-poppler
# Date created:		2008-04-14
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	poppler
PORTVERSION=	0.6.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.gnome.org/~gianmt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	romain@blogreen.org
COMMENT=	Python bindings for the Poppler PDF rendering library

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/poppler-glib.pc:${PORTSDIR}/graphics/poppler-gtk \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo \
		${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:${PORTSDIR}/x11-toolkits/py-gtk2

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig atk

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
