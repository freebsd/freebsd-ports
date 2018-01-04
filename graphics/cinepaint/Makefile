# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	cinepaint
DISTVERSION=	1.0-4
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/CinePaint/CinePaint-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editing tool used for painting and retouching of movies

LICENSE=	GPLv2 LGPL21 MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR \
		libftgl.so:graphics/ftgl \
		liblcms.so:graphics/lcms \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libHalf.so:graphics/ilmbase \
		libXcm.so:x11/libXcm

BROKEN_powerpc64=	fails to link: ld: undefined reference to symbol __gxx_personality_v0(try adding -lstdc++)

OPTIONS_DEFINE=	OYRANOS PRINT
OYRANOS_DESC=	ICC profile support via Oyranos
PRINT_DESC=	Gutenprint (gimp-print) plugin

GNU_CONFIGURE=	yes
USES=		autoreconf desktop-file-utils gettext ghostscript:run \
		gmake jpeg libtool pkgconfig python
USE_XORG=	ice sm x11 xcursor xext xfixes xmu xft xt xinerama xrender
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VER="${DISTVERSION}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOYRANOS}
LIB_DEPENDS+=	libOyranos.so:graphics/oyranos
.else
CONFIGURE_ENV+=	ac_cv_path_OY_CONFIG=no
.endif

.if ${PORT_OPTIONS:MPRINT}
LIB_DEPENDS+=	libgutenprint.so:print/gutenprint
PLIST_SUB+=	PRINT=""
.else
CONFIGURE_ARGS+=	--disable-print
PLIST_SUB+=	PRINT="@comment "
.endif

post-extract:
	@${LN} -sf gimprc.in ${WRKSRC}/cinepaintrc.in
	@${LN} -sf gimprc_user.in ${WRKSRC}/cinepaintrc_user.in

post-patch:
	@${REINPLACE_CMD} -e \
		'/^pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata| ; \
		 s|gimprc|cinepaintrc|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e \
		'/cms-profile-path/s|".*"|"${LOCALBASE}/share/color/icc"| ; \
		 s|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/gimprc.in
	@${REINPLACE_CMD} -e \
		's|gimprc|cinepaintrc|g' \
		${WRKSRC}/user_install.in
	@${REINPLACE_CMD} -e \
		's|static GDrawableType|static GImageType|' \
		${WRKSRC}/plug-ins/psd/psd.c

.include <bsd.port.mk>
