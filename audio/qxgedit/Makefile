PORTNAME=	qxgedit
DISTVERSION=	0.9.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Editor for MIDI System Exclusive files for XG devices

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake compiler:c++17-lang pkgconfig qt:5
USE_QT=		core gui network widgets buildtools_build qmake_build

.include <bsd.port.mk>
