# Created by: ijliao
# $FreeBSD$

PORTNAME=	k3d
PORTVERSION=	0.8.0.2
PORTREVISION=	3
DISTVERSIONPREFIX=	source-
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/K-3D%20Source/K-3D%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D modeling, animation, and rendering system

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/gmm/gmm.h:${PORTSDIR}/math/gmm++
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		expat:${PORTSDIR}/textproc/expat2 \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

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
USE_DOS2UNIX=	*.hpp
USE_GCC=	yes
USE_PYTHON=	yes
USES=		cmake:outsource gettext
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
LIB_DEPENDS+=	3ds-1:${PORTSDIR}/graphics/lib3ds
PLIST_SUB+=	3DS=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_3DS_IO_MODULE:BOOL=OFF
PLIST_SUB+=	3DS="@comment "
.endif

.if ${PORT_OPTIONS:MCOMPIZ}
LIB_DEPENDS+=	dbus-glib:${PORTSDIR}/devel/dbus-glib
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
LIB_DEPENDS+=	profiler:${PORTSDIR}/devel/google-perftools
PLIST_SUB+=	PERFTOOLS=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_GOOGLE_PERFTOOLS_MODULE:BOOL=OFF
PLIST_SUB+=	PERFTOOLS="@comment "
.endif

.if ${PORT_OPTIONS:MGTS}
LIB_DEPENDS+=	gts:${PORTSDIR}/graphics/gts
PLIST_SUB+=	GTS=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_GTS_MODULE:BOOL=OFF
PLIST_SUB+=	GTS="@comment "
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
LIB_DEPENDS+=	MagickCore:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IMAGEMAGICK=""
.else
CMAKE_ARGS+=	-DK3D_BUILD_IMAGEMAGICK_IO_MODULE:BOOL=OFF
PLIST_SUB+=	IMAGEMAGICK="@comment "
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
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
