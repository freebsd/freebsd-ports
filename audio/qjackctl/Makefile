# New ports collection makefile for:	qjackctl
# Date created:		2006-12-06
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	qjackctl
DISTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qjackctl

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Qt Interface for the JACK Audio Connection Kit

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build gui xml linguist_build
CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
CONFIGURE_ARGS+=ac_cv_path_ac_moc=${LOCALBASE}/bin/moc-qt4 \
		ac_cv_path_ac_uic=${LOCALBASE}/bin/uic-qt4 \
		ac_cv_path_ac_qmake=${LOCALBASE}/bin/qmake-qt4 \
		ac_cv_path_ac_lupdate=${LOCALBASE}/bin/lupdate-qt4 \
		ac_cv_path_ac_lrelease=${LOCALBASE}/bin/lrelease-qt4

.include <bsd.port.mk>
