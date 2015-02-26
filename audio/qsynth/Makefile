# Created by: lazyklimm <lazyklimm@gmail.com>
# $FreeBSD$

PORTNAME=	qsynth
PORTVERSION=	0.3.8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt fluidsynth front-end application

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth

OPTIONS_DEFINE=	GRADIENT SYSTEM_TRAY
OPTIONS_DEFAULT=	GRADIENT SYSTEM_TRAY
GRADIENT_DESC=		Gradient eye-candy
GRADIENT_CONFIGURE_ENABLE=	gradient
SYSTEM_TRAY_DESC=	System-tray icon
SYSTEM_TRAY_CONFIGURE_ENABLE=	system-tray

USES=		gmake
USE_QT4=	gui linguisttools_build moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
CONFIGURE_ARGS=	--localedir=${DATADIR} \
		--with-qt=${QT_PREFIX} \
		--with-fluidsynth=${LOCALBASE}
INSTALLS_ICONS=	yes

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o qsynth.mak \
		${QMAKE_ARGS})

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qsynth

.include <bsd.port.mk>
