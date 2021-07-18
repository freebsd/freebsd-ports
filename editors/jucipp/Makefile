# Created by: Mohammad S. Babaei <info@babaei.net>

PORTNAME=	jucipp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.3
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
GL_COMMIT=	e59cb70467a085cb00fba75a748fe8b7b5431624
GL_TUPLE=	cppit:libclangmm:11fc6bb436fea00abc23fa2464781880642de5e5:libclangmm/lib/libclangmm \
		eidheim:tiny-process-library:15e4f77f8254e4b093f6be128db50fe4b6bee120:tinyprocesslibrary/lib/tiny-process-library
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
