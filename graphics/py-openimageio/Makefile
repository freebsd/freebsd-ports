# New ports collection makefile for:	py-openimageio
# Date created:			28 April 2012
# Whom:					Shane Ambler
#
# $FreeBSD$
#

PORTNAME=	openimageio
PORTVERSION=	1.0.9
CATEGORIES=	graphics multimedia python
MASTER_SITES=	https://github.com/OpenImageIO/oiio/tarball/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Release-${PORTVERSION}
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	OpenImageIO python bindings

LICENSE=	BSD

LIB_DEPENDS=	OpenImageIO:${PORTSDIR}/graphics/openimageio \
		boost_python:${PORTSDIR}/devel/boost-python-libs

FETCH_ARGS=	-pRr
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_ARGS=	-DBUILDSTATIC:BOOL=OFF \
		-DLINKSTATIC:BOOL=OFF \
		-DUSE_OPENGL:BOOL=OFF \
		-DUSE_PYTHON:BOOL=ON \
		-DUSE_QT:BOOL=OFF \
		-DUSE_TBB:BOOL=ON
LDFLAGS+=	-ltbb
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	2.6+
WRKSRC=		${WRKDIR}/OpenImageIO-oiio-0d48631/src

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/OpenImageIO.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${OSVERSION} < 803000
USE_GCC=	4.6+
.endif

.if ${OSVERSION} < 800000
IGNORE=	requires FreeBSD 8.0 or higher
.endif

post-patch:
	@${REINPLACE_CMD} 's|lib/python|lib/${PYTHON_VERSION}|' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_LIB} ${BUILD_WRKSRC}/python/OpenImageIO.so ${PYTHON_SITELIBDIR}/

.include <bsd.port.post.mk>
