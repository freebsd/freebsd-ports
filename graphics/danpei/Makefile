# ports collection makefile for: 	danpei
# Date created:         		4 Fev 2005
# Whom:                 		Andrey V. Elsukov <bu7cher@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	danpei
PORTVERSION=	2.9.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	danpei

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	Image Viewer for X Window System with thumbnail preview feature

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

.if !defined(WITHOUT_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

USE_X_PREFIX=	yes
USE_GNOME=	gtk12 gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
