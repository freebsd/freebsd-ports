# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bambootracker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.4
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt:extras
DISTFILES=	${PORTNAME}-extras-${EXTRASVERSION}${EXTRACT_SUFX}:extras

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music tracker for the Yamaha YM2608 (OPNA) sound chip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang qmake qt:5 gl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	rerrahkr
GH_PROJECT=	BambooTracker
USE_GL=		gl
USE_QT=		buildtools core gui linguisttools_build multimedia network \
		widgets

BUILD_WRKSRC=		${WRKSRC}/BambooTracker
CONFIGURE_WRKSRC=	${WRKSRC}/BambooTracker

PORTEXAMPLES=	*

EXTRASVERSION=	2

OPTIONS_DEFINE=	ALSA EXAMPLES JACK NLS PULSEAUDIO
OPTIONS_DEFAULT=PULSEAUDIO

ALSA_DESC=	ALSA audio architecture support (EXPERIMENTAL)
JACK_DESC=	JACK audio server support (EXPERIMENTAL)

OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
JACK_LIB_DEPENDS=	libjack.so:audio/jack
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
QMAKE_ARGS+=	CONFIG+="use_alsa"
.endif

.if ${PORT_OPTIONS:MJACK}
QMAKE_ARGS+=	CONFIG+="use_jack" \
		CONFIG+="jack_has_rename"
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
QMAKE_ARGS+=	CONFIG+="use_pulse"
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons \
		${STAGEDIR}${MANPREFIX}/man/fr.UTF-8/man1
	${INSTALL_PROGRAM} ${WRKSRC}/BambooTracker/BambooTracker \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/BambooTracker.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/BambooTracker.fr.1 \
		${STAGEDIR}${MANPREFIX}/man/fr.UTF-8/man1
	${INSTALL_DATA} ${WRKSRC}/BambooTracker.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/img/icon.png \
		${STAGEDIR}${PREFIX}/share/icons/BambooTracker.png

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demos/modules/*.btm \
		${WRKDIR}/${PORTNAME}-extras-${EXTRASVERSION}/*.btm \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
