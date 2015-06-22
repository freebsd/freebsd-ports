# Created by: Carlos Eduardo G. Carvalho <cartola@openit.com.br>
# $FreeBSD$

PORTNAME=	hugin
PORTVERSION=	2013.0
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-2013.0
PKGNAMESUFFIX=	-devel
DISTNAME=	hugin-2013.0.0_beta1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for Panorama Tools, to stitch panoramic images

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libImath.so:${PORTSDIR}/graphics/ilmbase \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		liblensfun.so:${PORTSDIR}/graphics/lensfun \
		libpano13.so:${PORTSDIR}/graphics/libpano13 \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff
BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20 \
		tclap>=1.2.1:${PORTSDIR}/devel/tclap
# gmake is really needed at _runtime_.   Do not remove it from this list.
RUN_DEPENDS=	enblend>=3.1.r20080615:${PORTSDIR}/graphics/enblend \
		exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool \
		gmake:${PORTSDIR}/devel/gmake

WRKSRC=		${WRKDIR}/hugin-2013.0.0
CONFLICTS_INSTALL=	hugin-201[0-2]*

IGNORE=		older than graphics/hugin

OPTIONS_DEFINE=	PANOMATIC AUTOPANOSIFTC
OPTIONS_DEFAULT=	PANOMATIC AUTOPANOSIFTC
PANOMATIC_DESC=		Install graphics/panomatic
AUTOPANOSIFTC_DESC=	Install graphics/autopano-sift-c

USES=		cmake gettext jpeg pkgconfig tar:bzip2

CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}

USE_WX=		2.8+
WX_UNICODE=	yes


USE_GL=		glew glut

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
