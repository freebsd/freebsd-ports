PORTNAME=	jucipp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTREVISION=	9
CATEGORIES=	editors

MAINTAINER=	info@babaei.net
COMMENT=	Lightweight C++-IDE with support for C++11, C++14 and C++17
WWW=		https://gitlab.com/cppit/jucipp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libboost_filesystem.so:devel/boost-libs \
		libclang.so:devel/llvm${LLVM_DEFAULT} \
		libgit2.so:devel/libgit2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	uctags:devel/universal-ctags

USES=		cmake compiler:c++14-lang desktop-file-utils gnome \
		llvm:build,noexport,run pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	cppit
GL_TUPLE=	cppit:libclangmm:5611eb3d9e69486f85a431fbaae03c065f62c2d8:libclangmm/lib/libclangmm \
		eidheim:tiny-process-library:aaf6afa48ad8f0ea5f15dc5cb5f53888bf1ff7ac:tinyprocesslibrary/lib/tiny-process-library
USE_GNOME=	gdkpixbuf gtkmm30 gtksourceviewmm3

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/include \
		-DCMAKE_LIBRARY_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg
OPTIONS_DEFINE=	TEST

TEST_CMAKE_BOOL=	BUILD_TESTING BUILD_FUZZING

.include <bsd.port.mk>
