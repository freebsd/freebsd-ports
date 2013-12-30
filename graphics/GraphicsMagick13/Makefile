# Created by: Ron van Daal
# $FreeBSD$

PORTNAME=	GraphicsMagick
PORTVERSION=	1.3.18
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/1.3/
MASTER_SITE_SUBDIR=	${PORTNAME:L}/${PORTNAME:L}/${PORTVERSION}
PKGNAMESUFFIX=	13

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast image processing tools based on ImageMagick

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2	\
		libpng15.so:${PORTSDIR}/graphics/png		\
		libjbig.so:${PORTSDIR}/graphics/jbigkit		\
		libjasper.so:${PORTSDIR}/graphics/jasper	\
		libjpeg.so:${PORTSDIR}/graphics/jpeg		\
		liblcms.so:${PORTSDIR}/graphics/lcms		\
		libtiff.so:${PORTSDIR}/graphics/tiff		\
		libxml2.so:${PORTSDIR}/textproc/libxml2

CONFLICTS=	GraphicsMagick-1.[12].* GraphicsMagick12-*

OPTIONS_DEFINE=	Q8BIT FPX OPENMP SSE TESTS X11 DOCS

Q8BIT_DESC=	Use 8-bit pixels (speed) instead of 16 (quality)
DPS_DESC=	Enable Display Ghostscript support
TESTS_DESC=	Run bundled self-tests after build

OPTIONS_DEFAULT=FPX DPS OPENMP X11 TESTS DOCS
OPTIONS_SINGLE=	X11
OPTIONS_SINGLE_X11=	DPS

PORTSCOUT=	limit:^1\.3\.

USES=		iconv
USE_AUTOTOOLS=	libtool libltdl
USE_BZIP2=	yes
USE_GHOSTSCRIPT=yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--without-perl --enable-shared --enable-static \
		--with-ltdl-include=${LOCALBASE}/include \
		--with-ltdl-lib=${LOCALBASE}/lib
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

test check:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} == ""
# Get rid of the Makefile targets that install the documentation
# and HTML files into DOCSDIR
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.in
.endif

.if ${PORT_OPTIONS:MSSE}
.if ${MACHINE_CPU:Msse}
CFLAGS+=	-msse
.endif
.if ${MACHINE_CPU:Msse2}
CFLAGS+=	-msse2
.endif
.if ${MACHINE_CPU:Msse3}
CFLAGS+=	-msse3
.endif
.endif

.if ${PORT_OPTIONS:MFPX}
LIB_DEPENDS+=		libfpx.so.[2-9]:${PORTSDIR}/graphics/libfpx
CONFIGURE_ARGS+=	--with-fpx
.else
CONFIGURE_ARGS+=	--without-fpx
.endif

.if ${PORT_OPTIONS:MDPS}
USE_XORG+=		xt
LIB_DEPENDS+=		libdps.so:${PORTSDIR}/x11/dgs
CONFIGURE_ARGS+=	--with-dps
.else
CONFIGURE_ARGS+=	--without-dps
.endif

.if ${PORT_OPTIONS:MOPENMP}
.if ${OSVERSION} < 700042
IGNORE=		does not support OpenMP on FreeBSD version ${OSVERSION}
.endif

LDFLAGS+=		${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-threads --enable-openmp --disable-openmp-slow
.else
CONFIGURE_ARGS+=	--without-threads --disable-openmp
.endif

.ifndef WINDOWS_FONT_DIR
# Use fonts installed by x11-fonts/webfonts by default
WINDOWS_FONT_DIR=${LOCALBASE}/lib/X11/fonts/webfonts
.endif

.if defined(WITH_WINDOWS_FONT_DIR)
CONFIGURE_ARGS+=	--with-windows-font-dir="${WINDOWS_FONT_DIR}"
.endif

.if ${PORT_OPTIONS:MX11} == ""
CONFIGURE_ARGS+=--without-x
LIB_DEPENDS+=	libwmflite.so:${PORTSDIR}/graphics/libwmf-nox11
.else
USE_XORG+=		xext
LIB_DEPENDS+=	libwmflite.so:${PORTSDIR}/graphics/libwmf
.endif

.if ${PORT_OPTIONS:MQ8BIT}
CONFIGURE_ARGS+=	--with-quantum-depth=8
QD=			8
.else
CONFIGURE_ARGS+=	--with-quantum-depth=16
QD=			16
.endif
PLIST_SUB+=		Q=${QD}

.if ${PORT_OPTIONS:MTESTS}
post-build::	test
.else
post-build::
	#
	# You are strongly advised to run ``make test'' now
	# and report any failures to ${MAINTAINER}.
	#
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/GraphicsMagick/modules-Q${QD}/coders	\
		${STAGEDIR}${PREFIX}/lib/GraphicsMagick/modules-Q${QD}/filters

.include <bsd.port.mk>
