# Created by: trasz <trasz@FreeBSD.org
# $FreeBSD$

PORTNAME=	qsampler
PORTVERSION=	0.2.3
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based front end to LinuxSampler

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libgig.so:${PORTSDIR}/audio/libgig \
		liblscp.so:${PORTSDIR}/audio/liblscp
RUN_DEPENDS=	linuxsampler:${PORTSDIR}/audio/linuxsampler

USES=		gmake shared-mime-info
USE_QT4=	corelib gui \
		linguist_build moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_rcc=${RCC} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
INSTALLS_ICONS=	yes

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qsampler

.include <bsd.port.mk>
