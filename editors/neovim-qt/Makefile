PORTNAME=	neovim-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.19
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neovim client library and Qt6 GUI
WWW=		https://github.com/equalsraf/neovim-qt/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	neovim>=0:editors/neovim
LIB_DEPENDS=	libmsgpack-c.so:devel/msgpack-c
RUN_DEPENDS=	neovim>=0:editors/neovim

USES=		cmake desktop-file-utils gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	equalsraf
USE_GL=		opengl
USE_QT=		base svg

CMAKE_ARGS=	-DWITH_QT=Qt6
CMAKE_ON=	USE_SYSTEM_MSGPACK
CMAKE_OFF=	ENABLE_TESTS

DATADIR=	${PREFIX}/share/nvim-qt

PORTSCOUT=	limit:^d\.d\.

.include <bsd.port.mk>
