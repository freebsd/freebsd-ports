PORTNAME=	ghostwriter
DISTVERSION=	2.2.0
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

USES=		compiler:c++11-lang desktop-file-utils kde:5 pkgconfig qmake

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT=		buildtools:build core gui linguisttools:build svg \
		webchannel webengine widgets
RCCREGEXP=	\/lib\/qt5\/bin\/rcc
.else
USES+=		qt:6
USE_QT=		5compat base svg tools webchannel webengine
RCCREGEXP=	\/libexec\/qt6\/rcc
.endif

# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

KDE_INVENT=	151268bcfdca57bba4944caa7172dde9549f0622 office

post-configure:
	@${REINPLACE_CMD} -e 's|^\(build/release/qrc_QtAwesomeFree.cpp:[^\\]*\)\\|\1|' \
		-e '/3rdparty\/QtAwesome\/fonts\/Font/d' \
		-e '/${RCCREGEXP} \\/d' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
