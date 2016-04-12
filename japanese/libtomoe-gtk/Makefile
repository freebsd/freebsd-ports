# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtomoe-gtk
PORTVERSION=	0.6.0
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	SF/tomoe/tomoe-gtk/tomoe-gtk-${PORTVERSION}
DISTNAME=	tomoe-gtk-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	TOMOE GTK+ library

LIB_DEPENDS=	libtomoe.so:japanese/tomoe

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

#OPTIONS=	GUCHARMAP	"Compile with gucharmap"		on

.include <bsd.port.options.mk>

#.if defined(WITHOUT_GUCHARMAP)
CONFIGURE_ARGS+=--with-gucharmap=no
PLIST_SUB+=	GUCHARMAP="@comment "
#.else
#LIB_DEPENDS+=	libgucharmap.so:deskutils/gucharmap
#PLIST_SUB+=	GUCHARMAP=""
#.endif

.if exists(${LOCALBASE}/libdata/pkgconfig/pytomoe.pc)
USES+=		python
CONFIGURE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION:S;python;;} \
		pyexecdir=${PYTHON_SITELIBDIR}
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--with-python=no
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.mk>
