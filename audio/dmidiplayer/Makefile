PORTNAME=	dmidiplayer
DISTVERSION=	1.5.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Featured MIDI file player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrumstick-rt.so:audio/drumstick \
		libuchardet.so:textproc/uchardet

USES=		compiler:c++11-lang cmake desktop-file-utils pkgconfig qt:5 tar:bz2
USE_QT=		core gui printsupport widgets buildtools_build linguisttools qmake_build

CMAKE_ON=	EMBED_TRANSLATIONS
CMAKE_OFF=	BUILD_DOCS

.include <bsd.port.mk>
