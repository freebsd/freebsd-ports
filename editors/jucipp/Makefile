# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	jucipp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	info@babaei.net
COMMENT=	Lightweight C++-IDE with support for C++11, C++14 and C++17

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libboost_filesystem.so:devel/boost-libs \
		libgit2.so:devel/libgit2 \
		libclang.so.5:devel/llvm50

USES=		cmake:outsource compiler:c++14-lang desktop-file-utils pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	cppit
GH_TUPLE=	cppit:libclangmm:5a0195e:libclangmm/libclangmm \
		eidheim:tiny-process-library:a034812:tiny_process_library/tiny-process-library
USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3
INSTALLS_ICONS=	yes

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH=${LOCALBASE}/llvm50/include \
		-DCMAKE_LIBRARY_PATH=${LOCALBASE}/llvm50/lib

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg

.include <bsd.port.mk>
