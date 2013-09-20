# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	quimup
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd/Quimup/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4 Client for MPD (the Music Player Daemon)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	mpdclient:${PORTSDIR}/audio/libmpdclient

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

NO_STAGE=	yes
USE_QT4=	corelib gui network \
		moc_build qmake_build rcc_build uic_build

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="Quimup" "" "${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Audio;AudioVideo;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e \
		's|qt release -O2|qt| ; \
		 s|/usr/lib/|${LOCALBASE}/lib/| ; \
		 s|^QMAKE_|#QMAKE_|' ${WRKSRC}/${PORTNAME}.pro

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
	(cd ${WRKSRC}/src/resources && ${INSTALL_DATA} mn_icon.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png)

.include <bsd.port.mk>
