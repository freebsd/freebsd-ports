# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	jucipp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	editors

MAINTAINER=	info@babaei.net
COMMENT=	Lightweight C++-IDE with support for C++11, C++14 and C++17

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libboost_filesystem.so:devel/boost-libs \
		libgit2.so:devel/libgit2
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		uctags:devel/universal-ctags

USES=		cmake compiler:c++14-lang desktop-file-utils gnome pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	cppit
GL_COMMIT=	4a1f88590ad1242aed596546c5568bbc40184c0c
GL_TUPLE=	cppit:libclangmm:c807211edcd3894f0920fcc1c01476d898f93f8f:libclangmm/lib/libclangmm \
		eidheim:tiny-process-library:c9c8bf810ddad8cd17882b9a9ee628a690e779f5:tinyprocesslibrary/lib/tiny-process-library
USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/include \
		-DCMAKE_LIBRARY_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg
OPTIONS_DEFINE=	TEST

TEST_CMAKE_BOOL=	BUILD_TESTING

.include <bsd.port.mk>
