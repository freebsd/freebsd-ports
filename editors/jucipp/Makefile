# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	jucipp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
PORTREVISION=	2
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
GL_COMMIT=	485aa718ecbb99473ccc745d4a59c8f2871fef19
GL_TUPLE=	cppit:libclangmm:043d96d0bfbfe4bbb216a0954992d744a35c60ab:libclangmm/lib/libclangmm \
		eidheim:tiny-process-library:953b19c4c0692b18fb729ffd30f1cc3412797cda:tinyprocesslibrary/lib/tiny-process-library
USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	TESTS

TESTS_CMAKE_BOOL=	BUILD_TESTING

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/include \
		-DCMAKE_LIBRARY_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg

.include <bsd.port.mk>
