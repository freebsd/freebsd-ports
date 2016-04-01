# $FreeBSD$

PORTNAME=	linpsk
PORTVERSION=	1.2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Simple Qt PSK31, RTTY, and MSK31 client

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libasound.so:audio/alsa-lib

USES=		qmake tar:tgz
USE_QT4=	gui network corelib moc_build uic_build rcc_build qmake_build
DESKTOP_ENTRIES="LinPsk" "${COMMENT}" \
		"${DATADIR}/linpsk.png" "linpsk" "Audio;HamRadio;" \
		false

PLIST_FILES=	bin/linpsk \
		%%DATADIR%%/linpsk.png

post-patch:
	${REINPLACE_CMD} -e 's|<pixmapfunction>qPixmapFromMimeSource</pixmapfunction>|<!-- & -->|g' \
		${WRKSRC}/gui/*.ui

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/images/linpsk.png ${STAGEDIR}${DATADIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/linpsk

.include <bsd.port.mk>
