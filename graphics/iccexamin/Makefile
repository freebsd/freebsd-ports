# $FreeBSD$

PORTNAME=	iccexamin
PORTVERSION=	0.55
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/oyranos/ICC%20Examin/ICC%20Examin%20${PORTVERSION}
DISTNAME=	icc_examin-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	ICC profile viewer and colour visualisation

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libftgl.so:graphics/ftgl \
		liblcms.so:graphics/lcms \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		liboyranos.so:graphics/oyranos

MAKE_JOBS_UNSAFE=	yes
USES=		desktop-file-utils gettext iconv jpeg pkgconfig tar:bzip2
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_XORG=	#
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
