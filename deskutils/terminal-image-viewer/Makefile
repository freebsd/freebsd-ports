PORTNAME=	terminal-image-viewer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Display images in terminals using RGB ANSI codes & unicode characters

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

RUN_DEPENDS=	GraphicsMagick>0:graphics/GraphicsMagick

USES=		compiler:c++17-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	stefanhaustein
GH_PROJECT=	TerminalImageViewer

MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
WRKSRC_SUBDIR=	src/main/cpp

PLIST_FILES=	bin/tiv

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile
.endif

.include <bsd.port.post.mk>
