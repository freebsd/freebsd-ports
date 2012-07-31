# New ports collection makefile for:   hugin
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	hugin
PORTVERSION=	2011.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	A GUI for Panorama Tools, to stitch panoramic images

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		exiv2.12:${PORTSDIR}/graphics/exiv2 \
		pano13:${PORTSDIR}/graphics/libpano13 \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		Imath:${PORTSDIR}/graphics/ilmbase
# gmake is really needed at _runtime_, do not remove it from below
RUN_DEPENDS=	enblend>=3.1.r20080615:${PORTSDIR}/graphics/enblend \
		exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool \
		gmake:${PORTSDIR}/devel/gmake

USE_BZIP2=	yes

OPTIONS=	PANOMATIC "Install graphics/panomatic" on \
		AUTOPANOSIFTC "Install graphics/autopano-sift-c" on

USE_CMAKE=	yes

CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}
CMAKE_VERBOSE=	yes

USE_WX=		2.8+
WX_UNICODE=	yes

USE_GETTEXT=	yes

USE_GL=		glew glut

MANCOMPRESSED=	yes
MAN1=		\
		PTBatcher.1 \
		PTBatcherGUI.1 \
		align_image_stack.1 \
		autooptimiser.1 \
		autopano-noop.sh.1 \
		calibrate_lens_gui.1 \
		celeste_standalone.1 \
		checkpto.1 \
		cpclean.1 \
		cpfind.1 \
		deghosting_mask.1 \
		fulla.1 \
		hugin.1 \
		hugin_hdrmerge.1 \
		hugin_stitch_project.1 \
		icpfind.1 \
		linefind.1 \
		matchpoint.1 \
		nona.1 \
		nona_gui.1 \
		pano_modify.1 \
		pano_trafo.1 \
		pto2mk.1 \
		pto_merge.1 \
		tca_correct.1 \
		vig_optimize.1

#DOCSDIR=	${PREFIX}/share/hugin/xrc/data

# Extract the tclap library in a place where hugin's CMake scripts will find
# it. This library is entirely composed of .h files and does not need
# to be compiled or configured. This dependency would best be done if tclap
# is added as a separate port, but it does not seem eligible for that, so
# currently we store the library in ${PATCHDIR} and extract it before running
# CMake.
pre-configure:
	cd ${WRKSRC}/src/foreign && ${SH} ${PATCHDIR}/tclap-1.2.1-headers.shar

# workaround a bug in cmake (?). Without this we get an error like:
# cd /usr/ports/graphics/hugin/work/hugin-0.7.r3135/src/hugin1/base_wx && /usr/bin/c++   -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -D_THREAD_SAFE -O2 -fno-strict-aliasing -pipe -pthread;-D_THREAD_SAFE -O3 -DNDEBUG -I/usr/ports/graphics/hugin/work/hugin-0.7.r3135/src -I/usr/ports/graphics/hugin/work/hugin-0.7.r3135/src/hugin_base -I/usr/ports/graphics/hugin/work/hugin-0.7.r3135/src/foreign -I/usr/ports/graphics/hugin/work/hugin-0.7.r3135/src/foreign/vigra -I/usr/local/include -I/usr/local/include/OpenEXR -isystem /usr/local/lib/wx/include/gtk2-ansi-release-2.8 -isystem /usr/local/include/wx-2.8 -I/usr/ports/graphics/hugin/work/hugin-0.7.r3135/src/hugin1 -o CMakeFiles/huginbasewx.dir/ImageCache.o -c /usr/ports/graphics/hugin/work/hugin-0.7.r3135/src/hugin1/base_wx/ImageCache.cpp
# c++: No input files specified
# with cmake 2.6.0. It works with cmake 2.4.8.
post-configure:
	${REINPLACE_CMD} \
		's/-pthread;-D_THREAD_SAFE/-pthread -D_THREAD_SAFE/g' \
		${WRKSRC}/src/hugin1/base_wx/CMakeFiles/huginbasewx.dir/flags.make \
		${WRKSRC}/src/hugin1/hugin/CMakeFiles/hugin.dir/flags.make \
		${WRKSRC}/src/hugin1/hugin/CMakeFiles/hugin.dir/link.txt \
		${WRKSRC}/src/hugin1/nona_gui/CMakeFiles/nona_gui.dir/flags.make \
		${WRKSRC}/src/hugin1/nona_gui/CMakeFiles/nona_gui.dir/link.txt \
		${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcher.dir/flags.make \
		${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcher.dir/link.txt \
		${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcherGUI.dir/flags.make \
		${WRKSRC}/src/hugin1/ptbatcher/CMakeFiles/PTBatcherGUI.dir/link.txt \
		${WRKSRC}/src/hugin1/stitch_project/CMakeFiles/hugin_stitch_project.dir/flags.make \
		${WRKSRC}/src/hugin1/stitch_project/CMakeFiles/hugin_stitch_project.dir/link.txt

.include <bsd.port.pre.mk>

.if defined(WITH_PANOMATIC)
RUN_DEPENDS+=	panomatic:${PORTSDIR}/graphics/panomatic
.endif

.if defined(WITH_AUTOPANOSIFTC)
RUN_DEPENDS+=	autopano:${PORTSDIR}/graphics/autopano-sift-c
.endif

.include <bsd.port.post.mk>
