# $FreeBSD$

PORTNAME=	dspdfviewer
PORTVERSION=	1.15.1
DISTVERSIONPREFIX=v
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	Dual-screen PDF viewer for LaTeX-beamer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5 \
		libboost_program_options.so:devel/boost-libs

BUILD_WRKSRC=		${WRKSRC}/build
CONFIGURE_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=		${WRKSRC}/build

USES=		cmake pkgconfig
USE_QT5=	buildtools_build core gui qmake_build linguisttools widgets xml
CMAKE_ARGS=	-DPOPPLER_LIBRARIES=${LOCALBASE}/lib/libpoppler-qt5.so -DBuildTests=OFF
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dannyedel

PLIST_FILES=	bin/dspdfviewer \
		share/applications/dspdfviewer.desktop \
		man/man1/dspdfviewer.1.gz

.include <bsd.port.pre.mk>

# Build fails with LLVM 4.0.  Reported upstream as #191:
# https://github.com/dannyedel/dspdfviewer/issues/191
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200023
CFLAGS+=	-Wno-error=undefined-func-template
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200039
CFLAGS+=	-Wno-error=zero-as-null-pointer-constant
.endif

.include <bsd.port.post.mk>
