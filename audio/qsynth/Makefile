# Created by: lazyklimm <lazyklimm@gmail.com>
# $FreeBSD$

PORTNAME=	qsynth
PORTVERSION=	0.6.0
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Qt fluidsynth front-end application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		compiler:c++11-lang gmake pkgconfig qt:5
USE_CXXSTD=	c++11
USE_QT=		core gui network widgets x11extras buildtools_build \
		linguisttools_build qmake_build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localedir=${DATADIR} \
		--with-fluidsynth=${LOCALBASE}
CONFIGURE_ENV=	ac_cv_path_ac_cv_qmake=${QMAKE} \
		ac_cv_path_ac_lrelease=${LRELEASE} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC}

# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		GRADIENT SYSTEM_TRAY XUNIQUE
OPTIONS_DEFAULT=	GRADIENT SYSTEM_TRAY XUNIQUE

GRADIENT_DESC=		Gradient eye-candy
SYSTEM_TRAY_DESC=	System-tray icon support
XUNIQUE_DESC=		X11 unique/single instance

GRADIENT_CONFIGURE_ENABLE=	gradient
SYSTEM_TRAY_CONFIGURE_ENABLE=	system-tray
XUNIQUE_USES=			xorg
XUNIQUE_USE=			XORG=x11
XUNIQUE_CONFIGURE_ENABLE=	xunique

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|oss,alsa,alsa_seq,|jack,sndio,oss,|; \
		s|alsa,jack,oss,dsound,|jack,sndio,oss,|; \
		s|"/MidiDriver", "alsa_seq"|"/MidiDriver", "jack"|; \
		s|m_settings.value("/SoundFontDir").toString();|m_settings.value("/SoundFontDir").toString().isEmpty() ? "${LOCALBASE}/share/sounds/sf2" : m_settings.value("/SoundFontDir").toString();|' \
		${WRKSRC}/src/qsynthOptions.cpp \
		${WRKSRC}/qsynth.1 ${WRKSRC}/qsynth.fr.1

.include <bsd.port.mk>
