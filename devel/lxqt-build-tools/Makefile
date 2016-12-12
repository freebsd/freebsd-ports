# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-build-tools
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Helpers CMake modules for LXQt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-3-Clause

USES=	cmake:outsource lxqt pkgconfig tar:xz
USE_QT5=	qmake_build buildtools_build core

.include <bsd.port.pre.mk>

# When the CXX compiler is GNU 4.2.1 (DragonFlyBSD seems to have >= 4.7.x)
# we get the following errors:
# cc1plus: error: unrecognized command line option "-flto"
# cc1plus: error: unrecognized command line option "-fuse-linker-plugin"
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000024
EXTRA_PATCHES=	${FILESDIR}/extra-patch-cmake_modules_LXQtCompilerSettings.cmake
.endif

.include <bsd.port.post.mk>
