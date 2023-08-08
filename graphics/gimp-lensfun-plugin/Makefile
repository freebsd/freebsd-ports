PORTNAME=	lensfun
DISTVERSION=	0.2.5-dev
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Gimp plugin to correct lens distortion using the lensfun library
WWW=		https://seebk.github.io/GIMP-Lensfun/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/exiv2.pc:graphics/exiv2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app \
		${LOCALBASE}/libdata/pkgconfig/lensfun.pc:graphics/lensfun

LIB_DEPENDS+=	libatk-1.0.so:accessibility/at-spi2-core \
		libbabl-0.1.so:x11/babl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgegl-0.4.so:graphics/gegl \
		libgegl-npd-0.4.so:graphics/gegl \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		compiler:c++11-lang gettext-runtime gmake gnome pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	seebk
GH_PROJECT=	GIMP-Lensfun
GH_TAGNAME=	c5eaf97

USE_GNOME+=	cairo gdkpixbuf2 glib20 gtk20 pango

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLUGINS=	gimp-lensfun

# installed files
.for plugin in ${PLUGINS}
PLIST_FILES+=	${PLUGIN_DIR}/${plugin}
.endfor

post-patch:
	@${REINPLACE_CMD} \
		-e 's|gimptool-2.0|${LOCALBASE}/bin/gimptool-2.0|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${plugin} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>
