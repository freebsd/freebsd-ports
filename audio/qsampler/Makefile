# New ports collection makefile for:	qsampler
# Date created:		2007-03-06
# Whom:			trasz <trasz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qsampler
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Qt-based front end to LinuxSampler

LIB_DEPENDS=	lscp.6:${PORTSDIR}/audio/liblscp \
		gig.10:${PORTSDIR}/audio/libgig
RUN_DEPENDS=	linuxsampler:${PORTSDIR}/audio/linuxsampler

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_path_ac_qmake=qmake-qt4 ac_cv_path_ac_moc=moc-qt4 ac_cv_path_ac_uic=uic-qt4 \
		ac_cv_path_ac_rcc=rcc-qt4 ac_cv_path_ac_lupdate=lupdate-qt4 ac_cv_path_ac_lrelease=lrelease-qt4
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake moc uic rcc linguist
CFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
