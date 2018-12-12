# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimmage
PORTVERSION=	0.2.3
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Simple image viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to configure: C++ compiler cannot create executables

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang desktop-file-utils gettext pkgconfig
USE_GNOME=	gtkmm24 gdkpixbuf2
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	gettext

CXXFLAGS+=	-stdlib=libc++ -Wc++11-extensions -Wc++11-long-long \
		-Wunused-command-line-argument -Wreturn-type \
		-Wwritable-strings -Wlogical-op-parentheses
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.mk>
