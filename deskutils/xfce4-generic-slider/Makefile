PORTNAME=	xfce4-generic-slider
PORTVERSION=	g20230204
PORTEPOCH=	1
CATEGORIES=	deskutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Slider plugin to adjust and/or monitor any numeric variable
WWW=		https://gitlab.xfce.org/panel-plugins/xfce4-generic-slider

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdt-autogen:devel/xfce4-dev-tools
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext gmake gnome libtool pkgconfig xfce:gtk3
USE_GITLAB=	yes
GL_SITE=	https://gitlab.xfce.org
GL_ACCOUNT=	panel-plugins
GL_COMMIT=	158b29bf84d2a4be150fe7ac278c605eb5309c0c
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	libmenu panel

CONFIGURE_ARGS=	CC="${CC}"
PLIST_FILES=	lib/xfce4/panel/plugins/libgeneric-slider.so \
		share/xfce4/panel/plugins/generic-slider.desktop

pre-configure:
	(cd ${WRKSRC} && ./autogen.sh ${CONFIGURE_ARGS})

.include <bsd.port.mk>
