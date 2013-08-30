# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	qjackctl
DISTVERSION=	0.3.10
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt Interface for the JACK Audio Connection Kit

LICENSE=	GPLv2

LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib \
		jack:${PORTSDIR}/audio/jack

USE_QT4=	corelib dbus gui xml \
		linguist_build moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
CONFIGURE_ARGS=	--disable-portaudio
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

MAN1=		qjackctl.1

LUPDATE=	${LOCALBASE}/bin/lupdate-qt4
LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKEFLAGS}

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
