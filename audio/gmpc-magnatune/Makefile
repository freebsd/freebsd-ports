# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-magnatune
PORTVERSION=	11.8.16
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Magnatune plugin lets you preview music from Magnatune

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpd.so:audio/libmpd \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:audio/gmpc
RUN_DEPENDS=	gmpc:audio/gmpc

USES=		gettext gmake gnome libtool pkgconfig sqlite
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 intltool libglade2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/gmpc/plugins/magnatuneplugin.so \
		share/gmpc/plugins/magnatune/magnatune.png

.include <bsd.port.mk>
