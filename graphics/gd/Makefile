# Created by: jeff@cetlink.net
# $FreeBSD$

PORTNAME=	libgd
PORTVERSION=	2.2.3
PORTREVISION?=	1
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/gd-${PORTVERSION}/

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	Graphics library for fast creation of images

LICENSE=	MIT

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

CONFLICTS=	bazaar-1.*

USES=		tar:xz pkgconfig pathfix libtool:keepla shebangfix jpeg
SHEBANG_FILES=	${WRKSRC}/src/bdftogd
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	FONTCONFIG ICONV XPM WEBP
OPTIONS_DEFAULT=FONTCONFIG WEBP
NO_OPTIONS_SORT=yes
FONTCONFIG_LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_OFF=	--with-fontconfig=no
ICONV_USES=	iconv
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
XPM_USE=	xorg=xpm,x11
XPM_CONFIGURE_ON=	--with-x
XPM_CONFIGURE_OFF=	--with-xpm=no
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_OFF=	--without-webp

.include <bsd.port.options.mk>

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
		${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MICONV}
	${REINPLACE_CMD} \
		-e 's|iconv|noiconv|' \
		${WRKSRC}/configure
.endif

.if defined(GD_FONTS)
pre-build:
	cd ${WRKFONTS} && ${SH} ${FILESDIR}/makefonts build ${GD_FONTS}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/gdhelpers.h \
		${STAGEDIR}${PREFIX}/include/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgd.so.6.0.3

.include <bsd.port.mk>
