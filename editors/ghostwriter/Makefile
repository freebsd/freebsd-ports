PORTNAME=	ghostwriter
DISTVERSION=	24.12.0
CATEGORIES=	editors kde

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Distraction-free Markdown editor
WWW=		https://ghostwriter.kde.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig kde:6 qt:6
USE_KDE=	configwidgets coreaddons doctools ecm:build sonnet widgetsaddons xmlgui
KDE_INVENT=	86e8255e5b571d949826f61bd1da24f241496b01 office
USE_QT=		base svg tools:build webchannel webengine

CMAKE_ARGS=	-DBUILD_WITH_QT6=ON \
		-DQT_MAJOR_VERSION=6

# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		CMARK PANDOC
OPTIONS_DEFAULT=	CMARK PANDOC

CMARK_DESC=		Add runtime dependency on cmark parser
PANDOC_DESC=		Add runtime dependency on pandoc parser

CMARK_BUILD_DEPENDS=	cmark>0:textproc/cmark

PANDOC_BUILD_DEPENDS=	hs-pandoc>0:textproc/hs-pandoc

.include <bsd.port.mk>
