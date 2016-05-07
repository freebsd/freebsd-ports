# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	qjackctl
PORTVERSION=	0.4.2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt interface for JACK Audio Connection Kit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		gmake
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_lrelease=${LRELEASE} \
		ac_cv_path_ac_lupdate=${LUPDATE}

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=		ALSA PORTAUDIO SYSTRAY
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT4 SYSTRAY

TOOLKIT_DESC=		Qt toolkit

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa_seq

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_ENABLE=	portaudio

SYSTRAY_DESC=		System tray icon support
SYSTRAY_CONFIGURE_WITH=	system-tray

QT4_USE=		qt4=corelib,dbus,gui,xml \
			qt4=linguisttools_build \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_CONFIGURE_ENABLE=	qt4
QT5_USE=		qt5=core,dbus,gui,widgets,x11extras,xml \
			qt5=buildtools_build,linguisttools_build,qmake_build
QT5_CONFIGURE_ENABLE=	qt5

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

.include <bsd.port.mk>
