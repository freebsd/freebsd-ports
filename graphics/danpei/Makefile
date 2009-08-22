# ports collection makefile for: 	danpei
# Date created:         		4 Fev 2005
# Whom:                 		Andrey V. Elsukov <bu7cher@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	danpei
PORTVERSION=	2.9.7
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	Image Viewer for X Window System with thumbnail preview feature

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

.if !defined(WITHOUT_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

USE_GETTEXT=	yes
USE_GNOME=	gtk12 gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--without-included-gettext

.include <bsd.port.mk>
