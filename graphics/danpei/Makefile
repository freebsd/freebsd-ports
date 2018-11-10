# Created by: Andrey V. Elsukov <bu7cher@yandex.ru>
# $FreeBSD$

PORTNAME=	danpei
PORTVERSION=	2.9.7
PORTREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Image Viewer for X Window System with thumbnail preview feature

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

OPTIONS_DEFINE=	IMAGEMAGICK
OPTIONS_DEFAULT=IMAGEMAGICK

IMAGEMAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick6

USES=		gettext
USE_GNOME=	gtk12 gdkpixbuf
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--without-included-gettext

PLIST_FILES=	bin/danpei \
		share/locale/de/LC_MESSAGES/danpei.mo \
		share/locale/ja/LC_MESSAGES/danpei.mo

.include <bsd.port.mk>
