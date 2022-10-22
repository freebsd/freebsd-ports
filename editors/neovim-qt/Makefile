PORTNAME=	neovim-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.17
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neovim client library and QT5 GUI
WWW=		https://github.com/equalsraf/neovim-qt/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	neovim>=0:editors/neovim \
		unibilium>=0:devel/unibilium
LIB_DEPENDS=	libmsgpackc.so:devel/msgpack-c \
		libunibilium.so:devel/unibilium
RUN_DEPENDS=	neovim>=0:editors/neovim

USES=		cmake compiler:c++11-lang desktop-file-utils qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	equalsraf
USE_QT=		core gui network svg testlib widgets buildtools:build \
		qmake:build

CMAKE_ON=	USE_SYSTEM_MSGPACK
CMAKE_OFF=	ENABLE_TESTS

DATADIR=	${PREFIX}/share/nvim-qt

PORTSCOUT=	limit:^d\.d\.

.include <bsd.port.mk>
