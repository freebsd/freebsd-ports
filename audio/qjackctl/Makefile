# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	qjackctl
DISTVERSIONPREFIX=	qjackctl_
DISTVERSION=	0_5_0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt interface for JACK Audio Connection Kit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		autoreconf gmake localbase pkgconfig
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_lrelease=${LRELEASE} \
		ac_cv_path_ac_lupdate=${LUPDATE}

OPTIONS_DEFINE=		ALSA PORTAUDIO SYSTRAY
OPTIONS_DEFAULT=	QT5 SYSTRAY
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5

SYSTRAY_DESC=		System tray icon support
TOOLKIT_DESC=		Qt toolkit

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa_seq

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_ENABLE=	portaudio

SYSTRAY_CONFIGURE_ENABLE=	system-tray

QT4_USE=		QT4=corelib,dbus,gui,xml \
			QT4=linguisttools_build \
			QT4=moc_build,qmake_build,rcc_build,uic_build
QT4_CONFIGURE_ENABLE=	qt4

QT5_USES=		compiler:c++11-lib
QT5_USE=		QT5=core,dbus,gui,widgets,x11extras,xml \
			QT5=buildtools_build,linguisttools_build,qmake_build \
			GL=gl \
			CXXSTD=c++11

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

.include <bsd.port.mk>
