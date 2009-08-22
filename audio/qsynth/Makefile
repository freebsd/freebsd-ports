# New ports collection makefile for:	qsynth
# Date created:		2007-11-17
# Whom:			lazyklimm <lazyklimm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qsynth
DISTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	lazyklimm@gmail.com
COMMENT=	Qt fluidsynth front-end application

LIB_DEPENDS=	fluidsynth:${PORTSDIR}/audio/fluidsynth

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build gui xml
CFLAGS+=	-I${QT_INCDIR} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
LDFLAGS+=	-L${QT_LIBDIR}
CONFIGURE_ARGS+=ac_cv_path_ac_moc=${LOCALBASE}/bin/moc-qt4 ac_cv_path_ac_uic=${LOCALBASE}/bin/uic-qt4 \
		ac_cv_path_ac_qmake=${LOCALBASE}/bin/qmake-qt4

.include <bsd.port.mk>
