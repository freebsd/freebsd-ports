# Created by: jeff@cetlink.net

PORTNAME=	libgd
PORTVERSION=	2.3.3
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/gd-${PORTVERSION}/

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	Graphics library for fast creation of images

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	libgd ??-libgd

USES=		cpe tar:xz pkgconfig pathfix libtool:keepla shebangfix
SHEBANG_FILES=	${WRKSRC}/src/bdftogd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gd-formats
TMPDIR?=	/tmp
MAKE_ENV=	TMPDIR=${TMPDIR}
SUB_FILES=	gdlib-config
USE_LDCONFIG=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	PNG JPEG WEBP HEIF AVIF TIFF FREETYPE FONTCONFIG RAQM XPM ICONV
OPTIONS_DEFAULT=PNG JPEG WEBP TIFF FREETYPE FONTCONFIG ICONV
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_OFF=	--without-png
PNG_CPPFLAGS=		-I${LOCALBASE}/include
JPEG_USES=		jpeg
JPEG_CONFIGURE_OFF=	--without-jpeg
JPEG_CPPFLAGS=		-I${LOCALBASE}/include
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_OFF=	--without-webp
WEBP_CPPFLAGS=		-I${LOCALBASE}/include
HEIF_DESC=	HEIF image format support
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_CONFIGURE_OFF=	--without-heif
HEIF_CPPFLAGS=		-I${LOCALBASE}/include
AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_CONFIGURE_OFF=	--without-avif
AVIF_CPPFLAGS=		-I${LOCALBASE}/include
AVIF_USES=		autoreconf
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_OFF=	--without-tiff
TIFF_CPPFLAGS=		-I${LOCALBASE}/include
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_OFF=	--without-freetype
FREETYPE_CPPFLAGS=	-I${LOCALBASE}/include
FONTCONFIG_LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_OFF=	--with-fontconfig=no
FONTCONFIG_CPPFLAGS=		-I${LOCALBASE}/include
RAQM_DESC=	Raqm text layout support
RAQM_LIB_DEPENDS=	libraqm.so:print/libraqm
RAQM_CONFIGURE_OFF=	--with-raqm=no
RAQM_CPPFLAGS=	-I${LOCALBASE}/include
XPM_USES=	xorg
XPM_USE=	xorg=xpm,x11
XPM_CONFIGURE_ON=	--with-x
XPM_CONFIGURE_OFF=	--with-xpm=no
ICONV_USES=	iconv
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
# bin/annotate
CONFLICTS_INSTALL+=	mummer
.endif

# force gdlib-config --ldflags
LDFLAGS+=	-L${LOCALBASE}/lib

# The GD_FONTS environment variable can be set to specify the gzipped
# tar-ball containing the fonts in bdf format and the bdf file names.
# The tarball is the first argument, the tiny, small, medium-bold,
# large, and giant fonts follow.
#
# For example:
# GD_FONTS="/usr/ports/distfiles/x-koi8u.tgz koi6x10.bdf koi8x13.bdf \
#       koi9x15.bdf koi12x24.bdf koi10x20.bdf"
#
.if defined(GD_FONTS)
USES+=		perl5
USE_PERL5=	build
WRKFONTS=	${WRKSRC}/src
.endif

pre-extract::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "GD_FONTS can be set to specify an alternative list of .bdf files"
	@${ECHO_MSG} ""

post-extract:
.if defined(GD_FONTS)
	cd ${WRKFONTS} && ${SH} ${FILESDIR}/makefonts extract ${GD_FONTS}
.endif

pre-configure:
.if defined(GD_FONTS)
	cd ${WRKFONTS} && ${SH} ${FILESDIR}/makefonts configure ${GD_FONTS}
.endif
	# bump shlib version
	${REINPLACE_CMD} \
		-e 's|^GDLIB_LT_CURRENT=3|GDLIB_LT_CURRENT=6|' \
		${WRKSRC}/configure ${WRKSRC}/config/getlib.sh

pre-configure-ICONV-off:
	${REINPLACE_CMD} \
		-e 's|iconv|noiconv|' \
		${WRKSRC}/configure

.if defined(GD_FONTS)
pre-build:
	cd ${WRKFONTS} && ${SH} ${FILESDIR}/makefonts build ${GD_FONTS}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/gdhelpers.h \
		${STAGEDIR}${PREFIX}/include/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgd.so.6*
	${INSTALL_SCRIPT} ${WRKDIR}/gdlib-config \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
