# Created by: ijliao
# $FreeBSD$

PORTNAME=	k3d
PORTVERSION=	0.8.0.2
PORTREVISION=	6
DISTVERSIONPREFIX=	source-
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/K-3D%20Source/K-3D%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D modeling, animation, and rendering system

LICENSE=	GPLv2

BROKEN=		Fails to configure

BUILD_DEPENDS=	${LOCALBASE}/include/gmm/gmm.h:${PORTSDIR}/math/gmm++
LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24

OPTIONS_DEFINE=	3DS COMPIZ GNOME PERFTOOLS GTS IMAGEMAGICK OPENEXR
3DS_DESC=	3ds_io plugin module
COMPIZ_DESC=	Compiz plugin module
GNOME_DESC=	GNOME integration plugin module
PERFTOOLS_DESC=	Google Perftools profiling module
GTS_DESC=	GNU Triangulated Surfaces plugin module
IMAGEMAGICK_DESC=	ImageMagick file format module
OPENEXR_DESC=	OpenEXR file format module

USE_BZIP2=	yes
USE_GL=		glu
USE_GNOME=	gtksourceview2
DOS2UNIX_GLOB=	*.hpp
USE_GCC=	yes
USE_PYTHON=	yes
USES=		cmake:outsource gettext dos2unix
CMAKE_ARGS=	-DK3D_INTL_INCLUDE_DIRS:STRING="-I${LOCALBASE}/include" \
		-DK3D_INTL_LIBS:STRING="-L${LOCALBASE}/lib -lintl" \
		-DK3D_BUILD_CARVE_MODULE:BOOL=OFF \
		-DK3D_BUILD_CGAL_MODULE:BOOL=OFF \
		-DK3D_BUILD_COLLADA_IO_MODULE:BOOL=OFF \
		-DK3D_BUILD_INOTIFY_MODULE:BOOL=OFF \
		-DK3D_BUILD_OPENCASCADE_MODULE:BOOL=OFF
USE_LDCONFIG=	yes

MAN1=		k3d.1 k3d-renderframe.1 k3d-renderjob.1 k3d-sl2xml.1 \
		k3d-uuidgen.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M3DS}
LIB_DEPENDS+=	lib3ds-1.so:${PORTSDIR}/graphics/lib3ds
PLIST_SUB+=	3DS=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_3DS_IO_MODULE:BOOL=OFF
PLIST_SUB+=	3DS="@comment "
.endif

.if ${PORT_OPTIONS:MCOMPIZ}
LIB_DEPENDS+=	libdbus-glib.so:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	COMPIZ=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_COMPIZ_MODULE:BOOL=OFF
PLIST_SUB+=	COMPIZ="@comment "
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gnomevfs2
PLIST_SUB+=	GNOME=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_GNOME_MODULE:BOOL=OFF
PLIST_SUB+=	GNOME="@comment "
.endif

.if ${PORT_OPTIONS:MPERFTOOLS}
LIB_DEPENDS+=	libprofiler.so:${PORTSDIR}/devel/google-perftools
PLIST_SUB+=	PERFTOOLS=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_GOOGLE_PERFTOOLS_MODULE:BOOL=OFF
PLIST_SUB+=	PERFTOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MGTS}
LIB_DEPENDS+=	libgts.so:${PORTSDIR}/graphics/gts
PLIST_SUB+=	GTS=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_GTS_MODULE:BOOL=OFF
PLIST_SUB+=	GTS="@comment "
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	libMagickCore.so:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IMAGEMAGICK=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_IMAGEMAGICK_IO_MODULE:BOOL=OFF
PLIST_SUB+=	IMAGEMAGICK="@comment "
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=	OPENEXR=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_OPENEXR_IO_MODULE:BOOL=OFF
PLIST_SUB+=	OPENEXR="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cmake/modules/*.cmake
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.mk>
