# Created by: lazyklimm <lazyklimm@gmail.com>
# $FreeBSD$

PORTNAME=	qsynth
PORTVERSION=	0.4.1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt fluidsynth front-end application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		gmake
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_cv_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
CONFIGURE_ARGS=	--localedir=${DATADIR} \
		--with-fluidsynth=${LOCALBASE}

OPTIONS_DEFINE=		GRADIENT SYSTEM_TRAY
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	GRADIENT QT4 SYSTEM_TRAY

GRADIENT_DESC=		Gradient eye-candy
GRADIENT_CONFIGURE_ENABLE=	gradient
QT4_USE=		qt4=corelib,gui \
			qt4=linguisttools_build \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_CONFIGURE_ENABLE=	qt4
QT5_USE=		qt5=core,gui,widgets,x11extras \
			qt5=buildtools_build,linguisttools_build,qmake_build
QT5_CONFIGURE_ENABLE=	qt5
SYSTEM_TRAY_DESC=	System-tray icon support
SYSTEM_TRAY_CONFIGURE_ENABLE=	system-tray
TOOLKIT_DESC=		Qt toolkit

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o qsynth.mak \
		${QMAKE_ARGS})

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qsynth

.include <bsd.port.mk>
