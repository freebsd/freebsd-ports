# New ports collection makefile for:	ja-libtomoe-gtk
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtomoe-gtk
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	SF/tomoe/tomoe-gtk/tomoe-gtk-${PORTVERSION}
DISTNAME=	tomoe-gtk-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	TOMOE GTK+ library

LIB_DEPENDS=	tomoe.1:${PORTSDIR}/japanese/tomoe

USE_GNOME=	lthack gnomehack gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

#OPTIONS=	GUCHARMAP	"Compile with gucharmap"		on

.include <bsd.port.pre.mk>

#.if defined(WITHOUT_GUCHARMAP)
CONFIGURE_ARGS+=--with-gucharmap=no
PLIST_SUB+=	GUCHARMAP="@comment "
#.else
#LIB_DEPENDS+=	gucharmap.6:${PORTSDIR}/deskutils/gucharmap
#PLIST_SUB+=	GUCHARMAP=""
#.endif

.if exists(${LOCALBASE}/libdata/pkgconfig/pytomoe.pc)
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION:S;python;;} \
		pyexecdir=${PYTHON_SITELIBDIR}
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--with-python=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.post.mk>
