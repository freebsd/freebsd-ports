# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	qjackctl
DISTVERSION=	0.3.13
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt Interface for the JACK Audio Connection Kit

LICENSE=	GPLv2

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		libjack.so:${PORTSDIR}/audio/jack

USES=		gmake
USE_QT4=	corelib dbus gui xml \
		linguisttools_build moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
CONFIGURE_ARGS=	--disable-portaudio
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

.include <bsd.port.mk>
