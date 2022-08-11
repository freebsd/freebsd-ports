PORTNAME=	quimup
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	Quimup_${PORTVERSION}_source

MAINTAINER=	cmangin@arobas.net
COMMENT=	Qt5 client for MPD (the Music Player Daemon)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libtag.so:audio/taglib

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_QT=		core gui network widgets buildtools_build
USE_GL=		gl

WRKSRC=		${WRKDIR}/Quimup_${PORTVERSION}_source

CXXFLAGS+=	-std=c++11

PLIST_FILES=	bin/quimup \
		share/pixmaps/quimup.png

DESKTOP_ENTRIES="Quimup" "MPD client" "quimup" "quimup" \
		"Audio;AudioVideo;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#define get_time/d' ${WRKSRC}/src/qm_playlistview.h
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/qm_mpdcom.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quimup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/resources/mn_icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/quimup.png

.include <bsd.port.mk>
