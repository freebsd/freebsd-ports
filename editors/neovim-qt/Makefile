# $FreeBSD$

PORTNAME=	neovim-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.10
CATEGORIES=	editors

MAINTAINER=	chuck@tuffli.net
COMMENT=	Neovim client library and QT5 GUI

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	neovim>=0:editors/neovim
LIB_DEPENDS=	libmsgpackc.so:devel/msgpack
RUN_DEPENDS=	neovim>=0:editors/neovim

USES=		cmake desktop-file-utils qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	equalsraf
USE_QT=		core gui testlib network widgets buildtools_build qmake_build

CMAKE_ON=	USE_SYSTEM_MSGPACK
CMAKE_OFF=	ENABLE_TESTS

DATADIR=	${PREFIX}/share/nvim-qt

.include <bsd.port.mk>
