PORTNAME=	spotify-qt
PORTVERSION=	4.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Lightweight Spotify client using Qt
WWW=		https://github.com/kraxarn/spotify-qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

RUN_DEPENDS=	spotifyd:audio/spotifyd

USES=		cmake compiler:c++11-lang qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	kraxarn
USE_QT=		base svg
USE_GL=		gl opengl

PLIST_FILES=	bin/spotify-qt \
		share/applications/spotify-qt.desktop \
		share/icons/hicolor/scalable/apps/spotify-qt.svg

.include <bsd.port.mk>
