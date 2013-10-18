# Created by: Andrey V. Elsukov <bu7cher@yandex.ru>
# $FreeBSD$

PORTNAME=	danpei
PORTVERSION=	2.9.7
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Image Viewer for X Window System with thumbnail preview feature

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

.if !defined(WITHOUT_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

USES=		gettext
USE_GNOME=	gtk12 gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--without-included-gettext

NO_STAGE=	yes
.include <bsd.port.mk>
