PORTNAME=	qxgedit
DISTVERSION=	0.9.10
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Editor for MIDI System Exclusive files for XG devices
WWW=		https://qxgedit.sourceforge.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig qt:6
USE_QT=		base svg tools:build
USE_GL=		gl opengl

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
