# Created by: jeff@cetlink.net
# $FreeBSD$

PORTNAME=	libgd
PORTVERSION=	2.1.0
PORTREVISION?=	7
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	https://bitbucket.org/libgd/gd-libgd/downloads/ \
		http://cdn.bitbucket.org/libgd/gd-libgd/downloads/

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	Graphics library for fast creation of images

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

CONFLICTS=	bazaar-1.*

USES=		jpeg libtool:keepla pathfix pkgconfig shebangfix tar:xz
SHEBANG_FILES=	${WRKSRC}/src/bdftogd
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	FONTCONFIG ICONV VPX XPM
OPTIONS_DEFAULT=FONTCONFIG
NO_OPTIONS_SORT=yes
FONTCONFIG_LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_OFF=	--with-fontconfig=no
ICONV_USES=	iconv
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_OFF=	--without-vpx
XPM_USE=	xorg=xpm,x11
XPM_CONFIGURE_ON=	--with-x
XPM_CONFIGURE_OFF=	--with-xpm=no

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
		-e 's|GDLIB_CURRENT=.*|GDLIB_CURRENT=5|' \
		${WRKSRC}/configure
	# workaround for broken configure
.if ! ${PORT_OPTIONS:MICONV}
	${REINPLACE_CMD} \
		-e 's|iconv|noiconv|' \
		${WRKSRC}/configure
.endif
.if ! ${PORT_OPTIONS:MXPM}
	${REINPLACE_CMD} \
		-e 's|xpm|noxpm|' \
		${WRKSRC}/configure
.endif
.if ! ${PORT_OPTIONS:MFONTCONFIG}
	${REINPLACE_CMD} \
		-e 's|fontconfig|nofontconfig|' \
		${WRKSRC}/configure
.endif

.if defined(GD_FONTS)
pre-build:
	cd ${WRKFONTS} && ${SH} ${FILESDIR}/makefonts build ${GD_FONTS}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/gdhelpers.h \
		${STAGEDIR}${PREFIX}/include/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgd.so.5

.include <bsd.port.mk>
