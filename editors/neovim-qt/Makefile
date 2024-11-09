PORTNAME=	neovim-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.18
CATEGORIES=	editors
PKGNAMESUFFIX=	${FLAVOR:S/qt//}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neovim client library and QT${FLAVOR:S/qt//} GUI
WWW=		https://github.com/equalsraf/neovim-qt/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	neovim>=0:editors/neovim
LIB_DEPENDS=	libmsgpack-c.so:devel/msgpack-c
RUN_DEPENDS=	neovim>=0:editors/neovim

FLAVORS=		qt5 qt6
FLAVOR?=		${FLAVORS:[1]}
qt5_CONFLICTS_INSTALL=	neovim-qt6
qt6_CONFLICTS_INSTALL=	neovim-qt5

USES=		${_USES_${FLAVOR}} cmake desktop-file-utils qt:${FLAVOR:S/qt//}
USE_GITHUB=	yes
GH_ACCOUNT=	equalsraf
_USES_qt6=	gl
_USE_QT_qt5=	core gui network svg testlib widgets buildtools:build \
		qmake:build
_USE_QT_qt6=	base svg
_USE_GL_qt6=	opengl
USE_GL=		${_USE_GL_${FLAVOR}}
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ARGS=	-DWITH_QT=Qt${FLAVOR:S/qt//}
CMAKE_ON=	USE_SYSTEM_MSGPACK
CMAKE_OFF=	ENABLE_TESTS

DATADIR=	${PREFIX}/share/nvim-qt

PORTSCOUT=	limit:^d\.d\.

.include <bsd.port.mk>
