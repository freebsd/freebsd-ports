# Created by: jeff@cetlink.net
# $FreeBSD$

PORTNAME=	libgd
PORTVERSION=	2.1.0
PORTREVISION?=	1
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://cdn.bitbucket.org/libgd/gd-libgd/downloads/

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

CONFLICTS=	bazaar-1.*

USE_XZ=		yes
USES=		pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_ENV=	PKG_CONFIG_LIBDIR=${LOCALBASE}/libdata/pkgconfig
GNU_CONFIGURE_ARGS=
USE_LDCONFIG=	yes
WANT_PERL=	yes

OPTIONS_DEFINE=	FONTCONFIG ICONV VPX XPM
OPTIONS_DEFAULT=FONTCONFIG
NO_OPTIONS_SORT=yes

.include <bsd.port.options.mk>

PKGCONFIGDIR?=	${LOCALBASE}/libdata/pkgconfig
# force gdlib-config --ldflags
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${PORT_OPTIONS:MFONTCONFIG}
LIB_DEPENDS+=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig
.else
GNU_CONFIGURE_ARGS+=	--with-fontconfig=no
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
GNU_CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}
.else
GNU_CONFIGURE_ARGS+=	--without-libiconv
GNU_CONFIGURE_ARGS+=	--with-libiconv-prefix=no
.endif

.if ${PORT_OPTIONS:MVPX}
LIB_DEPENDS+=	vpx:${PORTSDIR}/multimedia/libvpx
.else
CONFIGURE_ARGS+=	--without-vpx
.endif

# honor global WITHOUT_X11
.if !defined(WITHOUT_X11)
.if ${PORT_OPTIONS:MXPM}
USE_XORG=	xpm x11
GNU_CONFIGURE_ARGS+=	--with-x
.else
GNU_CONFIGURE_ARGS+=	--with-xpm=no
.endif
.endif

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
USE_PERL5_BUILD=	yes
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
	# force PKGCONFIGDIR
	${REINPLACE_CMD} \
		-e 's|^pkgconfigdir =.*|pkgconfigdir = ${PKGCONFIGDIR}|' \
		${WRKSRC}/config/Makefile.in
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
		${PREFIX}/include/

.include <bsd.port.mk>
