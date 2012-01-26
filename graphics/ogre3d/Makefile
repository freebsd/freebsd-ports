# New ports collection makefile for:	ogre3d
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogre3d
PORTVERSION=	1.7.4
CATEGORIES=	graphics devel
MASTER_SITES=	SF/ogre/ogre/${PORTVERSION:C/.[0-9]$//g}
DISTNAME=	ogre_src_v${PORTVERSION:S/./-/g}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A scene-oriented, flexible 3D engine written in C++

LIB_DEPENDS=	zzip.13:${PORTSDIR}/devel/zziplib \
		freetype.9:${PORTSDIR}/print/freetype2 \
		freeimage.3:${PORTSDIR}/graphics/freeimage

OPTIONS=	BOOST	"Use Boost to build threaded ogre"	off

USE_LDCONFIG=	YES
USE_BZIP2=	YES
USE_CMAKE=	YES
USE_SDL=	sdl
USE_XORG=	xaw
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_BOOST)
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
RUND_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
PLIST_SUB+=	BOOSTTRUE=""
PLIST_SUB+=	BOOSTFALSE="@comment "
.else
PLIST_SUB+=	BOOSTTRUE="@comment "
PLIST_SUB+=	BOOSTFALSE=""
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc
.endif

.if ${CXX:M*clang*}
CMAKE_ARGS+=	-DCMAKE_COMPILER_IS_GNUCXX:BOOL=YES
.endif

post-patch:
.if defined(WITHOUT_BOOST)
	@${REINPLACE_CMD} -e 's|Boost|No_Boost|g' \
		${WRKSRC}/CMake/Dependencies.cmake
.endif
	@${REINPLACE_CMD} -e 's|(CEGUI::uint)|(size_t)|' \
		${WRKSRC}/Samples/OceanDemo/src/OceanDemo.cpp
	@${REINPLACE_CMD} -e '\
		s,defined(__x86_64__),& || defined(__powerpc__) || defined(__ia64__) || defined(__sparc64__) || defined(__alpha__) || defined(__amd64__),' \
		${WRKSRC}/OgreMain/include/OgrePlatform.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
