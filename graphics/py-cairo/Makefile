# New ports collection makefile for:	py-cairo
# Date created:		2004-12-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cairo
PORTVERSION=	0.1.3
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/snapshots/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Python bindings for Cairo

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/MA/__init__.py:${PORTSDIR}/math/py-numeric
LIB_DEPENDS=	cairo.1:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
WANT_GNOME=	yes
USE_LIBTOOL_VER=15

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygtk2}!=""
WITH_PYGTK=	yes
.endif

.if defined(WITHOUT_PYGTK) && !defined(WITH_PYGTK)
PLIST_SUB+=	GTK="@comment "
.else
USE_GNOME=	pygtk2
PLIST_SUB+=	GTK=""
.endif

.include <bsd.port.post.mk>
