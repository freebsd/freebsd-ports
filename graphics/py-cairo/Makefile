# New ports collection makefile for:	py-cairo
# Date created:		2004-12-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cairo
PORTVERSION=	0.4.0
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/snapshots/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Python bindings for Cairo

BUILD_DEPENDS=	${PYNUMERIC}
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

.if defined(WITH_SVG) || exists(${LOCALBASE}/lib/libsvg-cairo.a)
LIB_DEPENDS+=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo
PLIST_SUB+=	SVG=""
.else
PLIST_SUB+=	SVG="@comment "
.endif

pre-everything::
	@${ECHO_MSG} "Enable SVG support by defining WITH_SVG"
	@${ECHO_MSG} "Enable PyGtk support by defining WITH_PYGTK"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
