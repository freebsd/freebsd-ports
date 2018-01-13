# Created by: trasz <trasz@FreeBSD.org
# $FreeBSD$

PORTNAME=	qsampler
DISTVERSIONPREFIX=	qsampler_
DISTVERSION=	0_5_0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based front end to LinuxSampler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgig.so:audio/libgig \
		liblscp.so:audio/liblscp
RUN_DEPENDS=	linuxsampler:audio/linuxsampler

LDFLAGS+=	-L${LOCALBASE}/lib

USES=	autoreconf gmake pkgconfig shared-mime-info
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_cv_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_rcc=${RCC} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
USE_GL=	gl

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

TOOLKIT_DESC=	Qt toolkit

QT4_USE=	qt4=corelib,gui \
		qt4=linguisttools_build \
		qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_CONFIGURE_ENABLE=	qt4

QT5_USE=	qt5=core,gui,widgets,x11extras \
		qt5=buildtools_build,linguisttools_build,qmake_build
QT5_CONFIGURE_ENABLE=	qt5

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qsampler

.include <bsd.port.mk>
