# New ports collection makefile for:	taglib
# Date Created:				06 Nov 2003
# Whom:				 	Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	taglib
PORTVERSION=	1.7.1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/taglib/taglib/ \
		http://developer.kde.org/~wheeler/files/src/ \
		http://launchpad.net/taglib/trunk/${PORTVERSION}/+download/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Library for manipulating ID3 tags and Ogg comments

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL=	${WRKSRC}/COPYING.MPL

USE_CMAKE=	yes
CMAKE_ARGS=	-DWITH_ASF:BOOL=ON \
		-DWITH_MP4:BOOL=ON
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS=	RCC "Build with RusXMMS librcc patches (experimental)" off

.include <bsd.port.options.mk>

.if defined(WITH_RCC)
PKGNAMESUFFIX=	-rcc
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-rcc
LIB_DEPENDS+=	rcc.2:${PORTSDIR}/devel/librcc
PLIST_SUB+=	RCC=""
.else
PLIST_SUB+=	RCC="@comment "
.endif

post-patch:
.if defined(WITH_RCC)
	@${REINPLACE_CMD} -e 's|-ltag|-ltag -lrcc|g' \
		${WRKSRC}/taglib.pc.cmake ${WRKSRC}/taglib-config.cmake \
		${WRKSRC}/bindings/c/taglib_c.pc.cmake
.endif
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/bindings/c/CMakeLists.txt

.include <bsd.port.mk>
