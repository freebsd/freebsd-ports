PORTNAME=	terminal-image-viewer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Display images in terminals using RGB ANSI codes & unicode characters
WWW=		https://github.com/stefanhaustein/TerminalImageViewer

LICENSE=	APACHE20

RUN_DEPENDS=	GraphicsMagick>0:graphics/GraphicsMagick

USES=		compiler:c++17-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	stefanhaustein
GH_PROJECT=	TerminalImageViewer

MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/tiv

.include <bsd.port.mk>
