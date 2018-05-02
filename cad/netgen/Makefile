# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netgen
PORTVERSION=	5.3.1
PORTREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	SF/netgen-mesher/netgen-mesher/${PORTVERSION:C|\.[[:digit:]]+$||}/

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Automatic 3D tetrahedral mesh generator

LIB_DEPENDS=	libTix8.4.3.so:x11-toolkits/tix \
		libtogl.so:graphics/togl

OCC_BROKEN=	Does not compile because of issues with cad/opencascade

USE_LDCONFIG=	yes
USES=		gmake jpeg libtool localbase tk:tea
USE_GL=		gl glu
USE_XORG=	x11 xmu xi
MAKE_JOBS_UNSAFE=	yes
CPPFLAGS+=	-isystem ${LOCALBASE}/lib/Togl-1.7
CONFIGURE_ARGS=	--enable-jpeglib
INSTALL_TARGET=	install-strip

FETCH_BEFORE_ARGS+=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

OPTIONS_DEFINE=		OCC FFMPEG
OCC_DESC=		Compile with OpenCascade geometry kernel
FFMPEG_DESC=		video recording with FFmpeg
OPTIONS_DEFAULT=	# OCC

BROKEN_sparc64=		internal gcc error (Bug 23159)

OCC_LIB_DEPENDS=	libTKernel.so:cad/opencascade
OCC_CXXFLAGS=		-DOCCGEOMETRY -DHAVE_CONFIG_H -D${ARCH} -I${LOCALBASE}/include/OpenCASCADE
OCC_CONFIGURE_ON=	--enable-occ

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--enable-ffmpeg

MACHINE=	${OPSYS:tu}

SUB_LIST=	PREFIX=${PREFIX}
SUB_FILES=	pkg-message
MAKE_ENV=	TK_VER=${TK_VER} TCL_VER=${TCL_VER}	\
		TCL_INCLUDEDIR="${TCL_INCLUDEDIR}"	\
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"	\
		MACHINE=${MACHINE} MAKE=${MAKE_CMD}

post-patch:
	@${REINPLACE_CMD} -e '/ngdir/s,"\.","${PREFIX}/bin",' \
		${WRKSRC}/ng/ng.tcl \
		${WRKSRC}/ng/ngappinit.cpp

post-install:
#	copy some additional headers for build cad/salome-netgenplugin
	${MKDIR} ${STAGEDIR}${DATADIR}/include
	${SH} ${FILESDIR}/netgen_copy_include_for_salome ${WRKSRC} ${STAGEDIR}${PREFIX}
	${LN} ${STAGEDIR}${PREFIX}/lib/libnglib.so ${STAGEDIR}${PREFIX}/lib/libnglib.so.1

.include <bsd.port.mk>
