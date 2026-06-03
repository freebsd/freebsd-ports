PORTNAME=	qtads
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.0
CATEGORIES=	games

MAINTAINER=	wes.frazier@avoidbig.tech
COMMENT=	Cross-platform, multimedia interpreter for TADS adventure games
WWW=		https://realnc.github.io/qtads/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libmpg123.so:audio/mpg123 \
		libsndfile.so:audio/libsndfile \
		libvorbisfile.so:audio/libvorbis

USES=		desktop-file-utils gl gmake pkgconfig qmake qt:5 sdl \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	realnc
USE_GL=		gl
USE_QT=		buildtools core gui network svg widgets
USE_SDL=	sdl2

DATADIR=	${PREFIX}/share/qtads

OPTIONS_DEFINE=		ICONS
OPTIONS_DEFAULT=	ICONS

OPTIONS_SUB=	yes

ICONS_DESC=			Install mimetype icons
ICONS_CONFLICTS_INSTALL=	gargoyle

.include <bsd.port.mk>
