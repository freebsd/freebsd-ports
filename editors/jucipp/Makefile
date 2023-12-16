PORTNAME=	jucipp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	info@babaei.net
COMMENT=	Lightweight C++-IDE with support for C++11, C++14 and C++17
WWW=		https://gitlab.com/cppit/jucipp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libboost_filesystem.so:devel/boost-libs \
		libgit2.so:devel/libgit2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		uctags:devel/universal-ctags

USES=		cmake compiler:c++14-lang desktop-file-utils gnome pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	cppit
GL_TAGNAME=	692f3de1f0aad00051096579975e515bccc3802a
GL_TUPLE=	cppit:libclangmm:9704b9b6de0982a588fa41741157d5640afedf30:libclangmm/lib/libclangmm \
		eidheim:tiny-process-library:839ff806dc447ff49af80f9a9eaa7949f770f8e5:tinyprocesslibrary/lib/tiny-process-library
USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/include \
		-DCMAKE_LIBRARY_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg
OPTIONS_DEFINE=	TEST

TEST_CMAKE_BOOL=	BUILD_TESTING BUILD_FUZZING

.include <bsd.port.mk>
