# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		fltk-threads>=0:${PORTSDIR}/x11-toolkits/fltk-threads
LIB_DEPENDS=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		tiff.4:${PORTSDIR}/graphics/tiff \
		aprutil-1.3:${PORTSDIR}/devel/apr \
		db-4.2.2:${PORTSDIR}/databases/db42

LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DAQSIS_BOOST_FILESYSTEM_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_filesystem.so \
		-DAQSIS_BOOST_REGEX_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_regex.so \
		-DAQSIS_BOOST_THREAD_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_thread.so \
		-DAQSIS_BOOST_WAVE_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_wave.so \
		-DAQSIS_FLTK_LIBRARIES:FILEPATH=${LOCALBASE}/lib/libfltk.so
#		-DAQSIS_BOOST_FILESYSTEM_LIBRARY_NAME:STRING=boost_filesystem \
#		-DAQSIS_BOOST_REGEX_LIBRARY_NAME:STRING=boost_regex \
#		-DAQSIS_BOOST_THREAD_LIBRARY_NAME:STRING=boost_thread \
#		-DAQSIS_BOOST_WAVE_LIBRARY_NAME:STRING=boost_wave \
#		-DAQSIS_FLTK_INCLUDE_DIR:PATH=${LOCALBASE}/include \
#		-DAQSIS_FLTK_LIBRARIES_DIR:PATH=${LOCALBSAE}/lib
CMAKE_USE_PTHREAD=	yes

USE_LDCONFIG=	yes
USE_CMAKE=	yes

# Required for off-source building
CMAKE_BUILD_PATH=	${WRKSRC}/build
CMAKE_SOURCE_PATH=	${WRKSRC}/
CONFIGURE_WRKSRC=	${CMAKE_BUILD_PATH}

post-extract:
	${MKDIR} ${CMAKE_BUILD_PATH}

post-patch:
	${REINPLACE_CMD} -e '47s/$$/ || defined(__sparc64__)/' \
	    ${WRKSRC}/renderer/ddmanager/ndspy.h

post-configure:
	${FIND} ${WRKSRC} -name "relink.txt" -o -name "link.txt" \
	    | ${XARGS} ${REINPLACE_CMD} -i "" -e 's|\-ldl||g'

do-build:
	cd ${CMAKE_BUILD_PATH} && ${MAKE}

do-install:
	cd ${CMAKE_BUILD_PATH} && ${MAKE} install

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
