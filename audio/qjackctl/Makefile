# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	qjackctl
PORTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt Interface for the JACK Audio Connection Kit

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

USES=		gmake
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=		ALSA PORTAUDIO
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT4

ALSA_LIB_DEPENDS= 	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa_seq
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio
PORTAUDIO_CONFIGURE_ENABLE=	portaudio
QT4_USE=		qt4=corelib,dbus,gui,xml \
			qt4=linguisttools_build \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_CONFIGURE_ENABLE=	qt4
QT5_USE=		qt5=core,dbus,gui,widgets,xml \
			qt5=buildtools_build,linguisttools_build,qmake_build
QT5_CXXFLAGS=		-fPIC
QT5_CONFIGURE_ENABLE=	qt5
TOOLKIT_DESC=		Qt toolkit

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

.include <bsd.port.mk>
