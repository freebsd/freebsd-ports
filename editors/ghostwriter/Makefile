PORTNAME=	ghostwriter
DISTVERSION=	24.02.1
CATEGORIES=	editors kde

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Distraction-free Markdown editor
WWW=		https://ghostwriter.kde.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

FLAVORS=	qt5 qt6
FLAVOR?=	qt5
qt5_PKGNAMESUFFIX=
qt6_PKGNAMESUFFIX=	-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig
USE_KDE=	configwidgets coreaddons doctools ecm:build sonnet widgetsaddons xmlgui

.if ${FLAVOR} == qt5
USES+=		kde:5 qt:5
USE_QT=		buildtools:build core gui linguisttools:build qmake:build \
		webchannel webengine widgets
.else
CMAKE_ARGS=	-DBUILD_WITH_QT6=ON \
		-DQT_MAJOR_VERSION=6
USES+=		kde:6 qt:6
USE_QT=		5compat base svg tools:build webchannel webengine
.endif

# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

KDE_INVENT=	55792d3e4a2e6599e968fae262d8b0a3a224b100 office

OPTIONS_DEFINE=		CMARK PANDOC
OPTIONS_DEFAULT=	CMARK PANDOC

CMARK_DESC=		Add runtime dependency on cmark parser
PANDOC_DESC=		Add runtime dependency on pandoc parser

CMARK_BUILD_DEPENDS=	cmark>0:textproc/cmark

PANDOC_BUILD_DEPENDS=	hs-pandoc>0:textproc/hs-pandoc

.include <bsd.port.mk>
