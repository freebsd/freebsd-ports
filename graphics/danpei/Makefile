# Created by: Andrey V. Elsukov <bu7cher@yandex.ru>
# $FreeBSD$

PORTNAME=	danpei
PORTVERSION=	2.9.7
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Image Viewer for X Window System with thumbnail preview feature

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	IMAGEMAGICK
OPTIONS_DEFAULT=IMAGEMAGICK

IMAGEMAGICK_RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USES=		gettext
USE_GNOME=	gtk12 gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--without-included-gettext

PLIST_FILES=	bin/danpei \
		share/locale/de/LC_MESSAGES/danpei.mo \
		share/locale/ja/LC_MESSAGES/danpei.mo

.include <bsd.port.mk>
