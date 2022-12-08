PORTNAME=	dmidiplayer
DISTVERSION=	1.7.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Featured MIDI file player
WWW=		https://sourceforge.net/projects/dmidiplayer/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrumstick-widgets.so:audio/drumstick \
		libOpenGL.so:graphics/libglvnd \
		libuchardet.so:textproc/uchardet

USES=		compiler:c++17-lang cmake desktop-file-utils pkgconfig qt:6 tar:bz2
USE_QT=		base tools:build

CMAKE_ARGS=	-DUSE_QT=6
CMAKE_ON=	EMBED_TRANSLATIONS
CMAKE_OFF=	BUILD_DOCS

.include <bsd.port.mk>
