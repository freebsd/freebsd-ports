# New ports collection makefile for:	qsampler
# Date created:		2007-03-06
# Whom:			trasz <trasz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qsampler
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION} \
		http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based front end to LinuxSampler

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gig.10:${PORTSDIR}/audio/libgig \
		lscp.6:${PORTSDIR}/audio/liblscp
RUN_DEPENDS=	linuxsampler:${PORTSDIR}/audio/linuxsampler

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_rcc=${RCC} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
MAKE_JOBS_SAFE=	yes

LUPDATE=	${LOCALBASE}/bin/lupdate-qt4
LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

post-patch:
	@${REINPLACE_CMD} -e 's|make -f|$$(MAKE) -f|' ${WRKSRC}/Makefile.in

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKEFLAGS}

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qsampler

.include <bsd.port.mk>
