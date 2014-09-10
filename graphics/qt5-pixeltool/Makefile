# $FreeBSD$

PORTNAME=	pixeltool
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 screen magnifier

USE_QT5=	core network widgets buildtools_build
QT_DIST=	tools
USES=		qmake

# qt5logo.png is installed by qt5-widgets.
DESKTOP_ENTRIES="Qt 5 PixelTool" "" \
		"${QT_PREFIX}/share/pixmaps/qt5logo.png" \
		"${PREFIX}/${QT_BINDIR_REL}/pixeltool" \
		"Graphics;Qt;" true

WRKSRC_SUBDIR=	src/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/DESTDIR/ d' \
		${WRKSRC}/pixeltool.pro

.include <bsd.port.mk>
