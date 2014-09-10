# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netgen
PORTVERSION=	5.0.0
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	SF/netgen-mesher/netgen-mesher/${PORTVERSION:S|.0$||}/

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Automatic 3D tetrahedral mesh generator

LIB_DEPENDS=	libTix8.4.3.so:${PORTSDIR}/x11-toolkits/tix \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtogl.so:${PORTSDIR}/graphics/togl

USE_LDCONFIG=	yes
USES=		gmake libtool tk
USE_GL=		yes
USE_XORG=	xmu xi
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/lib/Togl-1.7
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR} --enable-jpeglib

FETCH_BEFORE_ARGS+=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

OPTIONS_DEFINE=		OCC FFMPEG
OCC_DESC=		Compile with OpenCascade geometry kernel
FFMPEG_DESC=		video recording with FFmpeg
OPTIONS_DEFAULT=	OCC

BROKEN_sparc64=	internal gcc error (Bug 23159)
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOCC}
LIB_DEPENDS+=	libTKernel.so:${PORTSDIR}/cad/opencascade
CXXFLAGS+=	-DOCCGEOMETRY -DHAVE_CONFIG_H -D${ARCH} -I${LOCALBASE}/include/OpenCASCADE
CONFIGURE_ARGS+=	--enable-occ
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0
CONFIGURE_ARGS+=	--enable-ffmpeg
.endif

MACHINE=	${OPSYS:tu}

SUB_LIST=	PREFIX=${PREFIX}
SUB_FILES=	pkg-message
MAKE_ENV=	TK_VER=${TK_VER} TCL_VER=${TCL_VER}	\
		TCL_INCLUDEDIR="${TCL_INCLUDEDIR}"	\
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"	\
		MACHINE=${MACHINE} MAKE=${MAKE_CMD}

pre-configure:
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"		\
		${WRKSRC}/ng/ngappinit.cpp

post-configure:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|"	\
		${WRKSRC}/configure

post-install:
#	copy some additional headers for build cad/salome-netgenplugin
	${MKDIR} ${STAGEDIR}${DATADIR}/include
	${SH} ${FILESDIR}/netgen_copy_include_for_salome ${WRKSRC} ${STAGEDIR}${PREFIX}
	${LN} ${STAGEDIR}${PREFIX}/lib/libnglib.so ${STAGEDIR}${PREFIX}/lib/libnglib.so.1
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
