# $FreeBSD$

PORTNAME=	QtBitcoinTrader
DISTVERSION=	1.40.52
CATEGORIES=	finance
MASTER_SITES=	SF/bitcointrader/SRC/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Secure client uses latest OpenSSL and best encryption

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL3

USES=		compiler:c++11-lib gl qmake qt:5 ssl xorg
USE_QT=		core gui multimedia network script speech widgets buildtools_build
USE_GL=		gl

WRKSRC_SUBDIR=	src

QMAKE_ARGS=	DESKTOPDIR=${PREFIX}/share/applications ICONDIR=${PREFIX}/share/pixmaps

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
