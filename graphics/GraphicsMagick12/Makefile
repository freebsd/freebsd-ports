# New ports collection makefile for:   GraphicsMagick
# Date created:        25 july 2005
# Whom:                Ron van Daal
#
# $FreeBSD$
#

PORTNAME=	GraphicsMagick
PORTVERSION=	1.2.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/1.2/
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Fast image processing tools based on ImageMagick

CONFLICTS=	GraphicsMagick-1.[13].*

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2	\
		jbig:${PORTSDIR}/graphics/jbigkit	\
		wmflite:${PORTSDIR}/graphics/libwmf	\
		xml2:${PORTSDIR}/textproc/libxml2	\
		ltdl:${PORTSDIR}/devel/libltdl22
OTHERGRAPHICS=	jasper jpeg lcms png tiff
LIB_DEPENDS+=	${OTHERGRAPHICS:C|(.+)|\1:${PORTSDIR}/graphics/\1|}
OPTIONS=	Q8BIT "Use 8-bit pixels (speed) instead of 16 (quality)" off \
		FPX "Enable FlashPIX support" on \
		DPS "Enable Display Ghostscript support" on \
		OPENMP "Enable OpenMP support" off \
		SSE "Enable SSE opcodes on supported CPUs" off \
		TESTS "Run bundled self-tests after build" on

USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GHOSTSCRIPT=yes
GNU_CONFIGURE=	yes
LATEST_LINK=	GraphicsMagick12

MAN1=	GraphicsMagick++-config.1 \
	GraphicsMagick-config.1 \
	GraphicsMagickWand-config.1 \
	gm.1
MAN4=	miff.4
MAN5=	quantize.5

CONFIGURE_ARGS=	--without-perl --enable-shared --enable-static \
		--with-ltdl-include=${LOCALBASE}/include \
		--with-ltdl-lib=${LOCALBASE}/lib
USE_LDCONFIG=	yes

ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"       \
	LDFLAGS="-L${LOCALBASE}/lib"

test check:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
# Get rid of the Makefile targets that install the documentation
# and HTML files into DOCSDIR
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.in
.endif

.if defined(WITH_SSE)
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

.if defined(WITH_FPX)
LIB_DEPENDS+=		fpx.[2-9]:${PORTSDIR}/graphics/libfpx
CONFIGURE_ARGS+=	--with-fpx
.else
CONFIGURE_ARGS+=	--without-fpx
.endif

.if defined(WITH_DPS)
LIB_DEPENDS+=		dps:${PORTSDIR}/x11/dgs
CONFIGURE_ARGS+=	--with-dps
.else
CONFIGURE_ARGS+=	--without-dps
.endif

.if defined(WITH_OPENMP)
.if ${OSVERSION} < 700042
IGNORE=		does not support OpenMP on FreeBSD version ${OSVERSION}
.endif

CONFIGURE_ENV+=		LDFLAGS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-threads --enable-openmp
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

.if defined(WITHOUT_X11)
PKGNAMESUFFIX+=	-nox11
CONFIGURE_ARGS+=--without-x
.endif

.if defined(WITH_Q8BIT) || defined(WITHOUT_GRAPHICSMAGICK_16BIT_PIXEL)
CONFIGURE_ARGS+=	--with-quantum-depth=8
PLIST_SUB+=		Q=8
.else
CONFIGURE_ARGS+=	--with-quantum-depth=16
PLIST_SUB+=		Q=16
.endif

.if !defined(WITHOUT_TESTS)
post-build::	test
.else
post-build::
	#
	# You are strongly advised to run ``make test'' now
	# and report any failures to ${MAINTAINER}.
	#
.endif

.include <bsd.port.post.mk>
