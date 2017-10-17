# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	hiptext
PORTVERSION=	0.0.s20160621
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	yuri@rawbw.com
COMMENT=	Tool for rendering images and videos inside terminals

BUILD_DEPENDS=	ragel:devel/ragel
LIB_DEPENDS=	libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libpng.so:graphics/png \
		libswscale.so:multimedia/ffmpeg \
		libfreetype.so:print/freetype2
TEST_DEPENDS=	googletest>=1.7.0:devel/googletest
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

BROKEN_aarch64=		fails to compile: error: the clang compiler does not support -march=native
BROKEN_armv6=		fails to compile: error: the clang compiler does not support -march=native

USE_GITHUB=	yes
GH_ACCOUNT=	jart
GH_TAGNAME=	f89b44f

USES=		compiler:c++11-lib gmake jpeg localbase
CPPFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
CPPFLAGS+=	-I${LOCALBASE}/include/freetype2
MAKE_ENV=	GTEST_DIR="${LOCALBASE}"
TEST_TARGET=	check

PLIST_FILES=	bin/hiptext

post-extract:
	@${RM} -r ${WRKSRC}/gtest

post-patch:
	@${REINPLACE_CMD} -e 's|"DejaVuSansMono.ttf"|"${LOCALBASE}/share/fonts/dejavu/DejaVuSansMono.ttf"|' \
		${WRKSRC}/font.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hiptext ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
