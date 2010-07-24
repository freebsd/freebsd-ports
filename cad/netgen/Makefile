# New ports collection makefile for:  netgen
# Date created:               29 April 2004
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netgen
PORTVERSION=	4.9.13
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	SF/netgen-mesher/netgen-mesher/${PORTVERSION}/

MAINTAINER=	stephen@missouri.edu
COMMENT=	An automatic 3D tetrahedral mesh generator


USE_GMAKE=	yes
USE_TK=		84
USE_TK_BUILD=	84
USE_GL=		yes
USE_XORG=	xmu xi
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${TK_LIBDIR}/Togl-1.7
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR} --enable-jpeglib
LIB_DEPENDS+=	tix8184:${PORTSDIR}/x11-toolkits/tix \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		togl.1:${PORTSDIR}/graphics/togl

FETCH_BEFORE_ARGS+=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

OPTIONS=	OCC	"Compile with OpenCascade geometry kernel" 	on \
		FFMPEG  "video recording with FFmpeg"		off

.include <bsd.port.options.mk>

.if defined(WITH_OCC)
LIB_DEPENDS+=	TKernel.0:${PORTSDIR}/cad/opencascade
CXXFLAGS+=	-DOCCGEOMETRY -DOCC63 -DHAVE_WOK_CONFIG_H -DHAVE_CONFIG_H -D${ARCH} -I${LOCALBASE}/OpenCAS/ros/inc
CONFIGURE_ARGS+=	--enable-occ
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-ffmpeg
.endif

MACHINE=	${OPSYS:U}

SUB_LIST=	PREFIX=${PREFIX}
SUB_FILES=	pkg-message
MAKE_ENV=	TK_VER=${TK_VER} TCL_VER=${TCL_VER}	\
		TCL_INCLUDEDIR="${TCL_INCLUDEDIR}"	\
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"	\
		MACHINE=${MACHINE} MAKE=${GMAKE}	\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		internal gcc error (Bug 23159)
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"		\
		${WRKSRC}/ng/ngappinit.cpp

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
