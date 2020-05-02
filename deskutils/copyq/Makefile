# $FreeBSD$

PORTNAME=	copyq
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.0
CATEGORIES=	deskutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Qt5 based clipboard manager

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	hluk
GH_PROJECT=	CopyQ
USE_LDCONFIG=	yes
USE_QT=		core gui network script svg widgets x11extras imageformats_run \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	x11 xtst

LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		PLUGINS WEBKIT
OPTIONS_DEFAULT=	PLUGINS WEBKIT
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

WEBKIT_IMPLIES=		PLUGINS
WEBKIT_USE=		qt=webkit
WEBKIT_CMAKE_BOOL=	WITH_WEBKIT

.include <bsd.port.mk>
