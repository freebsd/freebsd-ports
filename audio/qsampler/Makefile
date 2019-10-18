# Created by: trasz <trasz@FreeBSD.org
# $FreeBSD$

PORTNAME=	qsampler
DISTVERSIONPREFIX=	qsampler_
DISTVERSION=	0_6_0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based front end to LinuxSampler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgig.so:audio/libgig \
		liblscp.so:audio/liblscp
RUN_DEPENDS=	linuxsampler:audio/linuxsampler

LDFLAGS+=	-L${LOCALBASE}/lib

USES=		autoreconf desktop-file-utils gl gmake pkgconfig \
		shared-mime-info qmake:no_env qt:5 xorg
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_cv_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_rcc=${RCC} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
CONFIGURE_ARGS=	--enable-qt5
USE_GL=		gl
USE_QT=		core gui network widgets x11extras \
		buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qsampler

.include <bsd.port.mk>
