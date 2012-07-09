# New ports collection makefile for:	taglib
# Date Created:				06 Nov 2003
# Whom:				 	Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	taglib
PORTVERSION=	1.7.2
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/taglib/taglib/ \
		http://developer.kde.org/~wheeler/files/src/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Library for manipulating ID3 tags and Ogg comments

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL=	${WRKSRC}/COPYING.MPL

OPTIONS_DEFINE=	RCC

RCC_DESC=	Build with RusXMMS librcc patches (experimental)

USE_CMAKE=	yes
CMAKE_ARGS=	-DWITH_ASF:BOOL=ON \
		-DWITH_MP4:BOOL=ON
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRCC}
PKGNAMESUFFIX=	-rcc
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-rcc
LIB_DEPENDS+=	rcc:${PORTSDIR}/devel/librcc
PLIST_SUB+=	RCC=""
.else
PLIST_SUB+=	RCC="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MRCC}
	@${REINPLACE_CMD} -e 's|-ltag|-ltag -lrcc|g' \
		${WRKSRC}/taglib.pc.cmake ${WRKSRC}/taglib-config.cmake \
		${WRKSRC}/bindings/c/taglib_c.pc.cmake
.endif
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/bindings/c/CMakeLists.txt

.include <bsd.port.mk>
