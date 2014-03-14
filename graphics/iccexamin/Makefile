# $FreeBSD$

PORTNAME=	iccexamin
PORTVERSION=	0.54
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/oyranos/ICC%20Examin/ICC%20Examin%20${PORTVERSION}
DISTNAME=	icc_examin-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	ICC profile viewer and colour visualisation

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libftgl.so:${PORTSDIR}/graphics/ftgl \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liboyranos.so:${PORTSDIR}/graphics/oyranos

MAKE_JOBS_UNSAFE=	yes
USES=		gettext iconv pkgconfig
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_XORG=	#
CONFIGURE_ARGS+=--mandir=${PREFIX}/man

post-patch:
	@${REINPLACE_CMD} 's:\\$$(iconv):${ICONV_LIB}:' \
		${WRKSRC}/configure ${WRKSRC}/fl_i18n/makefile.in
	@${REINPLACE_CMD} 's:-xdg:#-xdg:' ${WRKSRC}/makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/icc_examin.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/iccexamin.png

.include <bsd.port.mk>
