# New ports collection makefile for:	cutecom
# Date created:			Thu Jul 15 02:07:06 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cutecom
PORTVERSION=	0.20.0
CATEGORIES=	comms
MASTER_SITES=	http://cutecom.sourceforge.net/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Graphical serial terminal

RUN_DEPENDS=	lsz:${PORTSDIR}/comms/lrzsz

USE_QT_VER=	4
QT_COMPONENTS=	qt3support qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

MAN1=		cutecom.1

.include <bsd.port.mk>
