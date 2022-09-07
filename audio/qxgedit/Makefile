PORTNAME=	qxgedit
DISTVERSION=	0.9.6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Editor for MIDI System Exclusive files for XG devices
WWW=		https://qxgedit.sourceforge.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake compiler:c++17-lang pkgconfig qt:5
USE_QT=		core gui network widgets buildtools_build qmake_build

.include <bsd.port.mk>
