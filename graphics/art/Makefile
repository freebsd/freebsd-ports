# $FreeBSD$

PORTNAME=	art
DISTVERSION=	1.8.2
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/agriggio/art/downloads/
PKGNAMESUFFIX=	-raw-image-editor
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Raw image processing program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	ld: error: undefined symbol: __atomic_load

EXTRACT_DEPENDS=	gtar:archivers/gtar # bsdtar(1) complains about hard links to itself
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libfftw3f.so:math/fftw3-float \
		liblensfun.so:graphics/lensfun \
		liblcms2.so:graphics/lcms2 \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang desktop-file-utils gnome jpeg pkgconfig tar:xz xorg
USE_GNOME=	atk atkmm cairo cairomm glibmm gtkmm30 librsvg2
USE_XORG=	x11

EXTRACT_CMD=	gtar

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

# breaks with llvm-8
.if ${CHOSEN_COMPILER_TYPE} == clang
LLVM_VERSION=	10
BUILD_DEPENDS+=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
.endif

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/ART

.include <bsd.port.post.mk>
