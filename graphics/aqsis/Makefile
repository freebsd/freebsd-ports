# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost \
		bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		fltk-threads>=0:${PORTSDIR}/x11-toolkits/fltk-threads
LIB_DEPENDS=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff

LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DAQSIS_BOOST_FILESYSTEM_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_filesystem.so \
		-DAQSIS_BOOST_REGEX_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_regex.so \
		-DAQSIS_BOOST_THREAD_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_thread.so \
		-DAQSIS_BOOST_WAVE_LIBRARY:FILEPATH=${LOCALBASE}/lib/libboost_wave.so \
		-DAQSIS_BOOST_FILESYSTEM_LIBRARY_NAME:STRING=boost_filesystem \
		-DAQSIS_BOOST_REGEX_LIBRARY_NAME:STRING=boost_regex \
		-DAQSIS_BOOST_THREAD_LIBRARY_NAME:STRING=boost_thread \
		-DAQSIS_BOOST_WAVE_LIBRARY_NAME:STRING=boost_wave \
		-DAQSIS_FLTK_INCLUDE_DIR:PATH=${LOCALBASE}/include \
		-DAQSIS_FLTK_LIBRARIES:FILEPATH=${LOCALBASE}/lib/libfltk.so \
		-DAQSIS_FLTK_LIBRARIES_DIR:PATH=${LOCALBSAE}/lib

USE_LDCONFIG=	yes
USE_CMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e '54s/$$/ || defined(__sparc64__)/' \
	    ${WRKSRC}/renderer/ddmanager/ndspy.h

post-configure:
	${FIND} ${WRKSRC} -name "build.make" -o -name "link.txt" -o -name "relink.txt" \
	    | ${XARGS} ${REINPLACE_CMD} -i "" -e 's|-ldl||g'
	${REINPLACE_CMD} -e 's|-lz|-lz ${PTHREAD_LIBS}|' \
	    ${WRKSRC}/renderer/aqsis/CMakeFiles/aqsis.dir/link.txt \
	    ${WRKSRC}/texturing/teqser/CMakeFiles/teqser.dir/link.txt
	${REINPLACE_CMD} -e 's|-O2|-O2 ${PTHREAD_LIBS}|' \
	    ${WRKSRC}/shadercompiler/aqsltell/CMakeFiles/aqsltell.dir/link.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
