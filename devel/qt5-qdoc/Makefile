PORTNAME=	qdoc
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation generator

USES=		compiler:c++11-lang llvm:build,run qmake qt-dist:5,tools
USE_QT=		core declarative buildtools:build qdoc-data:run

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ENV=	LLVM_INSTALL_DIR=${LLVM_PREFIX}

QT_BINARIES=	yes

.include <bsd.port.mk>
