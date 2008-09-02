# New ports collection makefile for:   GraphicsMagick
# Date created:        25 july 2005
# Whom:                Ron van Daal
#
# $FreeBSD$
#

PORTNAME=	GraphicsMagick
PORTVERSION=	1.2.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Fast image processing tools based on ImageMagick

CONFLICTS=	GraphicsMagick-1.1.*

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2	\
		fpx.[2-9]:${PORTSDIR}/graphics/libfpx	\
		jbig:${PORTSDIR}/graphics/jbigkit	\
		wmflite:${PORTSDIR}/graphics/libwmf	\
		xml2:${PORTSDIR}/textproc/libxml2	\
		ltdl:${PORTSDIR}/devel/libltdl15
OTHERGRAPHICS=	jasper jpeg lcms png tiff
LIB_DEPENDS+=	${OTHERGRAPHICS:C|(.+)|\1:${PORTSDIR}/graphics/\1|}
OPTIONS=	Q8BIT "Use 8-bit pixels (speed) instead of 16 (quality)" off \
		OPENMP "Enable OpenMP support (requires GCC 4.2+)" off \
		SSE "Enable SSE opcodes on supported CPUs" off \
		TESTS "Run bundled self-tests after build" on

USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:15
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

.if defined(WITH_OPENMP)
# Later versions of FreeBSD 7.0 already have GCC 4.2
.if ${OSVERSION} < 700042
USE_GCC=	4.2+
.endif

CONFIGURE_ENV+=		LDFLAGS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--enable-openmp
.endif

.ifndef WINDOWS_FONT_DIR
# Use fonts installed by x11-fonts/webfonts by default
WINDOWS_FONT_DIR=${LOCALBASE}/lib/X11/fonts/webfonts
.endif

CONFIGURE_ARGS=	--without-perl --enable-shared --enable-static \
		--without-threads --with-ltdl-include=${LOCALBASE}/include \
		--with-ltdl-lib=${LOCALBASE}/lib
USE_LDCONFIG=	yes

ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"       \
	LDFLAGS="-L${LOCALBASE}/lib"

test check:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.pre.mk>

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
