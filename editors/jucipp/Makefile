# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	jucipp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
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
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake compiler:c++14-lang desktop-file-utils gnome pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	cppit
GL_COMMIT=	22b7c68c9f740f5db1c93c699068568fc87b3a07
GL_TUPLE=	cppit:libclangmm:a0316826f7f0c91949c6e11376fd4e92e39a008c:libclangmm/lib/libclangmm \
		eidheim:tiny-process-library:a6773276efdbc322f1abb0159301f5502647eb52:tinyprocesslibrary/lib/tiny-process-library
USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/include \
		-DCMAKE_LIBRARY_PATH=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg

.include <bsd.port.mk>
