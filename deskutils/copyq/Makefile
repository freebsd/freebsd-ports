# $FreeBSD$

PORTNAME=	copyq
PORTVERSION=	3.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt5 based clipboard manager

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake qt:5
USE_XORG=	ice sm x11 xext xfixes xtst
USE_QT=		core gui network script svg widgets x11extras xml \
		buildtools_build linguist_build qmake_build \
		imageformats_run

USE_GITHUB=	yes
GH_ACCOUNT=	hluk
GH_PROJECT=	CopyQ

CMAKE_ARGS=		-DMANPAGE_INSTALL_PREFIX:PATH=${MANPREFIX}/man/man1

OPTIONS_DEFINE=		PLUGINS WEBKIT
OPTIONS_DEFAULT=	PLUGINS WEBKIT
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

WEBKIT_USE=		qt=webkit
WEBKIT_CMAKE_BOOL=	WITH_WEBKIT
WEBKIT_IMPLIES=		PLUGINS

.include <bsd.port.mk>
