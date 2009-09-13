# New ports collection makefile for:	mplayerthumbs
# Date created:		2009-09-07
# Whom:			David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mplayerthumbs
PORTVERSION=	1.2
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	dolphin-plugins-
DISTNAME=	41180-${PORTNAME}-${PORTVERSION}

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	Video thumbs previewer for dolphin

RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
