PORTNAME=	ghostwriter
DISTVERSION=	2.2.0
CATEGORIES=	editors kde

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Distraction-free Markdown editor
WWW=		https://ghostwriter.kde.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		compiler:c++11-lang desktop-file-utils kde:5 pkgconfig qmake qt:5
USE_QT=		core gui svg webchannel webengine widgets buildtools:build \
		linguisttools:build

# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

KDE_INVENT=	151268bcfdca57bba4944caa7172dde9549f0622 office

post-configure:
	@${REINPLACE_CMD} -e 's|^\(build/release/qrc_QtAwesomeFree.cpp:[^\\]*\)\\|\1|' \
		-e '/3rdparty\/QtAwesome\/fonts\/Font/d' \
		-e '/\/lib\/qt5\/bin\/rcc \\/d' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
