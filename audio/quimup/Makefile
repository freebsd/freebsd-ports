# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	quimup
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd/Quimup/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 4 client for MPD (the Music Player Daemon)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

USES=		qmake
USE_QT4=	corelib gui network \
		moc_build rcc_build uic_build

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="Quimup" "MPD client" "${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Audio;AudioVideo;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CONFIG/s|-O2|| ; \
		 s|/usr/lib/|${LOCALBASE}/lib/| ; \
		 s|^QMAKE_|#QMAKE_|' ${WRKSRC}/${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/resources/mn_icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
