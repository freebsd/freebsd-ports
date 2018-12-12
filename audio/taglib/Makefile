# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	taglib
PORTVERSION=	1.11.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://taglib.github.io/releases/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for manipulating ID3 tags and Ogg comments

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING.MPL

USES=		cmake compiler:c++11-lang cpe pathfix
USE_LDCONFIG=	yes

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Boost \
		WITH_ASF \
		WITH_MP4 \
		BUILD_SHARED_LIBS

CPE_VENDOR=	scott_wheeler

OPTIONS_DEFINE=	RCC
OPTIONS_SUB=	yes

# The official patches for this can be obtained from:
#   http://darksoft.org/files/rusxmms/patches/
# however, they do not seem to yet have any for taglib-1.11.1.
# So instead, use:
#   https://sourceforge.net/p/qmmp-dev/code/HEAD/tree/trunk/extras/package/win32/contrib/taglib-rusxmms/
#
RCC_DESC=		Build with RusXMMS librcc patches (experimental)
RCC_LIB_DEPENDS=	librcc.so:devel/librcc
RCC_USES=		localbase:ldflags
RCC_EXTRA_PATCHES=	${FILESDIR}/extrapatch-rcc

post-patch-RCC-on:
	@${REINPLACE_CMD} -e 's|-ltag|-ltag -lrcc|g' \
		${WRKSRC}/taglib.pc.cmake ${WRKSRC}/taglib-config.cmake
	@${REINPLACE_CMD} -e 's|-ltag_c|-ltag_c -lrcc|g' \
		${WRKSRC}/bindings/c/taglib_c.pc.cmake

.include <bsd.port.mk>
