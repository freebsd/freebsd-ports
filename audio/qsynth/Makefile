# New ports collection makefile for:	qsynth
# Date created:		2007-11-17
# Whom:			lazyklimm <lazyklimm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qsynth
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	lazyklimm@gmail.com
COMMENT=	Qt fluidsynth front-end application

LIB_DEPENDS=	fluidsynth:${PORTSDIR}/audio/fluidsynth

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build uic_build rcc_build linguist_build
CFLAGS+=	-I${QT_INCDIR} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
LDFLAGS+=	-L${QT_LIBDIR}
CONFIGURE_ARGS+=ac_cv_path_ac_moc=${MOC} ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_qmake=${QMAKE} \
		ac_cv_path_ac_lupdate=${LOCALBASE}/bin/lupdate-qt4 \
		ac_cv_path_ac_lrelease=${LOCALBASE}/bin/lrelease-qt4
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
