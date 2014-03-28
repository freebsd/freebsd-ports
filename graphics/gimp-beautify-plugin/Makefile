# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beautify
PORTVERSION=	2012.08.12.00
CATEGORIES=	graphics
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GIMP plug-ins to both quickly and easily beautify photo

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:${PORTSDIR}/print/freetype2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:${PORTSDIR}/graphics/gimp-app
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:${PORTSDIR}/x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:${PORTSDIR}/print/freetype2 \
		${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:${PORTSDIR}/graphics/gimp-app

USE_GITHUB=	yes
GH_ACCOUNT=	hejiann
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	e209c8d

USES=		gettext gmake
USE_GCC=	yes
USE_GNOME=	atk cairo gdkpixbuf2 gtk20
USE_XORG=	x11 xcomposite xcursor xdamage xext xfixes xi xinerama xrandr xrender

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins/
PLUGINS=	beautify \
		border \
		simple-border \
		skin-whitening

# installed files
.for plugin in ${PLUGINS}
PLIST_FILES+=	${PLUGIN_DIR}/${plugin}
.endfor

# installed dirs
PLIST_DIRSTRY=	libexec/gimp/2.2/plug-ins \
		libexec/gimp/2.2 \
		libexec/gimp

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
