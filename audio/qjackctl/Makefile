# New ports collection makefile for:	qjackctl
# Date created:		2006-12-06
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	qjackctl
DISTVERSION=	0.3.1a
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qjackctl

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Qt Interface for the JACK Audio Connection Kit

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake moc uic rcc gui xml
CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
CONFIGURE_ARGS+=ac_cv_path_ac_moc=${LOCALBASE}/bin/moc-qt4 ac_cv_path_ac_uic=${LOCALBASE}/bin/uic-qt4 \
		ac_cv_path_ac_qmake=${LOCALBASE}/bin/qmake-qt4

.include <bsd.port.mk>
