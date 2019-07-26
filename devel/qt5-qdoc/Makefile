# $FreeBSD$

PORTNAME=	qdoc
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation generator

BUILD_DEPENDS=	llvm60>=0:devel/llvm60
RUN_DEPENDS=	llvm60>=0:devel/llvm60

USES=		compiler:c++11-lang qmake qt-dist:5,tools
USE_QT=		core declarative buildtools_build qdoc-data_run

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	${QT_BINDIR}/qdoc

CONFIGURE_ENV=	LLVM_INSTALL_DIR=${LOCALBASE}/llvm60

.include <bsd.port.mk>
