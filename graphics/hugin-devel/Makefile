# Created by: cartola (Carlos E. G. Carvalho)
# $FreeBSD$

PORTNAME=	hugin
PORTVERSION=	2013.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-2013.0
PKGNAMESUFFIX=  -devel
DISTNAME=	hugin-2013.0.0_beta1

MAINTAINER=	grog@FreeBSD.org
COMMENT=	A GUI for Panorama Tools, to stitch panoramic images

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libImath.so:${PORTSDIR}/graphics/ilmbase \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblensfun.so:${PORTSDIR}/graphics/lensfun \
		libpano13.so:${PORTSDIR}/graphics/libpano13 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff
BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20 \
		tclap>=1.2.1:${PORTSDIR}/devel/tclap
# gmake is really needed at _runtime_.   Do not remove it from this list.
RUN_DEPENDS=	enblend>=3.1.r20080615:${PORTSDIR}/graphics/enblend \
		exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool \
		gmake:${PORTSDIR}/devel/gmake

WRKSRC=		${WRKDIR}/hugin-2013.0.0
CONFLICTS_INSTALL=	hugin-201[0-2]*
USE_BZIP2=	yes

OPTIONS_DEFINE=	PANOMATIC AUTOPANOSIFTC
OPTIONS_DEFAULT=	PANOMATIC AUTOPANOSIFTC
PANOMATIC_DESC=		Install graphics/panomatic
AUTOPANOSIFTC_DESC=	Install graphics/autopano-sift-c

USES=		cmake gettext pkgconfig

CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}

USE_WX=		2.8+
WX_UNICODE=	yes


USE_GL=		glew glut

MANCOMPRESSED=	yes

MAN1=		align_image_stack.1 \
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
		nona.1 \
		linefind.1 \
		matchpoint.1 \
		nona_gui.1 \
		pano_modify.1 \
		pano_trafo.1 \
		pto2mk.1 \
		pto_gen.1 \
		pto_lensstack.1 \
		pto_merge.1 \
		pto_var.1 \
		tca_correct.1 \
		PTBatcher.1 \
		PTBatcherGUI.1 \
		vig_optimize.1

NO_STAGE=	yes
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPANOMATIC}
RUN_DEPENDS+=	panomatic:${PORTSDIR}/graphics/panomatic
.endif

.if ${PORT_OPTIONS:MAUTOPANOSIFTC}
RUN_DEPENDS+=	autopano:${PORTSDIR}/graphics/autopano-sift-c
.endif

.include <bsd.port.mk>
