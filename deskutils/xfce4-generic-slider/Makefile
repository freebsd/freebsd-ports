PORTNAME=	xfce4-generic-slider
PORTVERSION=	1.0.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Slider plugin to adjust and/or monitor any numeric variable
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-generic-slider

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	libmenu panel

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
