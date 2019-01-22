# Created by: ports@c0decafe.net <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	thunar-archive-plugin
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	archivers xfce
MASTER_SITES=	XFCE/src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Archive plugin for the Thunar File Manager

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gtk20 intltool
USE_XFCE=	libexo thunar

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
