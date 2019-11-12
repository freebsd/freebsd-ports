# $FreeBSD$

PORTNAME=	terminal-image-viewer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-50
DISTVERSIONSUFFIX=	-g134ca73
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Display images in terminals using RGB ANSI codes & unicode characters

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../../LICENSE

USES=		compiler:c++17-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	stefanhaustein
GH_PROJECT=	TerminalImageViewer

MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
WRKSRC_SUBDIR=	src/main/cpp

PLIST_FILES=	bin/tiv

.if exists(/usr/include/c++/v1) && !exists(/usr/include/c++/v1/filesystem)
BROKEN=		STL feature 'filesystem' isn't available # '
.endif

.include <bsd.port.mk>
