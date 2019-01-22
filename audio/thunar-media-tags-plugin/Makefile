# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	thunar-media-tags-plugin
PORTVERSION=	0.2.1
PORTREVISION=	5
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Media tags plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk20 intlhack intltool
USE_XFCE=	libexo thunar

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
