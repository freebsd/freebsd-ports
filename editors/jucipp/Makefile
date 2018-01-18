# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	jucipp
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	info@babaei.net
COMMENT=	Lightweight C++-IDE with support for C++11, C++14 and C++17

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libboost_filesystem.so:devel/boost-libs \
		libgit2.so:devel/libgit2 \
		libclang.so:devel/llvm50

USES=		cmake:outsource desktop-file-utils pkgconfig
USE_GNOME=	gdkpixbuf2 gtkmm30 gtksourceviewmm3
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cppit
GH_TUPLE=	cppit:libclangmm:d978517:libclangmm/libclangmm \
		eidheim:tiny-process-library:cf212df:tiny_process_library/tiny-process-library

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg

.include <bsd.port.mk>
