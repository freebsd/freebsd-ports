# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netgen
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/netgen-mesher/netgen-mesher/${PORTVERSION:S|.0$||}/

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	An automatic 3D tetrahedral mesh generator

LIB_DEPENDS=	Tix8.4.3:${PORTSDIR}/x11-toolkits/tix \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		togl.1:${PORTSDIR}/graphics/togl

USE_LDCONFIG=	yes
USES=		gmake
USE_TK=		85
USE_TK_BUILD=	84
USE_GL=		yes
USE_XORG=	xmu xi
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${TK_LIBDIR}/Togl-1.7
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR} --enable-jpeglib

FETCH_BEFORE_ARGS+=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

OPTIONS_DEFINE=		OCC FFMPEG
OCC_DESC=		Compile with OpenCascade geometry kernel
FFMPEG_DESC=		video recording with FFmpeg
OPTIONS_DEFAULT=	OCC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOCC}
LIB_DEPENDS+=	TKernel.0:${PORTSDIR}/cad/opencascade
CXXFLAGS+=	-DOCCGEOMETRY -DHAVE_CONFIG_H -D${ARCH} -I${LOCALBASE}/include/OpenCASCADE
CONFIGURE_ARGS+=	--enable-occ
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-ffmpeg
.endif

MACHINE=	${OPSYS:U}

SUB_LIST=	PREFIX=${PREFIX}
SUB_FILES=	pkg-message
MAKE_ENV=	TK_VER=${TK_VER} TCL_VER=${TCL_VER}	\
		TCL_INCLUDEDIR="${TCL_INCLUDEDIR}"	\
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"	\
		MACHINE=${MACHINE} MAKE=${GMAKE}
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		internal gcc error (Bug 23159)
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"		\
		${WRKSRC}/ng/ngappinit.cpp

post-install:
#	copy some additional headers for build cad/salome-netgenplugin
	${MKDIR} ${DATADIR}/include
	${SH} ${FILESDIR}/netgen_copy_include_for_salome ${WRKSRC} ${PREFIX}
	${LN} ${PREFIX}/lib/libnglib.so  ${PREFIX}/lib/libnglib.so.1
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
