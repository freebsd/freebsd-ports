# $FreeBSD$

PORTNAME=	icc-examin
PORTVERSION=	0.56
CATEGORIES=	graphics

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	ICC profile viewer and colour visualisation

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl \
		liblcms2.so:graphics/lcms2 \
		libOyranos.so:graphics/oyranos \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libXcm.so:x11/libXcm 

USE_GITHUB=     yes
GH_ACCOUNT=     oyranos-cms

MAKE_JOBS_UNSAFE=	yes
USES=		desktop-file-utils gettext iconv jpeg pkgconfig
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GL=		gl glu
USE_XORG=	x11 xcursor xext xfixes xft xinerama xpm xrandr xxf86vm
CONFIGURE_ARGS+=--mandir=${PREFIX}/man --disable-openmp

post-patch:
	@${REINPLACE_CMD} 's:\\$$(iconv):${ICONV_LIB}:' \
		${WRKSRC}/configure ${WRKSRC}/fl_i18n/makefile.in
	@${REINPLACE_CMD} 's:-xdg:#-xdg:' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} 's:-mimpure-text::' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/iccexamin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/iccexamin.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/iccexamin.png

.include <bsd.port.mk>
