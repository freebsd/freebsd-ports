# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beautify
PORTVERSION=	2012.08.12.00
PORTREVISION=	6
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP plug-ins to both quickly and easily beautify photo

LICENSE=	GPLv3+

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:print/freetype2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:print/freetype2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app

USE_GITHUB=	yes
GH_ACCOUNT=	hejiann
GH_TAGNAME=	e209c8d

USES=		gettext gmake pkgconfig
USE_GCC=	yes
USE_GNOME=	atk cairo gdkpixbuf2 gtk20
USE_XORG=	x11 xcomposite xcursor xdamage xext xfixes xi xinerama xrandr xrender
TMPDIR=		${WRKDIR}

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLUGINS=	beautify \
		border \
		simple-border \
		skin-whitening

# installed files
.for plugin in ${PLUGINS}
PLIST_FILES+=	${PLUGIN_DIR}/${plugin}
.endfor

post-patch:
	@${REINPLACE_CMD} \
		-e 's|gimptool-2.0|${LOCALBASE}/bin/gimptool-2.0|' \
		-e 's|gdk-pixbuf-csource|${LOCALBASE}/bin/gdk-pixbuf-csource|' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.for plugin in ${PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${plugin} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>
