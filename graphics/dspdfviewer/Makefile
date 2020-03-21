# $FreeBSD$

PORTNAME=	dspdfviewer
PORTVERSION=	1.15.1
DISTVERSIONPREFIX=	v
PORTREVISION=	27
CATEGORIES=	graphics

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Dual-screen PDF viewer for LaTeX-beamer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		cmake:insource pkgconfig qt:5
USE_QT=		core gui linguisttools widgets xml buildtools_build qmake_build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dannyedel

BUILD_WRKSRC=		${WRKSRC}/build
CONFIGURE_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=		${WRKSRC}/build

CMAKE_ARGS=	-DBuildTests=OFF \
		-DPOPPLER_LIBRARIES=${LOCALBASE}/lib/libpoppler-qt5.so

PLIST_FILES=	bin/dspdfviewer \
		man/man1/dspdfviewer.1.gz \
		share/applications/dspdfviewer.desktop

.include <bsd.port.pre.mk>

# Build fails with LLVM 4.0.  Reported upstream as #191:
# https://github.com/dannyedel/dspdfviewer/issues/191
CFLAGS+=	-Wno-error=undefined-func-template

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200039
CFLAGS+=	-Wno-error=zero-as-null-pointer-constant
.endif

# Fixes build failure for Clang 8.0.0
.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1300014 || (${OSVERSION} >= 1103000 && ${OSVERSION} < 1200000) || ${OSVERSION} >= 1201000)
CFLAGS+=	-Wno-error=extra-semi-stmt
.endif

CFLAGS+=	-Wno-error=redundant-parens

.include <bsd.port.post.mk>
