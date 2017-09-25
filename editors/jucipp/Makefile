# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	jucipp
PORTVERSION=	1.2.4
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	info@babaei.net
COMMENT=	Lightweight C++-IDE with support for C++11, C++14 and C++17

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libboost_filesystem.so:devel/boost-libs \
		libgit2.so:devel/libgit2 \
		libclang.so:devel/llvm40

USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3
USES=		cmake:outsource desktop-file-utils pkgconfig
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cppit
GH_TUPLE=	cppit:libclangmm:1ef0424:libclangmm/libclangmm \
		eidheim:tiny-process-library:8025c45:tiny_process_library/tiny-process-library

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg

post-patch:
# Make sure that jucipp can find LLVM 4.0
	@${REINPLACE_CMD} 's,[[:<:]]llvm39/\(.*\)[[:>:]],llvm40/\1,g' \
		${WRKSRC}/cmake_modules/FindLibClang.cmake

.include <bsd.port.mk>
