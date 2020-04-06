# $FreeBSD$

PORTNAME=	jucipp
DISTVERSION=	1.5.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight IDE supporting the most recent C++ standards

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libboost_filesystem.so:devel/boost-libs \
		libgit2.so:devel/libgit2

USES=		cmake desktop-file-utils gnome pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	cppit
GL_COMMIT=	22b7c68c9f740f5db1c93c699068568fc87b3a07
GL_TUPLE=	cppit:libclangmm:2edcb84b34b118e34ed498bdbfab43e440280448:libclangmm/lib/libclangmm \
		eidheim:tiny-process-library:f7e762200c3dafd340f8e730705a2f63042e2c10:tiny_process_library/lib/tiny-process-library
USE_GNOME=	gdkpixbuf2 gtk30 gtkmm30 gtksourceviewmm3

INSTALLS_ICONS=	yes

PLIST_FILES=	bin/juci \
		share/applications/juci.desktop \
		share/icons/hicolor/scalable/apps/juci.svg

# use clang from ports because the project uses libclang.so and always links to the clang from ports anyway
LLVM_VERSION=	${LLVM_DEFAULT}
LIB_DEPENDS+=	libclang.so:devel/llvm${LLVM_VERSION}
CPP=		clang-cpp${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}

.include <bsd.port.mk>
